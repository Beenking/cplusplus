#include <iostream>

class A 
{
public:
    A()
    {
        std::cout << "A Constructor\n";
    }
};


// ���๹�캯�� --> �����ʼ���б� --> �����Ա��ʼ�� --> ���๹�캯����
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