#include <iostream>
#include <vector>

class Base
{
public:
	Base()
	{
		std::cout << "default Constructor" << std::endl;
	}

	Base(const Base& b)
	{
		std::cout << "Copy  Constructor" << std::endl;
	}

	Base(const Base&& b)
	{
		std::cout << "Copy right Constructor" << std::endl;
	}
};



int main()
{
	Base b1(Base());

	return 0;
}