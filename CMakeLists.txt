cmake_minimum_required(VERSION 3.18)

project(enum-reflection)

set(CMAKE_CXX_STANDARD 17)

aux_source_directory(./src SRC_LIST)

add_executable(enum-reflection ${SRC_LIST})
