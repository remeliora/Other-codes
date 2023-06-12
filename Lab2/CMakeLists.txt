cmake_minimum_required(VERSION 3.16)
project(Lab2)

include(FetchContent)

FetchContent_Declare(
    fmt
    GIT_REPOSITORY https://github.com/fmtlib/fmt.git
    GIT_TAG master
    
)
set(fmt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(fmt)

add_subdirectory(lib)

add_executable(main main/StringFMT_test.cpp)
target_link_libraries(main PRIVATE test::lib fmt::fmt)