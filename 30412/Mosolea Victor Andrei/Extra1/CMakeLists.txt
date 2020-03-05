cmake_minimum_required(VERSION 3.15)
project(Extra1 C)

set(CMAKE_C_STANDARD 99)

add_executable(Extra1 main.c functions.c head.h countries.h countries.c)