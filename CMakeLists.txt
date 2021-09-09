cmake_minimum_required(VERSION 3.14)
project(S21-P01-ArtGallery)
set(EXE_NAME ArtGallery)

set(input01 "test/input.txt")
set(output01 "output/test-bruteforce.txt")
set(output02 "output/test-highvalue.txt")
set(output03 "output/test-custom.txt")

foreach (file IN LISTS input01 output01 output02 output03)
    configure_file(${file} ${file} COPYONLY)
endforeach ()

set(CMAKE_CXX_STANDARD 17)
add_executable(${EXE_NAME} src/main.cpp src/picture.cpp src/gallery.cpp)
