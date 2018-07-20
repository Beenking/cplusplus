#include "print_fun.h"
#include <iostream>
#include <fstream>

void Test::print()
{
    std::cout << "Hello,World! OK ";
}

int Test::i = 5;

void MyPrint(int i)
{
    std::cout << "My Print " << i <<  std::endl;
}

void MyPrint2()
{
    std::ofstream ouput("output.xml");
    ouput << "Hello World" << std::endl;
}