cmake_minimum_required(VERSION 3.13)

project(miniflow)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(miniflow tensor_test.cc)