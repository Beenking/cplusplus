#include <functional>
#include <iostream>

bool Excute(std::string s, int len)
{
    if (s.length() == len)
    {
        return true;
    }
    return false;
}


bool Wrapper(std::string s, int len)
{
    std::cout << "Enter" << std::endl;
    bool re = Excute(s, len);
    std::cout << "Leave" << std::endl;

    return re;
}


std::function<bool(std::string, int)> LoggerExcute(std::function<bool(std::string, int)> Excute)
{
    return Wrapper;
}


class A
{

};

int main()
{

    std::function<bool(std::string, int)> Excute2 = LoggerExcute(Excute);
    Excute2("22", 2);

  
    return 0;
}