cmake_minimum_required(VERSION 3.13)
project(mardcpp)

set(CMAKE_CXX_STANDARD 17)

add_library(mardcpp mardcpp.cpp mardcpp.h collections/LinkedList.h collections/Collections.h time.h mardcpp/time.cpp)
include_directories("/home/mard/Code/C")