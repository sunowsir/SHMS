cmake_minimum_required(VERSION 3.0)

project(SHMS)

include_directories(include)

link_libraries(pthread)

add_definitions("-g -Wall")

add_library(SHMS STATIC
    src/Get_conf.c
    src/StrtoInt.c
    src/sockFrame.c
    src/Write_Pi_Log.c
)
