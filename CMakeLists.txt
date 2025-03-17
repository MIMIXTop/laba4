cmake_minimum_required(VERSION 3.10)
project(LABA_1)

set(CXX_STANDARD_REQUIRED 17)

set(SOURCES main.cpp
            client.cpp
            function.cpp
            journal.cpp)

add_executable(LABA_1 ${SOURCES})