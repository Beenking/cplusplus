#include <thread>
#include <iostream>
#include <vector>
#include <mutex>

int main() 
{
	std::mutex mtx;
	std::vector<std::thread> threads;
	for (int i = 0; i < 5; ++i)
	{
		threads.push_back(std::thread([&]()  //如果以传值的形式捕获外部变量，lambda 体不允许修改外部变量
		{	
			mtx.lock();
			std::cout << "hello from lambda thread " << std::this_thread::get_id() << std::endl;
			mtx.unlock();
		}));
		
	}

	for (/*const*/auto &thd : threads)
	{
		thd.join(); //  const修饰的对象，该对象的任何非const成员函数都不能被调用
	}

	std::cout << "hello from main thread " << std::this_thread::get_id() << std::endl;
}