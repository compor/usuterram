//

#include <iostream>
#include <thread>
#include <utility>
#include <chrono>
#include <mutex>
using namespace std::chrono_literals;


struct asteroid {
  int mass;
  int velocity;

  std::mutex mtx;
};

void collide(asteroid &a1, asteroid &a2) {
  if (&a1 == &a2)
    return;

  std::lock(a1.mtx, a2.mtx);
  std::lock_guard<std::mutex> lk1(a1.mtx, std::adopt_lock);
  std::this_thread::sleep_for(2s);
  std::lock_guard<std::mutex> lk2(a2.mtx, std::adopt_lock);

  a1.velocity /= 2;
  a2.velocity /= 2;

  return;
}


int main(int argc, const char *argv[])
{
  asteroid b1{ 5, 10 }, b2{ 15, 300 };

  std::thread t3(&collide, std::ref(b1), std::ref(b2));
  std::thread t4(&collide, std::ref(b2), std::ref(b1));

  t3.join();
  t4.join();

  std::cerr << "reached here!\n";

  return 0;
}

