cmake_minimum_required(VERSION 3.10)

set(CXX_STANDARD_REQUIRED 17)

find_package(Boost 1.80.0 REQUIRED system chrono thread)


set(SOURCE_FILES
    acceptor.hpp
    server.cpp
)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    add_library(server SHARED ${SOURCE_FILES})
    target_link_libraries(server PUBLIC ${Boost_LIBRARIES})
endif()


