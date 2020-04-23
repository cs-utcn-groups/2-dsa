cmake_minimum_required(VERSION 3.15)
project(assignment_5 C)

set(CMAKE_C_STANDARD 99)

add_executable(assignment_5 main.c "graphRepresentation.c" "graphRepresentation.h" graph.h node.c node.h list.h list.c queue.c queue.h stack.c stack.h "graphTraversals.c" graphTraversals.h matrix.c matrix.h)