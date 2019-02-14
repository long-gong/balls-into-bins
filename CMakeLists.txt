cmake_minimum_required(VERSION 3.13)
project(BallsIntoBins)

set(CMAKE_CXX_STANDARD 17)

add_executable(BallsIntoBins utils.hpp balls_into_bins.hpp main.cpp)
target_link_libraries(BallsIntoBins fmt)