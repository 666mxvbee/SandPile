cmake_minimum_required(VERSION 3.10)
project(main)

include_directories(lib/ArgParser lib/SandMatrix lib/TsvParser lib/bmpCreator)

set(SOURCE_FILES
    bin/main.cpp
    lib/ArgParser/argparser.cpp
    lib/SandMatrix/matrix.cpp
    lib/TsvParser/tsvparser.cpp
    lib/bmpCreator/bmpcreator.cpp
)

add_executable(main ${SOURCE_FILES})