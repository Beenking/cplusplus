#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;
 int count = 0;

void attemp_10K_increased()
{
	for (int i = 0; i < 10000; i++) 
	{
		//if (mtx.try_lock())
		{
			mtx.lock();
			count++;
			mtx.unlock();
		}
	}
}

int main()
{
	std::thread threads[10];
	for (int i = 0; i < 10; i++)
	{
		threads[i] = std::thread(attemp_10K_increased);
	}

	for (auto & t : threads)
	{
		t.join();
	}

	std::cout << count << std::endl;
}