#include <thread>
#include <iostream>
using namespace std;

class interrupt_exception
{
};

class MyThreadInterrupt
{
public:
	static void interrupt()
	{
		interrupt_enable = true;
	}

	static void interrupt_point()
	{
		if (interrupt_enable)
		{
			throw interrupt_exception();
		}
	}

private:
	static bool interrupt_enable;
};
bool MyThreadInterrupt::interrupt_enable = false;


void test()
{
	std::cout << "Child Thread" << std::endl;
	int i = 0;
	try 
	{
		for (; i < 100000; ++i)
		{
			MyThreadInterrupt::interrupt_point();
			//std::cout << i << std::endl;
		}
	}
	catch (interrupt_exception)
	{
		std::cout << "interrupt time i = " << i << std::endl;
	}
}

int main()
{
	std::thread t1(test);
	std::cout << "Main Thread" << std::endl;
	int i = 1000;
	while (i--)
	{
		;
	}

	MyThreadInterrupt::interrupt();
	t1.join();

	return 0;
}