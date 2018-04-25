#include "move_test.h"
#include"right_value_reference_test.h"

#include <iostream>


using namespace std;

class Image
{
public:
    Image()
    {
        cout << "Image()..." << endl;
    }

    Image(const Image&)
    {
        cout << "Image(const File&)..." << endl;
    }

    Image(const Image&&)
    {
        cout << "Image(const Image&&)" << endl;
    }

    Image& operator= (const Image&)
    {
        cout << "operator=(const Image&) " << endl;
    }

    ~Image()
    {
        cout << "~Image()" << endl;
    }

private:
    unsigned char* data = nullptr;
};


Image readImage(/*path*/)
{
    Image image;
    // fill file data
    return std::move(image);
}



int main()
{
    //Image image = readImage();
    //Image i2 = std::move(image);
    right_value_reference_test();

    return 0;
}