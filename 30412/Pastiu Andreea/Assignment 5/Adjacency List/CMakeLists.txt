cmake_minimum_required(VERSION 3.15)
project(Adjacency_List C)

set(CMAKE_C_STANDARD 99)

add_executable(Adjacency_List main.c graphTraversals.h graphTraversals.c queue.h queue.c stack.h stack.c node.h node.c)