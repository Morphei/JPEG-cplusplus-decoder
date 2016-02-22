#include <iostream>
#include <jpeg_container.h>
using namespace std;

int main()
{
    Jpeg_container image;
    image.jpeg_load_from_file("est.jpg");
    int result = image.jpeg_save_to_file("est_out.jpg");
    cout << "\n" << result;
    return 0;
}

