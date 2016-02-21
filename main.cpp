#include <iostream>
#include <jpeg_container.h>
using namespace std;

int main()
{
    Jpeg_container image;
    image.jpeg_load_from_file("test.jpg");
    return 0;
}

