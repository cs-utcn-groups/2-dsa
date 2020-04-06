cmake_minimum_required(VERSION 3.15)
project(Adjacency C)

set(CMAKE_C_STANDARD 99)

add_executable(Adjacency main.c node.h list.h list.c matrix.h matrix.c traversal.h traversal.c transform.h transform.c node.c stack.h stack.c)