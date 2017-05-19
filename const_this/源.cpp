#include <iostream>
using namespace std;

class A
{	
public:
	A():p(new int(1)){}
	~A()
	{
		delete p;
	}

	void print()const
	{
		*p = 2;
		cout << *p << endl;
	}
private:
	int *p;
};

int main()
{
	A a;
	a.print();

	return 0;
}