#include <iostream>
#include <string>

namespace NS1
{
    class A {
    public:
        A(int i) 
        {
            std::cout << "NS1::A " << i << std::endl;
        }
    };
    static A a1(1);
}

namespace NS2
{
    class B
    {
    public:
        B(int i)
        {
            std::cout << "NS2::B " << i << std::endl;
        }
    };
    static B b1(1);
}


static NS1::A a2(2);
static NS2::B b2(2);

#define TO_STRING(name) #name

int main()
{
    //static NS1::A a3(3);
    //static NS2::B b3(3);

    double a = 35.9;
    double b = 0.1;
    int c = a / b;
    double m = std::fmod(a, b);
    std::cout << c << " " << a/b << " " << std::fmod(a, b) << std::endl;

    std::string s = TO_STRING(helloworld);
    std::cout << s << std::endl;

    return 0;
}