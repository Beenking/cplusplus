#include <thread>
#include <fstream>
#include <iostream>
#include <string>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <stack>

//class MutexLog
//{
//public:
//	MutexLog()
//	{
//		out.open("mutex_logger.txt");
//	}
//	void shared_print(const std::string& s, int value)
//	{
//		std::unique_lock<std::mutex> locker(m_mutex);
//		out << s << " " << value << std::endl;
//		//std::cout << s << " " << value << std::endl;
//	}
//
//private:
//	std::mutex m_mutex;
//	std::ofstream out;
//};
//
//void thread_porcess_fun(MutexLog &logger)
//{
//	for (int i = 0; i < 100; ++i)
//	{
//		logger.shared_print("thread t1", i);
//	}
//}
//
//int main()
//{
//	MutexLog logger;
//	std::thread t1(thread_porcess_fun, std::ref(logger));
//
//	for (int i = 0; i < 100; ++i)
//	{
//		logger.shared_print("thread main", i);
//	}
//
//	t1.join();
//	return 0;
//}

std::deque<int> g_stk;
std::mutex mtx;
std::condition_variable cv;

void fun_push1()
{
	int n = 20;
	while (n--)
	{
		std::unique_lock<std::mutex> locker(mtx);
		g_stk.push_back(n);
		locker.unlock();

		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
}

void fun_push2()
{
	int n = 20;
	while (n--)
	{
		std::unique_lock<std::mutex> locker(mtx);
		g_stk.push_back(n);
		locker.unlock();

		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}
}



void fun_pop1()
{
	int data = -1;
	while (data != 2)
	{
		std::unique_lock<std::mutex> locker(mtx);
		if (!g_stk.empty())
		{
			data = g_stk.back();
			g_stk.pop_front();
			std::cout << "t2 got a value from t1: " << data << std::endl;
			locker.unlock();
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
}


void fun_pop2()
{
	int data = -1;
	while (data != 0)
	{
		std::unique_lock<std::mutex> locker(mtx);
		if (!g_stk.empty())
		{
			data = g_stk.back();
			g_stk.pop_front();
			std::cout << "t3 got a value from t1: " << data << std::endl;
			locker.unlock();

		}
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
}


int main()
{
	std::thread t0(fun_push1);
	std::thread t1(fun_push2);
	std::thread t2(fun_pop1);
	std::thread t3(fun_pop2);

	t0.join();
	t1.join();
	t2.join();
	t3.join();

	std::cout << g_stk.size() << std::endl;
	return 0;
}