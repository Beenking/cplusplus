#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <Windows.h>


// sleep join wait 都是线程阻塞函数

void hello()
{
	std::cout << "hello from thread " << std::endl;
}
int main()
{
	std::thread t1(hello);
	t1.join(); // 该线程执行完才返回，即阻塞主线程

	std::cout << "MAIN thread" << std::endl;

	return 0;
}