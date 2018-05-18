#include "shared_reset.h"
#include "template_print.h"
#include <string> 
#include <iostream>
#include <thread>

using namespace CPP11;

int main()
{
    //test1
    /*using namespace std;
    std::string str1("xxxx");
    std::string str2("");
    cout << sizeof(str1) << " " << sizeof(str2) << std::endl;
    cout << sizeof(std::string) << endl;*/

    // test2
    /*auto t = "hello " + 2;
    int i = 0.999;
    enum Language
    {
        cpp,
        java,
        python
    };
    my_print((const char*)"hello " + std::to_string(python));*/

    // test3

    try
    { 
        std::thread thrd(thread_exception_inverse, 0);
        thrd.join();
    }
    catch(const std::exception& ex)
    {
        std::cout << ex.what() << std::endl;
    }
    catch (...)
    {
        std::cout << "unkowned exception" << std::endl;
    }

}