#include <iostream>
#include <mutex>
#include <vector>
#include <thread>

class Counter
{
public:
	std::mutex mutex;
	int count;

public:
	Counter(int i = 0):count(i){}
	void incerase()
	{
		//mutex.lock();
		++count;
		//mutex.unlock();
	}

	void decrease()
	{
		mutex.lock();
		--count;
		mutex.unlock();
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
}