cmake_minimum_required(VERSION 2.7)
project(LCC3)

set(CMAKE_C_STANDARD 11)

set(LC3_SOURCE_FILES
        driver.c
        lex.yy.c
        y.tab.h y.tab.c
        )

add_executable(LC3 ${LC3_SOURCE_FILES})