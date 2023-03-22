cmake_minimum_required(VERSION 3.21)
project(hw4)

set(CMAKE_CXX_STANDARD 14)

add_executable(hw4 main.cpp SplayTree.h Avl.h)
#add_executable(hw4 testGen.cpp SplayTree.h Avl.h)


add_library(SplayTree.h Avl.h main.cpp)