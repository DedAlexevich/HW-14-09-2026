#include <iostream>
#include <chrono>
#include <vector>

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
  constexpr size_t size{1'000'000'000};
  using data_t = std::vector< unsigned long long >;
  using value_t = data_t::value_type;

  double init{}, total{};
  value_t sum{};
  {
    kuznetsov::Clicker cl;
    data_t vals(size, 1);
    init = cl.millisec();
    for (size_t i = 0; i < vals.size(); ++i) {
      sum += vals[i];
    }
    total = cl.millisec();
  }
  std::cout << init << '\n';
  std::cout << total << '\n';
  std::cout << total - init << '\n';
}

