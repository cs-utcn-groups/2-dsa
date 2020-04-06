cmake_minimum_required(VERSION 3.15)
project(Lab5 C)

set(CMAKE_C_STANDARD 99)

add_executable(Lab5 main.c graphTraversals.c graphTraversals.h graphRepresentation.c graphRepresentation.h graph.h edge.h node.c node.h stack.c stack.h queue.c queue.h)