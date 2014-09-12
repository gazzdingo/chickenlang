717301 Programming languages Coursework 1 API
=============================================

James Skene, 2013


The function prototypes for the drawing api are provided here in cw1.h. You should have
a look at that file to see how they are to be used.


Also included is test.c that can be used to demonstrate that the code works on your
platform as follows:

1. Compile test.c

gcc -c -o test.o test.c

2. Link with the API as follows

gcc -o test.exe test.o cw1.o -L. -lSDL

3. Run test.exe - you should see a window called 'Canvas' with a yellow dot on it.


That's it!  Let me know if you have trouble getting this to work on your platform.


This code links dynamically to the SDL library version 1.2.15, distributed under 
the terms of the LGPL.  It also includes libSDL.dll.a in unmodified form.  See
www.libsdl.org for further details on the terms of this license.