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
        cout << "1--Image()..." << endl;
        m_size = 10 * 1024 * 1024; //10M
        m_pdata = new uchar[m_size];
        memset(m_pdata, 0, m_size);
    }

    Image(const Image& img)
    {
        cout << "2--Image(const Image&)..." << endl;
        m_size = img.m_size;
        m_pdata = new uchar[m_size];
        memcpy(m_pdata, img.m_pdata, m_size);
    }

    Image& operator= (const Image& img)
    {
        cout << "operator=(const Image&) " << endl;
        if (this != &img)
        {
            delete[] m_pdata;
            m_pdata = nullptr;

            m_size = img.m_size;
            m_pdata = new uchar[m_size];
            memcpy(m_pdata, img.m_pdata, m_size);
        }
        return *this;
    }

    ~Image()
    {
        cout << "3--~Image()" << endl;
        if (m_pdata)
        {
            delete[] m_pdata;
        }
    }

    //Image(const Image&&)
    //{
    //    cout << "Image(const Image&&)" << endl;
    //}

    //Image& operator=(Image&&)
    //{
    //    cout << "operator=(Image&&)" << endl;
    //}

private:

    uchar* m_pdata = nullptr;
    size_t m_size = 0;
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

    std::vector<Image> vecImage;
    for (int i = 0; i < 5; i++)
    {
        vecImage.push_back(Image());
    }


    return 0;
}