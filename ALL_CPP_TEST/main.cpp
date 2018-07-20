#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <memory>

#include "check_memory_leaks.h"
#include "class_A.h"


class TEST
{
public:
    float f;
};


class CON
{
public:
    TEST t;
};

int main()
{
    float f = 2.1;
    f++;
    f++;

    return 0;
}