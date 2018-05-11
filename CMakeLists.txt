cmake_minimum_required(VERSION 3.10)
project(SimpleSharedPtr)

set(CMAKE_CXX_STANDARD 11)

add_executable(SimpleSharedPtr
        main.cpp SimpleSharedPtr.h)
