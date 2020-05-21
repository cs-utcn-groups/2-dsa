cmake_minimum_required(VERSION 3.15)
project(assignment5 C)

set(CMAKE_C_STANDARD 99)

add_executable(assignment5 main.c node.h node.c queue.c queue.h stack.c stack.h graphRepresentation.c graphRepresentation.h graph.h edge.h graphTraversals.c graphTraversals.h "list operations.c" "list operations.h" edge.c graph.c)