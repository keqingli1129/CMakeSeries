cmake_minimum_required(VERSION 3.10.0)
project(console VERSION 0.1.0 LANGUAGES C CXX)
set(SourceFiles
    src/console.cpp
)
# Create the console library
add_library(console SHARED
    ${SourceFiles}
)

# Set include directories for the library
target_include_directories(console 
    PUBLIC 
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# Define BUILDING_CONSOLE_DLL when building the library
target_compile_definitions(console PRIVATE BUILDING_CONSOLE_DLL)

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
