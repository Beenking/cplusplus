#include "../test_dll/print_fun.h"
#include <iostream>

int main()
{
    Test::print();
    std::cout << Test::i;

    MyPrint();
    return 0;
}
