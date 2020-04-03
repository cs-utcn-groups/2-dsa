cmake_minimum_required(VERSION 3.15)
project(assignment5_graphs C)

set(CMAKE_C_STANDARD 99)

add_executable(assignment5_graphs main.c matrixGraph.c matrixGraph.h Queue.c Queue.h list.h list.c node.h node.c edge.c edge.h listGraph.c listGraph.h)