#include <thread>
#include <iostream>

void hello() 
{
	int i = 10000;
	while (i--)
	{
		std::cout << "hello from thread" << std::endl;
	}
}

int main()
{
	//std::thread t1(hello);
	std::thread t1([](int i) -> void 
	{
		while (i--)
		{
			std::cout << "hello from thread" << std::endl;
		}	
	}, 10);
	//t1.join();

	long int j = 10;
	while (j--)
	{
		std::cout << "main thread" << std::endl;
	}
	t1.join();
	return 0;
}