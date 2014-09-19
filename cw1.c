
#include "SDL.h"
#include "cw1.h"

SDL_Surface *surface = 0;

/*
Initialise SDL and create window.
*/
void createCanvas() {

	if(surface != 0) {

		fprintf(stderr, "Canvas can only be created once per execution");
		exit(1);
	}

	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		fprintf(stderr, "Unable to init SDL: %s\n", SDL_GetError());
		exit(1);
	}

	surface = SDL_SetVideoMode(640, 480, 32, SDL_SWSURFACE);
	if(surface == NULL) {

		fprintf(stderr, "Could not initialise 640x480x32 window: %s", SDL_GetError());
	}
	SDL_WM_SetCaption("Canvas", NULL);
}


/*
Set the pixel at (x, y) to the given value
NOTE: createCanvas() must have been called first
*/
void putPixel(int x, int y, int r, int g, int b)
{
	/* Check preconditions */
	if(x < 0 || x >= 640) {

	    fprintf(stderr, "putpixel: X coordinate out of range 0 - 639: %d\n", x);
		exit(1);
	}

	if(y < 0 || x >= 480) {

	    fprintf(stderr, "putpixel: X coordinate out of range 0 - 479: %d\n", x);
		exit(1);
	}

	if(r < 0 || r > 0xFF) {

	    fprintf(stderr, "putpixel: r component out of range 0 - 0xff: %d\n", r);
		exit(1);
	}

	if(g < 0 || g > 0xFF) {

	    fprintf(stderr, "putpixel: g component out of range 0 - 0xff: %d\n", g);
		exit(1);
	}

	if(b < 0 || b > 0xFF) {

	    fprintf(stderr, "putpixel: b component out of range 0 - 0xff: %d\n", b);
		exit(1);
	}

	if(surface == 0) {

	    fprintf(stderr, "putpixel: canvas not created yet\n", b);
		exit(1);

	}

    /* Lock the surface for direct access to the pixels */
    if ( SDL_MUSTLOCK(surface) ) {

        if ( SDL_LockSurface(surface) < 0 ) {

            fprintf(stderr, "Can't lock surface: %s\n", SDL_GetError());
            exit(1);
        }
    }

	/* Create the pixel */
	Uint32 pixel;
    pixel = SDL_MapRGB(surface->format, r, g, b);

	/* Write the pixel */
    int bpp = surface->format->BytesPerPixel;
    /* Here p is the address to the pixel we want to set */
    Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;

    switch(bpp) {
    case 1:
        *p = pixel;
        break;

    case 2:
        *(Uint16 *)p = pixel;
        break;

    case 3:
        if(SDL_BYTEORDER == SDL_BIG_ENDIAN) {
            p[0] = (pixel >> 16) & 0xff;
            p[1] = (pixel >> 8) & 0xff;
            p[2] = pixel & 0xff;
        } else {
            p[0] = pixel & 0xff;
            p[1] = (pixel >> 8) & 0xff;
            p[2] = (pixel >> 16) & 0xff;
        }
        break;

    case 4:
        *(Uint32 *)p = pixel;
        break;
    }

	/* Update just the part of the display that we've changed */
    SDL_UpdateRect(surface, x, y, 1, 1);

	/* Unlock the surface if necessary */
	if ( SDL_MUSTLOCK(surface) ) {
        SDL_UnlockSurface(surface);
    }
}

/*
Call this to wait until the user closes the output window.
*/
void waitToQuit() {

	SDL_Event event;
	while(1) {

		if(SDL_PollEvent(&event)) {

			switch(event.type) {

			case SDL_QUIT:
				SDL_Quit();
				return;
			}
		}
	}

	fprintf(stderr, "Quitting unexpectedly.\n");
	exit(1);
}
