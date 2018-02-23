cmake_minimum_required(VERSION 3.9)
project(Join)

set(CMAKE_CXX_STANDARD 17)

add_executable(Join main.cpp HashTable.h HashEntry.h HashJoin.cpp HashJoin.h Table.h Field.h Expr.h TypeValue.h)