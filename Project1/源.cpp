#include <iostream>

class A
{
public:
	A()
	{
		*p = 100;
	}

	int a = 0;
	double b = 1;
	int *p;
};

int main()
{
	const A a;
	std::cout << *(a.p) << std::endl;
	*(a.p) = 200;
	std::cout << *(a.p) << std::endl;

	return 0;
}