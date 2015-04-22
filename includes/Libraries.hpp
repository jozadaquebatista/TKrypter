#ifdef _WIN32
    #include <windows.h>
#elif __linux__
    /*#include "../depends/gtk/gtk.h"*/
    #include <FL/Fl.H>
    #include <FL/Fl_Window.H>
#endif
/* STANDARD C LIBRARIES */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <iostream>
#include <stdint.h>
#include <string.h>

/* DEFINING SOME USEFUL FUNCTIONS */
#define exit(){ return 1; }
#define sucess(){ return 0; }
