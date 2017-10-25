#include <thread>
#include <iostream>
#include <condition_variable>
#include <mutex>
#include <queue>

std::mutex mu;
std::condition_variable cv;
std::queue<int> que;

void producer(int min, int max)
{
    for (int i = min; i <= max; ++i)
    {
        std::unique_lock<std::mutex> locker(mu);
        que.push(i);
        cv.notify_one();

        locker.unlock();
        std::cout << "thread ID: " << std::this_thread::get_id() << " prodece number: " << i << std::endl;
    }
}


void consumer()
{
    while (true)
    {
        std::unique_lock<std::mutex> locker(mu);
        if (que.empty())
        {
            cv.wait(locker);
        }
        int i = que.front();
        que.pop();

        locker.unlock();
        std::cout << "thread ID: " << std::this_thread::get_id() <<  " consum number: " << i << std::endl;
    }
}




int main()
{
    std::thread thread_producer1(producer, 1, 10);
    //std::thread thread_comsumer1(consumer);
    std::thread thread_producer2(producer, 11, 20);
    std::thread thread_comsumer2(consumer);

    thread_producer1.join();
    //thread_comsumer1.join();
    thread_producer2.join();
    thread_comsumer2.join();

    return 0;
}