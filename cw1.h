
/* 
This header file declares the functions that you can call from your
compiler or interpreter.
*/

/*
Call this function once to display the canvas window before making calls to
putPixel().  

Calling the function more than once per execution will cause a runtime error.
*/
extern void createCanvas();

/*
Call this function to draw a single pixel of the specified colour in the
specified location.

The x coordinate must be in the range 0-639 inclusive (i.e. the canvas is 640
    pixels wide).
The y coordinate must be in the range 0-479 inclusive (i.e. the canvas is 480
    pixels high).
All colour components must be in the range 0 - 0xFF inclusive (i.e. 0-255)

The function createCanvas() must be called before this function can be called.

Violating any of these constraints will cause a runtime error.
*/

extern void putPixel(int x, int y, int r, int g, int b);

/*
Call this function last.  It will hold the canvas window open for inspection
until the user closes it by clicking on the close button.  Then it will dispose
of the window and deinitialise the graphics library.

If you do not call this method last, you probably won't get much of a look at
your output.
*/
extern void waitToQuit();