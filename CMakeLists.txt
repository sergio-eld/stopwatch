cmake_minimum_required(VERSION 3.7.2 FATAL_ERROR)

project(stopwatch LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_library(stopwatch INTERFACE)
target_include_directories(stopwatch
        INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}
        )

#set_target_properties(stopwatch PROPERTIES
#        CXX_STANDARD 11
#        CXX_STANDARD_REQUIRED TRUE
#        )

# tests
add_executable(test.dummy tests/dummy.cpp)
target_link_libraries(test.dummy PRIVATE stopwatch)

# installation