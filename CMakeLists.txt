cmake_minimum_required(VERSION 3.15)
project(DeskCalculator)

set(CMAKE_CXX_STANDARD 14)

add_executable(DeskCalculator main.cpp catch.hpp Token_stream.h headers.h Parser.cpp IF.cpp Driver.cpp)