#pragma once
#include <iostream>
#include <thread>

void print()
{
    int sum = 0;
    while (true)
    {
        std::cout << "Hello, world! " << sum << std::endl;
        sum += 1;
    }
    
}

