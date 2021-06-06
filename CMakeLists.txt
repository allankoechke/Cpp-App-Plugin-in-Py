cmake_minimum_required(VERSION 3.4)

project(App VERSION 0.1)

add_subdirectory(pybind11)

add_executable(App src/main.cpp)

target_link_libraries(App PRIVATE pybind11::embed)
