#include "jpeg_container.h"

Jpeg_container::Jpeg_container()
{

}

void Jpeg_container::jpeg_load_from_file(char *filename)
{
    ImageData image;
    image = read_JPEG_file("test.jpg");

    width = image.width;
    height = image.height;
    pixel_array = image.pixels;
    size = width * height * 3;

    int i = 0;
    for(i; i < size; i++)
    {
        int n = pixel_array[i];
        printf("%d\n", n);
    }
}

