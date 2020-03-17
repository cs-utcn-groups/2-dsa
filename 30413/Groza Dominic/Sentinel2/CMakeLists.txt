cmake_minimum_required(VERSION 3.15)
project(Sentinel2 C)

set(CMAKE_C_STANDARD 99)

add_executable(Sentinel2 main.c instructions.h instructions.c)