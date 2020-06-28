cmake_minimum_required(VERSION 3.17)

project(gl-tut VERSION 3.17)

set(VERSION 0.0.1)
# set(CMAKE_LIBRARY_PATH ${PROJECT_SOURCE_DIR}/lib)
if (UNIX)
    set(GCC_COMPILE_FLAGS "-rdynamic")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -lpthread -ldl ")
else()
    set (GCC_COMPILE_FLAGS "")
endif()

set( CMAKE_VERBOSE_MAKEFILE on )

add_definitions(${GCC_COMPILE_FLAGS})
list(APPEND CMAKE_PROGRAM_PATH "${PROJECT_SOURCE_DIR}/lib")

file(GLOB headers include/*.h)
file(GLOB dirs **/*.cpp src/examples/*/*.cpp)
add_executable(gl-tut ${dirs} ${headers} src/examples/common.cpp)

find_library(GLFW_LIB libglfw3.a REQUIRED)
find_library(GLAD_LIB libglad.a REQUIRED)
# add_library(GLAD_LIB ${PROJECT_SOURCE_DIR}/lib/libglad.a)
# message(${GLAD_LIB})
# add_library(GLFW SHARED ${PROJECT_SOURCE_DIR}/lib/libglfw3.a )

target_include_directories(gl-tut PUBLIC ${PROJECT_SOURCE_DIR}/include/)

target_link_libraries(gl-tut PUBLIC ${GLFW_LIB})
target_link_libraries(gl-tut PUBLIC ${GLAD_LIB})
# set_target_properties(gl-tut PROPERTIES LINKER_LANGUAGE C)

add_subdirectory(src)
