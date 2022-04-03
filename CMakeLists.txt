cmake_minimum_required(VERSION 3.21)
project(matrix_cal_a)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(matrix_cal_a
        Demo.cpp
        Matrix.cpp
        Matrix.hpp
        )
