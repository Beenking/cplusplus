#include "move_test.h"
#include"right_value_reference_test.h"
#include <iostream>

typedef unsigned char uchar;

using namespace std;

class Image
{
public:
    Image()
    {
        cout << "Image()..." << endl;

        auto defaltSize = 1024;
        pdata = new uchar(defaltSize);
        memset(pdata, uchar(0), defaltSize);
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
        if (pdata)
        {
            delete pdata;
        }
    }

private:
    uchar* pdata = nullptr;
};


Image readImage(/*path*/)
{
    Image image;
    // fill file data
    return image;
}



int main()
{
    // right_value_reference_test();

    Image image = readImage();


    return 0;
}