#include <iostream>

class TestIn
{
public:
	TestIn(){}
	void print()const
	{
		std::cout << "hello test" << std::endl;
	}

	//TestIn(const TestIn&) = delete;
};

int main()
{
	//[](int i)->void
	//{
	//	std::cout << "lambda " << i << std::endl;
	//}(2);

	//auto f = [](int i)->void
	//{
	//std::cout << "lambda " << i << std::endl;
	//};
	//f(2);
	//return 0;

	TestIn in;
	[=]() {
		in.print();
	}();
}