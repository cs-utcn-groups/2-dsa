cmake_minimum_required(VERSION 3.15)
project(Assignment_6_1 C)

set(CMAKE_C_STANDARD 99)

add_executable(Assignment_6_1 main.c kruskal.c graph.h edge.h kruskal.h graphRepresentation.c graphRepresentation.h bellmanFord.c bellmanFord.h stack.c stack.h node.c node.h)