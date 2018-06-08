#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <thread>
#include <memory>
#include <algorithm>
#include <exception>

#include "test_and_or.h"
#include "test.h"

enum TYPE
{
    e1,
    e2 = 1,
    e3 = 1,
    e4
};


int main()
{
    // test1
    bool re = (fa() || fb()) && fc();

    A a;
    a.print();

    return 0;
}