#include <iostream>
#include <functional>

class LogDecorator
{
public:
    LogDecorator(std::function<void()> f)
    {
        std::cout << "enter " << f.target_type().name() << std::endl;
        f();
        std::cout << "leave " << __FUNCTION__ << std::endl;
    }

    void operator()(std::function<void()> f)
    {
        auto name = typeid(f).name();
        std::cout << "enter " << __FUNCTION__ << std::endl;
        f();
        std::cout << "leave " << name << std::endl;
    }
};


void fun()
{
    std::cout << __FUNCTION__ << "excute fun" << std::endl;
}

int main()
{
    LogDecorator log(fun);

    return 0;
}