cmake_minimum_required(VERSION 3.15)
project(HT_Open_Adressing C)

set(CMAKE_C_STANDARD 99)

add_executable(HT_Open_Adressing main.c io.c io.h files.h hashTable.c hashTable.h)