cmake_minimum_required(VERSION 3.15)
project(CLion C)

set(CMAKE_C_STANDARD 99)

add_executable(CLion main.c head.h sll.c)