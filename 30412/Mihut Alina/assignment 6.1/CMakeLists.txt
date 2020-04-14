cmake_minimum_required(VERSION 3.15)
project(assignment_6_1 C)

set(CMAKE_C_STANDARD 99)

add_executable(assignment_6_1 main.c graph.h edge.h graphRepresentation.c graphRepresentation.h node.c node.h graphAlgorithms.c graphAlgorithms.h edge.c functionsForKruskalAlg.c functionsForKruskalAlg.h stack.c stack.h)