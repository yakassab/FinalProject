cmake_minimum_required(VERSION 3.25)
project(FinalProject C)

set(CMAKE_C_STANDARD 11)

add_executable(FinalProject main.c menu.c menu.h checks.h checks.c globals.h Student.h Student.c)
