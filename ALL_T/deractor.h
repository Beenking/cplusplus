#pragma once

#include <functional>
#include <cmath>
#include <iostream>

int my_abs(int i)
{
    if (i < 0)
        return -i;
    return i;
}

int new_abs(int i)
{
    std::cout << "enter new_abs" << std::endl;
    if (i < 0)
        return -i;
    return i;
}

std::function<int(int)> old_abs = my_abs;
my_abs = new_abs;
