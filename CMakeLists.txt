cmake_minimum_required(VERSION 3.7.2 FATAL_ERROR)

project(stopwatch LANGUAGES CXX VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_library(stopwatch INTERFACE)
target_include_directories(stopwatch
        INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
        )

add_library(eld::stopwatch ALIAS stopwatch)

# tests
add_executable(test.dummy tests/dummy.cpp)
target_link_libraries(test.dummy PRIVATE eld::stopwatch)

# installation
include(CMakePackageConfigHelpers)
include(GNUInstallDirs)

set(project_config ${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.cmake)

configure_package_config_file(
        ${CMAKE_CURRENT_SOURCE_DIR}/cmake/${PROJECT_NAME}Config.cmake.in
        ${project_config}
        INSTALL_DESTINATION
        ${CMAKE_INSTALL_LIBDIR}/cmake
)

write_basic_package_version_file(
        ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
        VERSION ${PROJECT_VERSION}
        COMPATIBILITY SameMajorVersion
)

install(TARGETS stopwatch
        EXPORT ${PROJECT_NAME}Targets
        )

install(EXPORT ${PROJECT_NAME}Targets
        NAMESPACE "ELD::"
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake
        )

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/stopwatch
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
        )

install(FILES
        ${project_config}
        ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
        DESTINATION
        ${CMAKE_INSTALL_LIBDIR}/cmake
        )