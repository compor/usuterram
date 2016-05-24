//

#include <iostream>
#include <thread>
#include <utility>
#include <chrono>
#include <mutex>
using namespace std::chrono_literals;

#include <deque>
#include <random>


std::deque<int> q;
std::mutex q_mtx;
std::condition_variable q_cond;


void produce() {
  std::default_random_engine rg;
  std::uniform_int_distribution<int> distr(1, 100);

  while (true) {
    std::unique_lock<std::mutex> lk(q_mtx);
    typename decltype(q)::value_type d = distr(rg);
    std::cerr << "data  in: " << d << std::endl;
    q.push_front(d);
    lk.unlock();
    q_cond.notify_one();
    std::this_thread::sleep_for(100ms);
  }
}

void consume() {
  while (true) {
    std::unique_lock<std::mutex> lk(q_mtx);
    q_cond.wait(lk, [](){return !q.empty();});
    auto d = q.back();
    q.pop_back();
    std::cerr << "data out: " << d << std::endl;
    //std::this_thread::sleep_for(250ms);
  }
}


int main(int argc, const char *argv[]) {
  std::thread t1(&produce);
  std::thread t2(&consume);

  t1.join();
  t2.join();

  return 0;
}

