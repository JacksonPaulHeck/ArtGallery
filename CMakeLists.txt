cmake_minimum_required(VERSION 3.14)
project(21f-pa01)
set(EXE_NAME 21f-pa01)

set(input01 "test/input.txt")

foreach (file IN LISTS input01)
    configure_file(${file} ${file} COPYONLY)
endforeach ()

set(CMAKE_CXX_STANDARD 17)
add_executable(${EXE_NAME} src/main.cpp src/picture.cpp src/gallery.cpp)