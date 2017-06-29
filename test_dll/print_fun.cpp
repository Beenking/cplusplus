#include "print_fun.h"
#include <iostream>

void Test::print()
{
    std::cout << "Hello,World! OK ";
}

int Test::i = 5;

void MyPrint()
{
    std::cout << "My Print" << std::endl;
}