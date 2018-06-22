#include "shared_reset.h"
#include "template_print.h"
#include <string> 
#include <iostream>

int main()
{
    /*using namespace std;
    std::string str1("xxxx");
    std::string str2("");

    cout << sizeof(str1) << " " << sizeof(str2) << std::endl;
    cout << sizeof(std::string) << endl;*/

    auto t = "hello " + 2;

    int i = 0.999;

    enum Language
    {
        cpp,
        java,
        python
    };
    my_print((const char*)"hello " + std::to_string(python));
}