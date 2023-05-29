cmake_minimum_required(VERSION 3.10)

find_package(Boost 1.80.0 REQUIRED system chrono thread filesystem)



set(SOURCE_FILES
    httpservice.cpp
    container.cpp
)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    add_library(service SHARED ${SOURCE_FILES})
    target_link_libraries(service PUBLIC ${Boost_LIBRARIES} http)
endif()


