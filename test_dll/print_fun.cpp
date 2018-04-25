#include "print_fun.h"
#include <iostream>

void Test::print()
{
    std::cout << "Hello,World! OK ";
}

int Test::i = 5;

void MyPrint(int i)
{
    std::cout << "My Print " << i <<  std::endl;
}