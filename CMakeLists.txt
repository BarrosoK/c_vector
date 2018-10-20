cmake_minimum_required(VERSION 3.12)
project(c_vector)

set(CMAKE_C_STANDARD  99)

add_executable(vector main.c srcs/vector.c inc/vector.h)