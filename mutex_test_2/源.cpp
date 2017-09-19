#include <iostream>
#include <mutex>

using namespace std;

std::mutex g_mtx;

void print(int i)
{
	std::unique_lock<std::mutex> lck(g_mtx);
	i = i + 1 - 1;
	std::cout << i << std::endl;

	i = i + i;
	for (int n = 0; n < 1000000; ++n)
	{
		i = i * n;
	}
}

int main()
{
	std::thread threads[10];
	// spawn 10 threads:
	for (int i = 0; i<10; ++i)
		threads[i] = std::thread(print, i);

	for (auto& th : threads) th.join();

	return 0;
}