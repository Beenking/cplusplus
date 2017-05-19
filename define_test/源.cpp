#include <iostream>

#define Conn(x,y) x##y

int main()
{
	auto n = Conn(123, 456);
	std::cout << n * 10 << std::endl;
}