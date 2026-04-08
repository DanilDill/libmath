cmake_minimum_required(VERSION 3.10)

project(libmath LANGUAGES CXX)

add_library(math INTERFACE)

target_include_directories(math
    INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

option(ENABLE_CLANG_FORMAT "Enable clang-format" ON)
if(ENABLE_CLANG_FORMAT)
    find_program(CLANG_FORMAT_PATH NAMES clang-format-19 clang-format REQUIRED)
    message(STATUS "Found clang-format: ${CLANG_FORMAT_PATH}")

    file(GLOB_RECURSE CLANG_FORMAT_SRC CONFIGURE_DEPENDS
        include/*.h
    )

    add_custom_target(clang-format-target
        COMMAND
            ${CLANG_FORMAT_PATH} -style=file -i ${CLANG_FORMAT_SRC}
        WORKING_DIRECTORY
            ${CMAKE_SOURCE_DIR}
        COMMENT
            "Formatting files with clang-format ..."
    )

    add_dependencies(math clang-format-target)
endif()

option(ENABLE_CLANG_TIDY "Enable clang-tidy" ON)
if(ENABLE_CLANG_TIDY)
    find_program(CLANG_TIDY_PATH NAMES clang-tidy-19 clang-tidy REQUIRED)
    message(STATUS "Found clang-tidy: ${CLANG_TIDY_PATH}")

    set(CLANG_TIDY_COMMAND ${CLANG_TIDY_PATH} "-config-file=${CMAKE_SOURCE_DIR}/.clang-tidy")
    set_target_properties(math PROPERTIES CXX_CLANG_TIDY "${CLANG_TIDY_COMMAND}")
endif()

install(FILES include/libmath.h
    DESTINATION /usr/local/include
)
set(CPACK_GENERATOR "DEB")
set(CPACK_PACKAGE_NAME "libmath-dev")
set(CPACK_PACKAGE_VERSION "1.0.0")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Danil Dil")
set(CPACK_PACKAGE_DESCRIPTION "Header-only library for math")

add_custom_target(deb_package
    COMMAND ${CMAKE_CPACK_COMMAND} -G DEB
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Generating DEB package using CPack..."
    USES_TERMINAL
)
include(CPack)