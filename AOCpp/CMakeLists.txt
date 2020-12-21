cmake_minimum_required(VERSION 3.16)
project(untitled)


add_subdirectory(libs)

add_executable(untitled src/main.cpp src/constants.hpp src/util.hpp)
