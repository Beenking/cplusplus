#include <mutex>
#include <thread>
#include <iostream>
#include <queue>

namespace CPP11
{
	std::mutex mtx;
	std::condition_variable cv;
	std::queue<int> que;


	void calculate(int data)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(data * 1000));
		std::cout << std::this_thread::get_id() << " : " << data << std::endl;
	}

	void customer()
	{
		while (true)
		{
			std::unique_lock<std::mutex> locker(mtx);
			while (que.empty())
			{
				cv.wait(locker);
			}
			int data = que.front();
			que.pop();
			locker.unlock();

			calculate(data);
		}
	}

	void producer()
	{
		//std::unique_lock<std::mutex> locker(mtx);
		int input;
		while (std::cin >> input)
		{
			std::unique_lock<std::mutex> locker(mtx);

			que.push(input);
			cv.notify_one();
		}
	}


	void test_producer_customer()
	{
		std::thread customer_threads[10];
		for (int i = 0; i < 10; ++i)
		{
			customer_threads[i] = std::thread(customer);
		}

		std::thread producer_thread(producer);

		producer_thread.join();
		for (auto &t : customer_threads) t.join();

		std::cout << "test end" << std::endl;
	}


}
