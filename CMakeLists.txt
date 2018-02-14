cmake_minimum_required(VERSION 3.9)
project(Join)

set(CMAKE_CXX_STANDARD 11)

add_executable(Join main.cpp HashTable.cpp HashTable.h HashEntry.cpp HashEntry.h HashJoin.cpp HashJoin.h)