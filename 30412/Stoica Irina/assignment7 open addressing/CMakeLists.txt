cmake_minimum_required(VERSION 3.15)
project(assignment7_open_addressing C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(assignment7_open_addressing
        hashTable.c
        hashTable.h
        io.c
        io.h
        main.c file.h)
