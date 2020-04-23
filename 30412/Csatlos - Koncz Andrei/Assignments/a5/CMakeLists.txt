cmake_minimum_required(VERSION 3.15)
project(a5 C)

set(CMAKE_C_STANDARD 99)

add_executable(a5 main.c edge.c edge.h graph.c graph.h graphRepresentation.c graphRepresentation.h graphTraversals.c graphTraversals.h node.c node.h queue.c queue.h stack.c stack.h)