cmake_minimum_required(VERSION 3.3)
project(test_build)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(BUILD_1 main_1)
set(SOURCE_FILES_1 AL_12_03.cpp)
add_executable(${BUILD_1} ${SOURCE_FILES_1})

set(BUILD_2 main_2)
set(SOURCE_FILES_2 KOTYYYYY.cpp)
add_executable(${BUILD_2} ${SOURCE_FILES_2})

set(BUILD_3 main_3)
set(SOURCE_FILES_3 XIWTPZA.cpp)
add_executable(${BUILD_3} ${SOURCE_FILES_3})

set(BUILD_4 main_4)
set(SOURCE_FILES_4 Krzyzak.cpp)
add_executable(${BUILD_4} ${SOURCE_FILES_4})

set(BUILD_5 main_5)
set(SOURCE_FILES_5 mwpz2014l.cpp)
add_executable(${BUILD_5} ${SOURCE_FILES_5})

set(BUILD_6 main_6)
set(SOURCE_FILES_6 BSHEEP.cpp)
add_executable(${BUILD_6} ${SOURCE_FILES_6})

set(BUILD_7 main_7)
set(SOURCE_FILES_7 tprimes.cpp)
add_executable(${BUILD_7} ${SOURCE_FILES_7})

set(BUILD_8 main_8)
set(SOURCE_FILES_8 FACTORIZ.cpp)
add_executable(${BUILD_8} ${SOURCE_FILES_8})

set(BUILD_9 main_9)
set(SOURCE_FILES_9 FACT0.cpp)
add_executable(${BUILD_9} ${SOURCE_FILES_9})