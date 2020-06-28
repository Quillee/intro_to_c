file(GLOB libcomponents src/**/*.cpp)

add_library(
    say-hello 
    ${libcomponents}
    # src/hello/hello.h
    # src/hello/hello.cpp
    # src/goodbye/goodbye.cpp
)           

target_include_directories(say-hello PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")

target_compile_definitions(say-hello PUBLIC SAY_HELLO_VERSION="${VERSION}")

# target_link_libraries(cmake-good PRIVATE say-hello)

