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

    Image& operator= (const Image&)
    {
        cout << "operator=(const Image&) " << endl;
    }

    ~Image()
    {
        cout << "~Image()" << endl;
    }

private:
    unsigned char* data;
};


Image readImage()
{
    Image image;
    // fill file
    return image;
}

int main()
{
    Image file = readImage();

    return 0;
}