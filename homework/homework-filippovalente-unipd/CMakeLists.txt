cmake_minimum_required(VERSION 3.10.2)

project (Homework
        VERSION 0.1
        DESCRIPTION "Homework Winter 2019"
        LANGUAGES CXX)

#libreria
add_subdirectory(libs)

#main
add_subdirectory(src)
