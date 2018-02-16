cmake_minimum_required(VERSION 3.9)
project(Join)

set(CMAKE_CXX_STANDARD 11)

add_executable(Join main.cpp HashTable.h HashEntry.h HashJoin.cpp HashJoin.h Hash.h Table.h Field.h Fields/IntField.h Fields/DoubleField.h Fields/StringField.h Fields/CharField.h)