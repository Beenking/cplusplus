#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include "boost_timer_test.h"
#include <boost/lexical_cast.hpp>

enum Day
{
	Monday = 1,
	Tus = 2,
};

int enum_test()
{
    float f1 = 1.31391f;
    double d1 = 1.31391;
    std::string  s = std::to_string(d1);

    float f2 = 0.1f;
    double d2 = 0.1;

    std::cout << std::setprecision(100) << f2 << std::endl;
    std::cout << std::setprecision(100) << d2 << std::endl;
    
    std::string fss = boost::lexical_cast<std::string>(f2);
    std::string dss = boost::lexical_cast<std::string>(d2);
    std::cout << fss << std::endl;
    std::cout << dss << std::endl;

    std::string stdstr = std::to_string(f2);
    std::cout << stdstr << std::endl;

    char dest[10];
    sprintf_s(dest, "%.5f", 200.);
    std::cout << dest << std::endl;
    return 0;
}


class A {
public:
    int m_a;
};

int main()
{
    try
    {
        int i = 6;
        std::vector<int> vi{ 1,2,3,4,5 };
        vi.at(i) = 6;

        std::cout << "hello " << vi[i] << std::endl;
    }
    catch (std::exception &ex)
    {
        std::cout << ex.what() << std::endl;
    }
    catch (...)
    {
        std::cout << "... exception" << std::endl;
    }

    return 0;
}
