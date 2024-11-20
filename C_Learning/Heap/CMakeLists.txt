cmake_minimum_required (VERSION 2.8)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -o2 -Wall")

set(CMAKE_BUILD_TYPE Debug)

project (PenInfo)

add_executable(test test.c heap.c)