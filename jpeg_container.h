#ifndef JPEG_CONTAINER_H
#define JPEG_CONTAINER_H

extern "C"{
    #include "jpeg_interface.h"
}

class Jpeg_container
{
public:
    Jpeg_container();

    int jpeg_save_to_file(char *filename);
    void jpeg_load_from_file(char *filename);

    unsigned char* get_pixels();
    int get_width();
    int get_height();

private:
    unsigned char *pixel_array;
    int height, width, size;
};

#endif // JPEG_CONTAINER_H
