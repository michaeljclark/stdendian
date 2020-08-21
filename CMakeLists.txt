cmake_minimum_required(VERSION 3.0)

project(bytes)

include_directories(include)

add_executable(test_endian tests/test_endian.c)
