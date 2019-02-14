#include <iostream>
#include <fstream>
#include <unordered_map>
#include <algorithm>
#include "balls_into_bins.hpp"
#include "utils.hpp"
#include <fmt/format.h>

int main(int argc, char *argv[]){
  auto m = size_t(1e6);
  std::size_t n = m;
  std::size_t k = 10;
  std::size_t print_cnt = 30;
  auto T = std::size_t(1e3);

  BallsIntoBins bib(m, n);

  std::vector<std::unordered_map<size_t, size_t>> histograms(2 * k - 1);

  auto print_interval = (T  + print_cnt) / print_cnt;
  for (std::size_t i = 0;i < T;++ i) {
    auto buckets = bib.simulate();
    std::vector<size_t> counters;
    counters.reserve(buckets.size());
    for (const auto &b: buckets)
      counters.push_back(b.second);
    //top_k_element(counters.begin(), counters.begin() + k - 1, counters.end(), std::greater<>());
    std::sort(counters.begin(), counters.end(), std::greater<>());
    if(i % print_interval == 0) {
      std::for_each(counters.begin(), counters.begin() + k,
        [](const size_t & c) { print_fw<6>(c);});
      std::cout << "\n";
     }

    // top k histograms
    for(size_t j = 0;j < k;++ j) {
      auto c = counters[j];
      if(histograms[j].find(c) == histograms[j].end()) histograms[j][c] = 1;
      else ++ histograms[j][c];
    }
    // top k consecutive diff histograms
    for(size_t j = k;j < histograms.size();++ j){
      auto i1 = j - k;
      auto i2 = i1 + 1;
      auto diff = counters[i1] - counters[i2];
      if(histograms[j].find(diff) == histograms[j].end()) histograms[j][diff] = 1;
      else ++ histograms[j][diff];
    }
  }



  for(size_t j = 0;j < k; ++ j) {
    try {
      std::string out = fmt::format("bib_histograms_{:02}.csv", j);
      std::ofstream of(out, std::ios::out);

      if (of.bad()) {
        std::cerr << "Failed to open " << out << std::endl;
        exit(1);
      }
      const auto &hist = histograms[j];
      for (const auto &b : hist) {
        of << b.first << "," << b.second << "\n";
      }
    } catch (fmt::v5::format_error& e){
      std::cerr << "[FormatError]: " << e.what() << std::endl;
    }
  }

  for(size_t j = k;j < histograms.size(); ++ j) {
    auto i1 = j - k;
    std::string out = fmt::format("bib_histograms_diff_{:02}.csv", i1);
    std::ofstream of(out, std::ios::out);

    if(of.bad()) {
      std::cerr << "Failed to open " << out << std::endl;
      exit(1);
    }
    const auto& hist = histograms[j];
    for (const auto& b : hist) {
      of << b.first << "," << b.second << "\n";
    }
  }

  std::cout << "!!Finished!!\n" << std::endl;


  return 0;
}