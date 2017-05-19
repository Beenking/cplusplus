#include <iostream>

class A
{
public:
	int a = 0;
	double b = 1;
	int *p = &a;

	void setp(int& i)const
	{
		*p = i;
	}
};

int main()
{
	const A ca;
	std::cout << ca.a << " " << ca.b << std::endl;

	*(ca.p) = 100;
	std::cout << *(ca.p) << std::endl;
	*(ca.p) = 200;
	std::cout << *(ca.p) << std::endl;
	
	int m = 300;
	ca.setp(m);
	std::cout << *(ca.p) << std::endl;

	A cb = ca;

	return 0;
}