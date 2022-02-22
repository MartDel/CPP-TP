# cmake_minimum_required(VERSION 2.8.9)
cmake_minimum_required(VERSION 3.20.5)
project(ex4)

include_directories(headers)

file(GLOB SOURCES "src/*.cpp")

add_executable(ex4 ${SOURCES})
