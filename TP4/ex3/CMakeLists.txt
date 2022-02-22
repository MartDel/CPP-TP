# cmake_minimum_required(VERSION 2.8.9)
cmake_minimum_required(VERSION 3.20.5)
project(ex3)

include_directories(headers)

file(GLOB SOURCES "src/*.cpp")

add_executable(ex3 ${SOURCES})
