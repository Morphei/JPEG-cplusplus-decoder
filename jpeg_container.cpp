#include "jpeg_container.h"

Jpeg_container::Jpeg_container()
{

}

int Jpeg_container::jpeg_save_to_file(char *filename)
{
    ImageData image;
    image.height = height;
    image.width = width;
    unsigned char * arr[3];
//    image.pixels[0] = (unsigned char)'255';
//    image.pixels[1] = (unsigned char)'255';
//    image.pixels[2] = (unsigned char)'255';
        image.pixels = pixel_array;
    return write_JPEG_file(filename, image);
}

void Jpeg_container::jpeg_load_from_file(char *filename)
{
    ImageData image;
    image = read_JPEG_file(filename);

    width = image.width;
    height = image.height;
    pixel_array = image.pixels;
    size = width * height * 3;

//    int i = 0;
//    for(i; i < size; i++)
//    {
//        int n = pixel_array[i];
//        printf("%d\n", n);
//    }
}

unsigned char *Jpeg_container::get_pixels()
{
    return pixel_array;
}

int Jpeg_container::get_width()
{
    return width;
}

int Jpeg_container::get_height()
{
    return height;
}

