#include <iostream>
#include <mutex>
#include <vector>
#include <atomic>
#include <thread>
#include <ctime>

/*
class Counter
{
public:
	std::atomic_int count; //原子数据类型

public:
	Counter(int i = 0) :count(i) {}
	void incerase()
	{
		//mutex.lock();
		++count;
		//mutex.unlock();
	}

	void decrease()
	{
		//mutex.lock();
		--count;
		//mutex.unlock();
	}
};

int main()
{
	Counter counter;

	std::vector<std::thread> threads;
	for (int i = 0; i < 5; ++i)
	{
		threads.push_back(std::thread([&]() {
			for (int i = 0; i < 10000; ++i) {
				counter.incerase();
			}
		}));
	}

	for (auto& thread : threads)
	{
		thread.join();
	}

	std::cout << counter.count << std::endl;
	std::cout << "main thread exit" << std::endl;
}*/

long total = 0;
std::mutex mtx;
//std::atomic_long total = 0;

void click() 
{
	for (int i = 0; i < 1000000; ++i)
	{
		mtx.lock();
		total += 1;
		mtx.unlock();
	}
}

int main()
{
	std::clock_t start = std::clock();
	// create 100 threads
	std::vector<std::thread> threads;
	for (int i = 0; i < 100; ++i)
	{
		threads.push_back(std::thread(click));
	}
	for (auto& thread : threads)
	{
		thread.join();
	}
	std::clock_t finish = std::clock();
	std::cout << "result: " << total << std::endl;
	std::cout << "duration: " << finish - start << "ms" << std::endl;
	return 0;
}