#ifndef JPEG_INTERFACE_H
#define JPEG_INTERFACE_H

#include <stdio.h>
#include "jpeglib.h"
#include "setjmp.h"

struct my_error_mgr {
  struct jpeg_error_mgr pub;	/* "public" fields */

  jmp_buf setjmp_buffer;	/* for return to caller */
};

typedef struct my_error_mgr * my_error_ptr;

struct ImageData {
       unsigned char *pixels;
       long  width;
       long height;
   };

struct ImageData read_JPEG_file(char * filename);
int write_JPEG_file(char* filename,  struct ImageData image);



#endif // JPEG_INTERFACE_H
