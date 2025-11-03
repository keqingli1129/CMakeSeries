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
if(MSVC)
    add_compile_options(/std:c++latest)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
    set(BUILD_SHARED_LIBS ON)
endif()
set(SubProjects 
    consolelib
)
add_executable(${PROJECT_NAME} main.cpp)

# Use FetchContent to download SDL2
include(FetchContent)
FetchContent_Declare(
    SDL2
    GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
    GIT_TAG release-2.28.5  # Use a stable release
)
FetchContent_MakeAvailable(SDL2)
# Explicitly control where console library files go
# set_target_properties(console PROPERTIES
#     ARCHIVE_OUTPUT_DIRECTORY "${FullOutputDir}"
#     LIBRARY_OUTPUT_DIRECTORY "${FullOutputDir}"
#     RUNTIME_OUTPUT_DIRECTORY "${FullOutputDir}"
# )

foreach(SubProject ${SubProjects})
    if(NOT TARGET ${SubProject})
        add_subdirectory(${SubProject})
    endif()
    target_link_directories(${PROJECT_NAME} PRIVATE {SubProject})
endforeach()

# Link the console library to the main executable
target_link_libraries(${PROJECT_NAME} console SDL2::SDL2 SDL2::SDL2main)

