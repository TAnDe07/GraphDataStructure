cmake_minimum_required(VERSION 3.23)
project(not_so_simple_graph)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)
include_directories(test-unit)

add_executable(not_so_simple_graph
        src/not_so_simple_graph.h
        test-unit/catch.hpp
        test-unit/test.cpp src/main.cpp)
