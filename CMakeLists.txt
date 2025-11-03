cmake_minimum_required(VERSION 3.15.0)
project(hello)

set(OSBitness 32)
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(OSBitness 64)
endif()
set (FullOutputDir "${CMAKE_SOURCE_DIR}/bin/${CMAKE_SYSTEM_NAME}${OSBitness}/${CMAKE_BUILD_TYPE}")
set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${FullOutputDir}/static libs")
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY "${FullOutputDir}")
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY "${FullOutputDir}")


add_library(console SHARED consolelib/console.cpp)
target_include_directories(console PUBLIC "${CMAKE_SOURCE_DIR}/consolelib")
target_compile_definitions(console PRIVATE BUILDING_CONSOLE_DLL)

# Explicitly control where console library files go
# set_target_properties(console PROPERTIES
#     ARCHIVE_OUTPUT_DIRECTORY "${FullOutputDir}"
#     LIBRARY_OUTPUT_DIRECTORY "${FullOutputDir}"
#     RUNTIME_OUTPUT_DIRECTORY "${FullOutputDir}"
# )


add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} console)


