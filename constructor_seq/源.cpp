#include <iostream>

class A 
{
public:
    A(int i):m_i(i)
    {
        std::cout << "A Constructor\n";
    }

private:
    int m_i;
};


// 基类构造函数 --> 子类初始化列表 --> 子类成员初始化 --> 子类构造函数体
class B 
{
public:
    B(int i):m_a1(i)
    {
        std::cout << "B Constructor\n";
    }

private: 
    A m_a2 = 1;
    A m_a1;
    int m_i;
};

int main()
{
    B b(2);
}