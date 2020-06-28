cmake_minimum_required(VERSION 3.17)

set(VERSION 0.0.1)
message(STATUS "myproject - ${VERSION}")

project(myproject VERSION "${VERSION}")

set(cond FALSE)

# negate boolean value = NOT
# STREQUAL => == for strings 

if(NOT cond)
    message(STATUS "Condition was met")
else()
    message(STATUS "Condition failed")
endif()

add_subdirectory(hello)
add_subdirectory(src)
