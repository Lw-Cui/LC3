cmake_minimum_required(VERSION 2.7)
project(LC3)

set(CMAKE_C_STANDARD 11)

set(LC3_SOURCE_FILES
        driver.c
        lex.yy.c
        y.tab.h y.tab.c
        lc3.h lc3.c
        lc3_var.h lc3_var.c
        lc3_adt.h lc3_adt.c
        lc3_symtab.h lc3_symtab.c
        lc3_func.h lc3_func.c
        lc3_expr.h lc3_expr.c)

add_executable(LC3 ${LC3_SOURCE_FILES})