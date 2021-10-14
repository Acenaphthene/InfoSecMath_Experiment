cmake_minimum_required (VERSION 3.1)

project(BigInteger VERSION 0.1)

aux_source_directory(./include SRC_DIR)

add_executable(test main.cpp ${SRC_DIR})