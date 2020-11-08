cmake_minimum_required(VERSION 3.16.3)

project(
    Dumm
    VERSION 0.0.1
    LANGUAGES CXX
)

set(EXECUTABLE_OUTPUT_PATH "bin")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(CTest)

add_subdirectory(src)
add_subdirectory(tests)