cmake_minimum_required(VERSION 3.10)
project(LABA_1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES main.cpp
            client.cpp
            function.cpp
            journal.cpp
            templateVector.cpp
            templateVector.hpp)

add_executable(LABA_1 ${SOURCES})