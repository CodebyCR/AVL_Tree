cmake_minimum_required(VERSION 3.23)
project(AVL_Tree)

set(CMAKE_CXX_STANDARD          20)
set(CMAKE_CXX_STANDARD_REQUIRED OFF)
set(CMAKE_CXX_EXTENSIONS        OFF)

add_executable(AVL_Tree main.cpp AVL_Tree.hpp)
