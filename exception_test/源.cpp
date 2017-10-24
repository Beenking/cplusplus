#include "nst_exception.h"
#include <iostream>
#include <string>

int main()
{
    int i;
    std::cin >> i;

    try
    {
        if (0 == i)
        {
            NST_THROW_EXCEPTION("invalid devided vlaue 0");
        }
        else
        {
            std::cout << 1 / i << std::endl;
        }
    }
    catch (const std::exception &e)
    {
        auto ew = e.what();
        std::cout << e.what() << std::endl;
    }

    return 0;
}

