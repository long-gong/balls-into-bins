// utils.hpp
#ifndef UTILS_HPP
#define UTILS_HPP

#include <iomanip>
#include <iostream>
#include <algorithm>
#include <functional>

//! fixed width print : base case
template<const int width, typename T>
static void print_fw(const T &t) {
  std::cout << std::fixed << std::setw(width) ;
  std::cout << t;
}
//! fixed width print : recursion
template<const int width,  typename T, typename... Ts>
static void print_fw(const T &t, const Ts &... ts) {
  std::cout << std::fixed << std::setw(width) ;
  std::cout << t;
  print_fw<width>(ts...);
}


//! top k
template <typename RandomIt>
void top_k_element(RandomIt first, RandomIt kth, RandomIt last){
  std::nth_element(first, kth, last);
  std::sort(first, kth);
}
template< class RandomIt, class Compare >
void top_k_element( RandomIt first, RandomIt kth, RandomIt last,
                  Compare comp ){
  std::nth_element(first, kth, last, comp);
  std::sort(first, kth, comp);
}

#endif // UTILS_HPP
