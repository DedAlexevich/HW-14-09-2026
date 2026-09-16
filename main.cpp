#include <iostream>
#include <chrono>

namespace kuznetsov {
  class Clicker {
  public:
    Clicker():
      start_(std::chrono::high_resolution_clock::now())
    {}
    
    double millisec() const
    {
      using std::chrono::high_resolution_clock;
      using std::chrono::duration_cast;
      using std::chrono::milliseconds;
      auto t = high_resolution_clock::now();
      return duration_cast< milliseconds >(t - start_).count();
    }

  private:
      std::chrono::time_point< std::chrono::high_resolution_clock > start_;
  };
}


int main()
{
  long long sum = 0;
  kuznetsov::Clicker cl;
  for(size_t i = 0; i < 1'000'000'000; i++) {
    sum += i;
  }
  std::cout << cl.millisec() << '\n';
}

