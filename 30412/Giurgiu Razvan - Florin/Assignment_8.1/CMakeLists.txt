cmake_minimum_required(VERSION 3.15)
project(Assignment_8_1 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Assignment_8_1
        algorithms.c
        algorithms.h
        main.c)
