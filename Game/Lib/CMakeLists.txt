cmake_minimum_required(VERSION 3.17)

add_definitions("-std=c++17")

set(LIB sfml)
project(${LIB})

file(GLOB LIB_HPP iLib.hpp)
file(GLOB LIB_CPP lib_sfml.cpp)

add_library(${LIB} 
    SHARED
    ${LIB_HPP} ${LIB_CPP})

target_link_libraries (${LIB} PUBLIC sfml-system sfml-graphics sfml-audio sfml-network)
