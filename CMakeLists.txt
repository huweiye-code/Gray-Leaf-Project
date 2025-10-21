cmake_minimum_required(VERSION 3.10)

project("GRAY_LEAF" VERSION 1.0.0 LANGUAGES CXX)

set(CXX_STANDARD 20)
set(CXX_STANDARD_REQUIRED ON)
set(CXX_EXTENSIONS OFF)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/../../bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../../lib)

option(BUILD_STATIC "Choose build static or shared" OFF)

set(GRAY_LEAF_PROJECT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(GRAY_LEAF_COMPILER_DIR ${GRAY_LEAF_PROJECT_DIR}/Compiler)
set(GRAY_LEAF_SUPPORT_DIR ${GRAY_LEAF_PROJECT_DIR}/Support)

list(APPEND CMAKE_MODULE_PATH "${GRAY_LEAF_COMPILER_DIR}/cmake" "${GRAY_LEAF_SUPPORT_DIR}/cmake")
include(add_gray_leaf_compiler)
include(add_gray_leaf_support)

configure_file(
    ${GRAY_LEAF_PROJECT_DIR}/Tools/Config/Config.h.in
    ${GRAY_LEAF_PROJECT_DIR}/Tools/Config/Config.h
    @ONLY
)

add_subdirectory(Compiler)
