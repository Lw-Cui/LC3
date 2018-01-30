cmake_minimum_required(VERSION 2.7)
project(LC3)

set(CMAKE_C_STANDARD 11)

set(LC3_SOURCE_FILES
        driver.c
        lex.yy.c
        y.tab.h y.tab.c
        lc3.c lc3.h
        lc3_type.h lc3_type.c)

add_executable(LC3 ${LC3_SOURCE_FILES})