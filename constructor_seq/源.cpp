#include <iostream>

class A 
{
public:
    A()
    {
        std::cout << "A Constructor\n";
    }
};


// 基类构造函数 --> 子类初始化列表 --> 子类成员初始化 --> 子类构造函数体
class B : public A
{
public:
    B()
    {
        std::cout << "B Constructor\n";
    }

private:
    A m_b;
    int m_i;
};

int main()
{
    B b;
}