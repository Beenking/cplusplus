#include <iostream>

#define Conn(x,y) x##y

void seti(int& i);
int main()
{
	auto n = Conn("123", "456");
	std::cout << n  << std::endl;
	std::cout << "123""456" << std::endl;

	int i = 99;
	seti(i);
	std::cout << i << std::endl;
}


void seti(int& i)
{
	i = i / 2;
}