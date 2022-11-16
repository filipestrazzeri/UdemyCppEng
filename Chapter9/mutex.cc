#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>

std::mutex g_mutex;

void thread_func()
{
    using namespace std::chrono_literals;
    {
        std::lock_guard<std::mutex> lock(g_mutex);
        std::cout << "running thread " << std::this_thread::get_id() << '\n';
    }
    std::this_thread::yield();
    std::this_thread::sleep_for(2s);
    {
        std::lock_guard<std::mutex> lock(g_mutex);
        std::cout << "done in thread " << std::this_thread::get_id() << '\n';
    }
}

int main()
{

    return 0;
}
