#ifndef JPEG_CONTAINER_H
#define JPEG_CONTAINER_H

extern "C"{
    #include "jpeg_interface.h"
}

class Jpeg_container
{
public:
    Jpeg_container();
    void jpeg_load_from_file(char *filename);

private:
    unsigned char *pixel_array;
    int height, width, size;
};

#endif // JPEG_CONTAINER_H
