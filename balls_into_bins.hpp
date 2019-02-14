// balls_into_bins.hpp
#ifndef BALLS_INTO_BINS_HPP
#define BALLS_INTO_BINS_HPP
#include <random> // std::mt19937_64
#include <chrono> // std::chrono::system_clock
#include <unordered_map> // std::unordered_map
#include <cassert>

class BallsIntoBins {
public:
  explicit BallsIntoBins(std::size_t num_balls, std::size_t num_bins, std::mt19937_64::result_type seed):
  _m(num_balls), _n(num_bins),
  _seed(seed), _engine(_seed), _default_dist(0, num_bins - 1) {
    assert(num_balls > 1 && num_bins > 1); // avoid trivial case
  }
  explicit BallsIntoBins(std::size_t num_balls, std::size_t num_bins):
  BallsIntoBins(num_balls, num_bins, (std::mt19937_64::result_type)(std::chrono::system_clock::now().time_since_epoch().count())) {

  }
  explicit BallsIntoBins(std::size_t n): BallsIntoBins(n, n) {

  }
  template< typename RBG >
  std::unordered_map<size_t/* bucket id */, size_t /* bucket size */> simulate(RBG&& g) {
    std::unordered_map<size_t/* bucket id */, size_t /* bucket size */> buckets;
    for(auto k = 0;k < _m;++ k){
      auto r = _default_dist(g);
      if(buckets.find(r) == buckets.end()) buckets[r] = 1;
      else ++ buckets[r];
    }
    return buckets;
  }
  std::unordered_map<size_t/* bucket id */, size_t /* bucket size */> simulate() {
    std::unordered_map<size_t/* bucket id */, size_t /* bucket size */> buckets;
    for(auto k = 0;k < _m;++ k){
      auto r = _default_dist(_engine);
      if(buckets.find(r) == buckets.end()) buckets[r] = 1;
      else ++ buckets[r];
    }
    return buckets;
  }
protected:
  std::size_t _m;// number of balls
  std::size_t _n;// number of bins
  std::mt19937_64::result_type _seed;// random seed
  std::mt19937_64 _engine;// random number engine
  std::uniform_int_distribution<> _default_dist;// default distribution
};

#endif // BALLS_INTO_BINS_HPP
