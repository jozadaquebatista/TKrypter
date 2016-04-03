#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#pragma once

/* Headers that will be used */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <time.h>

#ifdef _WIN32
    #include <windows.h>
#endif
#ifdef _POSIX
    #include <gtk-3.0/gtk/gtk.h>
#endif
#ifdef _linux 
    #include <gtk-3.0/gtk/gtk.h>
#endif

/* Custom Types */
#define result(s) printf("\nExecution code: %d [success!]\n", s)

#define exec_result(s) \
{ if(s==0) \
    result(s); \
else puts("<EXEC ERROR!>");}
#define _(s) # s
#define nullptr (void*)NULL
#define new_string(s) calloc(s, sizeof(void*))

#define Uint8  uint8_t
#define Uint16 uint16_t
#ifdef  Uint32
#undef  Uint32
#define Uint32 uint32_t
#endif
#define String    const char*
// #define puts(s) # s

/* Functions and types to be used */
static _Bool verifyStr ( const unsigned char*, ... );

static _Bool krypto_encrypt   ( unsigned const char* ,
                                Integer8             ,
                                Integer8             ,
                                ...);
                                               
static _Bool krypto_decrypt   ( unsigned const char* , 
                                Integer8             ,
                                Integer8             ,
                                ...);
                                           
static void signature  ( unsigned char     [], 
                         unsigned const char*, 
                         Integer8            , 
                         int                 ,
                         ...);
                         
/*static _Bool tk_fEncrypt( FILE   *p, 
                            String file_name);*/

//static FILE *file_p=nullptr;

static Integer8 verifyArgs( int    , 
                            char [],
                            ... );
struct flag;

#endif
