cmake_minimum_required(VERSION 3.13)
project(BigInteger)

set(CMAKE_CXX_STANDARD 14)

add_executable(BigInteger main.cpp big_integer.cpp shared_ptr.cpp)