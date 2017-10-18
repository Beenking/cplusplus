#include <iostream>
#include <string>
#include <iomanip>
#include <boost/lexical_cast.hpp>

enum Day
{
	Monday = 1,
	Tus = 2,
};

int main()
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