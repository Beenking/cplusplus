#include <thread>
#include <iostream>
#include <vector>
#include <mutex>

int main() 
{
	std::mutex mtx;
	std::vector<std::thread> threads;
	std::vector<int, std::allocator<int>> vi;
	for (int i = 0; i < 5; ++i)
	{
		threads.push_back(std::thread([&]()  //����Դ�ֵ����ʽ�����ⲿ������lambda �岻�����޸��ⲿ����
		{	
			mtx.lock();
			std::cout << "hello from lambda thread " << std::this_thread::get_id() << std::endl;
			mtx.unlock();
		}));
		
	}

	for (/*const*/auto &thd : threads)
	{
		thd.join(); //  const���εĶ��󣬸ö�����κη�const��Ա���������ܱ�����
	}

	std::cout << "hello from main thread " << std::this_thread::get_id() << std::endl;
}