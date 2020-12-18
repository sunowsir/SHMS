cmake_minimum_required(VERSION 3.10) 

# set the project name 
project(SHMS-Master) 

include_directories(include)
include_directories(lib/include)

link_libraries(pthread)

add_definitions("-g -Wall")

add_subdirectory(lib)

add_executable(SHMS-Master
    mainMaster.c
    src/LinkList.c
    src/CreateConnect.c
    src/masterConnect.c
    src/getWarningInfo.c
    src/dataTransmission.c
)

target_link_libraries(SHMS-Master SHMS) 
