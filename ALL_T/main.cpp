#include "shared_reset.h"
#include <string> 
#include <iostream>

int main()
{
    using namespace std;
    std::string str1("xxxx");
    std::string str2("");

    cout << sizeof(str1) << " " << sizeof(str2) << std::endl;
    cout << sizeof(std::string) << endl;
}