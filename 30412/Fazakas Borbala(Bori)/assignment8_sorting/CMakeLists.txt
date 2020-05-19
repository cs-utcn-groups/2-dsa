cmake_minimum_required(VERSION 3.15)
project(assignment8_sorting C)

set(CMAKE_C_STANDARD 99)

add_executable(assignment8_sorting main.c sorting.c sorting.h generateData.c generateData.h)