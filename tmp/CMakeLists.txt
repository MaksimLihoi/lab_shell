cmake_minimum_required(VERSION 2.8)


project(shell)

set(SOURCE_EXE main.c)
set(SOURCE_LIB exec.c)

add_library(exec SHARED ${SOURCE_LIB})
add_executable(main ${SOURCE_EXE})

target_link_libraries(main exec)
