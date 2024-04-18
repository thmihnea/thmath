cmake_minimum_required(VERSION 3.0)
project(thmath)

add_executable(
    main 
    main.cpp 
    exception/illegal_size_exception.cpp
    exception/illegal_access_exception.cpp 
    exception/different_size_exception.cpp 
    vector.cpp
    complex.cpp
)