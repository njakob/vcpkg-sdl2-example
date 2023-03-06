cmake_minimum_required(VERSION 3.22)

project(example LANGUAGES CXX)

find_package(SDL2 CONFIG REQUIRED)

add_executable(example src/main.cpp)

target_compile_features(example PRIVATE cxx_std_20)
target_link_libraries(example PRIVATE SDL2::SDL2)
target_link_libraries(example PRIVATE SDL2::SDL2main)
