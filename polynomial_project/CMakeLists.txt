cmake_minimum_required(VERSION 3.25)
project(polynomial_project)

set(CMAKE_CXX_STANDARD 17)

add_executable(polynomial_project main.cpp cmake-build-debug/LL.cpp functions.cpp header.h)
