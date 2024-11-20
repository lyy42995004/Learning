cmake_minimum_required(VERSION 2.8)
project(CMakeTest)

add_executable(main.out main.cpp Hello.cpp)

set(CMAKE_BUILD_TYPE "Debug")