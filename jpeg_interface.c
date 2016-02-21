#include "jpeg_interface.h"
METHODDEF(void)

my_error_exit (j_common_ptr cinfo)
{
  my_error_ptr myerr = (my_error_ptr) cinfo->err;
  (*cinfo->err->output_message) (cinfo);
  longjmp(myerr->setjmp_buffer, 1);
}

struct ImageData read_JPEG_file (char * filename)
{
    struct ImageData imageData;
    struct jpeg_decompress_struct cinfo;
    struct my_error_mgr jerr;

    FILE * infile;      /* source file */
    JSAMPARRAY buffer;      /* Output row buffer */
    int row_stride;     /* physical row width in output buffer */

    if ((infile = fopen(filename, "rb")) == NULL) {
        fprintf(stderr, "can't open %s\n", filename);
        return imageData;
    }

    cinfo.err = jpeg_std_error(&jerr.pub);
    jerr.pub.error_exit = my_error_exit;

    if (setjmp(jerr.setjmp_buffer)) {

        jpeg_destroy_decompress(&cinfo);
        fclose(infile);
        return imageData;
    }

    jpeg_create_decompress(&cinfo);

    jpeg_stdio_src(&cinfo, infile);

    (void) jpeg_read_header(&cinfo, TRUE);

    (void) jpeg_start_decompress(&cinfo);

    int buffer_height = 1;
    buffer = (JSAMPARRAY)malloc(sizeof(JSAMPROW) * buffer_height);
    buffer[0] = (JSAMPROW)malloc(sizeof(JSAMPLE) * row_stride);

    row_stride = cinfo.output_width * cinfo.output_components;

    imageData.width = cinfo.output_width;
    imageData.height = cinfo.output_height;

    int pixel_size = cinfo.output_width * cinfo.output_height * cinfo.output_components;
    imageData.pixels = (unsigned char *)malloc (pixel_size);

    long counter = 0;

    while (cinfo.output_scanline < cinfo.output_height) {
      jpeg_read_scanlines(&cinfo, buffer, 1);
      memcpy(imageData.pixels+counter, buffer[0], row_stride);
      counter += row_stride;
    }

    (void) jpeg_finish_decompress(&cinfo);

    jpeg_destroy_decompress(&cinfo);

    fclose(infile);
    return imageData;
}
