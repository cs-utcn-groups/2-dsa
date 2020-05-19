cmake_minimum_required(VERSION 3.15)
project(HASH_Chaining C)

set(CMAKE_C_STANDARD 99)

add_executable(HASH_Chaining main.c hashFunctions.c hashFunctions.h io.c io.h list.c list.h files.h)