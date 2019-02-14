#include <thread>

int main()
{
  std::thread t(main);
  t.join();
}