cmake_minimum_required(VERSION 3.15)
project(Open_Addressing C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Open_Addressing
        files.h
        hashTable.c
        hashTable.h
        io.c
        io.h
        main.c)
