#include <iostream>
#include <functional>

void test(int i, double d)
{
	std::cout << "int " << i << std::endl;
	std::cout << "double " << d << std::endl;
}

int main()
{
	using namespace std::placeholders;
	auto b = std::bind(test, _2, _1);
	b(2.0, 1);
}
