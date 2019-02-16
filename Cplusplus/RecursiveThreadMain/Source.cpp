#include <iostream>
#include <thread>
#include <mutex>

std::mutex m;
int x = 0;

int main()
{
  std::thread t(main);
  {
    std::lock_guard<std::mutex> guard(m);
    std::cout << x++ << std::endl;
  }
  t.join();
}