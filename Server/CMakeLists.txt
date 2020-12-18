cmake_minimum_required(VERSION 3.10) 

# set the project name 
project(SHMS-Server) 

include_directories(include)
include_directories(lib/include)

link_libraries(pthread)

add_definitions("-g -Wall")

add_subdirectory(lib)

add_executable(SHMS-Server
    ./mainServer.c
    src/heartBeat.c
    src/ServerConnect.c
    src/sendWarningInfo.c
    src/dataTransmission.c
    src/getScriptRunInfo.c
    src/runScriptAndSave.c
)

target_link_libraries(SHMS-Server SHMS) 
