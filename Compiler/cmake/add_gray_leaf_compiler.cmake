include(set_windows_version_compiler)

# add_gray_leaf_compiler_library(name type sources version [include_dir] [link_lib])
function(add_gray_leaf_compiler_library name)
    cmake_parse_arguments(ARG "STATIC;SHARED" "VERSION" "SOURCES;INCLUDE_DIR;LINK_LIB" ${ARGN})
    
    file(RELATIVE_PATH lib_path
        ${GRAY_LEAF_COMPILER_DIR}/src/
        ${CMAKE_CURRENT_SOURCE_DIR}
    )

    if(NOT lib_path MATCHES "^[.][.]")
        file(GLOB_RECURSE header_file
            ${GRAY_LEAF_COMPILER_DIR}/include/${lib_path}/*.h
            ${GRAY_LEAF_COMPILER_DIR}/include/${lib_path}/*.def
    )
    endif()

    if(ARG_STATIC)
        set(TYPE STATIC)
    elseif(ARG_SHARED)
        set(TYPE SHARED)
    else()
        if(BUILD_STATIC)
          set(TYPE STATIC)
        else()
          set(TYPE SHARED)
        endif()
    endif()

    add_library(${name} ${TYPE} ${ARG_SOURCES} ${header_file})

    if(ARG_LINK_LIB)
        target_link_libraries(${name} PRIVATE ${ARG_LINK_LIB})
    endif()

    if(ARG_INCLUDE_DIR)
        target_include_directories(${name} PRIVATE ${ARG_INCLUDE_DIR})
    endif()
    
    set_target_properties(${name} PROPERTIES LINKER_LANGUAGE CXX RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../../lib VERSION ${ARG_VERSION})

    if(MSVC AND TYPE STREQUAL "SHARED")
        string(REPLACE "." ";" VERSION_SPLIT "${ARG_VERSION}")

        list(GET VERSION_SPLIT 0 MAJOR)
        list(GET VERSION_SPLIT 1 MINOR)
        list(GET VERSION_SPLIT 2 PATCH)

        SET_WINDOWS_DLL_VERSION(${name} ${ARG_VERSION} ${MAJOR} ${MINOR} ${PATCH})
    endif()
endfunction()