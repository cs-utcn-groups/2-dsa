cmake_minimum_required(VERSION 3.15)
project(Code_here C)

set(CMAKE_C_STANDARD 99)

add_executable(Code_here main.c edge.h graph.h graphRepresentation.h graphRepresentation.c stack.h queue.h stack.c queue.c node.h node.c Kruskal.h Kruscal.c BellmanFord.c BellmanFord.h Cover.h Cover.c)