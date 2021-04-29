cmake_minimum_required(VERSION 3.19)
project(6_week)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(6_week
        condition_parser.cpp
        condition_parser.h
        condition_parser_test.cpp
        database.cpp
        database.h
        main.cpp
        node.cpp
        node.h
        token.cpp
        token.h
        date.cpp
        date.h
        test_runner.h test_runner.cpp TComparison.h)
