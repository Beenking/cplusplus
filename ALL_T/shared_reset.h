#pragma once
#include <memory>
#include <thread>

namespace CPP11
{
	int test_reset()
	{
		std::shared_ptr<int> spi(new int(5));
		std::shared_ptr<int> spi2(new int(6));
		spi2 = spi;

		spi.reset(new int(7));

		int *p = new int(8);
		{
			std::shared_ptr<int> spi3(p);
		}
		

		return 0;
	}


    double thread_exception_inverse(int i)
    {
        if (0 != i)
        {
            return 1 / i;
        }
        else
        {
            throw std::exception("divide zero excepiton");
        }
    }

}
