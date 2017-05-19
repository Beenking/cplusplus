#include <iostream>

class Base
{
private:
	int m_i = 0;

public:
	int& get_i()
	{
		return m_i;
	}
};


int main()
{
	Base b;
	b.get_i() = 3;
}