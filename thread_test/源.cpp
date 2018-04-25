#include <thread>
#include <iostream>
#include <chrono>

void thread_task(int n)
{
	std::this_thread::sleep_for(std::chrono::seconds(n));
	int i = 1;

	std::cout << "hello thread " << std::this_thread::get_id() << " paused " << n << " seconds" << std::endl;
}

int main()
{
	std::thread threads[4];
	std::cout << "Spawing 5 threads...\n";

	for (int i = 0; i < 4; i++)
	{
		threads[i] = std::thread(thread_task, i + 1);
	}

	for (auto &t : threads)
	{
		t.join();
	}
	std::cout << "ALl thread joined.\n";
}