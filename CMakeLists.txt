cmake_minimum_required(VERSION 3.10)

project("Gray_Leaf" VERSION 1.0.0 LANGUAGES CXX)

set(CXX_STANDARD 20)
set(CXX_STANDARD_REQUIRED ON)
set(CXX_EXTENSIONS OFF)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/../../bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../../lib)

option(BUILD_STATIC "build static" OFF)

set(GRAY_LEAF_PROJECT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(GRAY_LEAF_COMPILER_DIR ${GRAY_LEAF_PROJECT_DIR}/Compiler)

list(APPEND CMAKE_MODULE_PATH "${GRAY_LEAF_COMPILER_DIR}/cmake")
include(add_gray_leaf)

configure_file(
    ${GRAY_LEAF_PROJECT_DIR}/Tools/Config/Config.h.in
    ${GRAY_LEAF_PROJECT_DIR}/Tools/Config/Config.h
    @ONLY
)

add_subdirectory(Compiler)