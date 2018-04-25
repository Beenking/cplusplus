#include "move_test.h"
#include"right_value_reference_test.h"
#include <iostream>
#include <vector>
#include <ctime>

typedef unsigned char uchar;

using namespace std;

class Image
{
public:
    Image()
    {
        //cout << "1--Image()..." << endl;
        m_size = 10 * 1024 * 1024; //10M
        m_pdata = new uchar[m_size];
        memset(m_pdata, 0, m_size);
    }

    Image(const Image& img)
    {
       // cout << "2--Image(const Image&)..." << endl;
        m_size = img.m_size;
        m_pdata = new uchar[m_size];
        memcpy(m_pdata, img.m_pdata, m_size);
    }

    Image& operator= (const Image& img)
    {
       // cout << "operator=(const Image&) " << endl;
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
        //cout << "3--~Image()" << endl;
        if (m_pdata)
        {
            delete[] m_pdata;
        }
    }

    //Image(Image&& img)
    //{
    //    //cout << "2--Image(const Image&&)" << endl;
    //    delete[] m_pdata;
    //    m_pdata = img.m_pdata;
    //    img.m_pdata = nullptr;
    //    img.m_size = 0;
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

    clock_t start, end;
    start = clock();
    for (int i = 0; i < 100; i++)
    {
        vecImage.push_back(Image());
    }
    end = clock();
    cout << " Time lost: " << double(end - start)/ CLOCKS_PER_SEC << endl;

    return 0;
}