cmake_minimum_required(VERSION 3.15)
project(assignment7_chaining C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(assignment7_chaining
        files.h
        hashTable.c
        hashTable.h
        io.c
        io.h
        list.c
        list.h
        main.c)
