cmake_minimum_required(VERSION 3.10)

project(banking-system CXX)

set(CXX_STANDARD 17)
set(CXX_STANDARD_REQUIRED ON)

set(EXECUTABLE_NAME banking-system)

add_subdirectory(http)
add_subdirectory(service)
add_subdirectory(server)

add_executable(${EXECUTABLE_NAME} main.cpp)
target_link_libraries(${EXECUTABLE_NAME} PUBLIC http service server)

