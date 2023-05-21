cmake_minimum_required(VERSION 3.10)

set(SOURCE_FILES
    container.cpp
    httpheader.cpp
    httprequest.cpp
    httpresponse.cpp
)

add_library(http SHARED ${SOURCE_FILES})