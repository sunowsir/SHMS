cmake_minimum_required(VERSION 3.0)

project(SHMS)

add_definitions("-Wall -std=c++11 -l pthread")

add_library(SHMS-public STATIC
    src/Get_conf.c
    src/StrtoInt.c
    src/sockFrame.c
    src/Write_Pi_Log.c
)
