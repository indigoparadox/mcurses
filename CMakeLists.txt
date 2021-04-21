
cmake_minimum_required(VERSION 3.10)

set(CMAKE_C_STANDARD 90)
set(CMAKE_C_STANDARD_REQUIRED TRUE)

project(mcurses)

include_directories(src)

add_library(mcurses src/mcurses.c)
