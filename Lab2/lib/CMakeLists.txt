add_library(test STATIC)
target_link_libraries(test fmt::fmt)
target_include_directories(test PUBLIC include)
target_sources(test PRIVATE src/StringFMT.cpp)
add_library(test::lib ALIAS test)