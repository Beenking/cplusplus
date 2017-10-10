#include <iostream>



void fun() noexcept
{
    std::cout << "xxxxxxxxxxx" << std::endl;
    throw 1;
}


void handler()
{
    std::cout << "unexception handler" << std::endl;
}

int main()
{
    set_unexpected(handler);
    try 
    {
        fun();
    }
    catch (const int i)
    {
        std::cout << i << std::endl;
    }
    
}