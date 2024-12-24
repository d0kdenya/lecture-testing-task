cmake_minimum_required(VERSION 3.10)
project(stack)

set(CMAKE_C_STANDARD 99)

add_library(stack STATIC stack.c)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fprofile-arcs -ftest-coverage")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")

add_executable(main main.c)
target_link_libraries(main stack)

add_executable(test_stack test_stack.c stack.c)
target_link_libraries(test_stack stack)