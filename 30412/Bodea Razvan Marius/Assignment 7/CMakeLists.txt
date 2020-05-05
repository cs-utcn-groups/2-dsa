cmake_minimum_required(VERSION 3.15)
project(Hash_tables C)

set(CMAKE_C_STANDARD 99)

add_executable(Hash_tables main.c files.h hashTableChaining.c hashTableChaining.h io.c io.h list.c list.h hashTableOpenAddressing.c hashTableOpenAddressing.h)