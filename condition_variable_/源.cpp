#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <Windows.h>


// sleep join wait �����߳���������

void hello()
{
	std::cout << "hello from thread " << std::endl;
}
int main()
{
	std::thread t1(hello);
	t1.join(); // ���߳�ִ����ŷ��أ����������߳�

	std::cout << "MAIN thread" << std::endl;

	return 0;
}