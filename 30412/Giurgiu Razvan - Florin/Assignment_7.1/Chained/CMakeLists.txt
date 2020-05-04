cmake_minimum_required(VERSION 3.15)
project(Chained C)

set(CMAKE_C_STANDARD 99)

add_executable(Chained main.c list.c list.h io.c io.h hashTable.c hashTable.h files.h)