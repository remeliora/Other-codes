add_library(test STATIC)
target_include_directories(test PUBLIC include)
target_sources(test PRIVATE src/Point.cpp src/Arrays.cpp src/Shape.cpp src/OPI_1.cpp)
add_library(test::lib ALIAS test)