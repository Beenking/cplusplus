#include <iostream>

class A
{
public:
	A()
	{
		std::cout << "A()" << std::endl;
	}

	~A()
	{
		std::cout << "~A()" << std::endl;
	}

	A(const A& r)
	{
		std::cout << "A(const A& r)" << std::endl;
	}

	A& operator= (const A& r)
	{
		std::cout << "operator=" << std::endl;
		return *this;
	}
};


A fun()
{
	A a;
	return a;
}

int main()
{
	A a;
	a = fun();
}