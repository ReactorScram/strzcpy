cmake_minimum_required(VERSION 3.20)

project(strzcpy C)

option(BUILD_TESTS "Build unit tests" ON)

add_library(strzcpy STATIC
    src/strzcpy.c
)

set_target_properties(strzcpy PROPERTIES
    C_STANDARD 17
    C_STANDARD_REQUIRED YES
    C_EXTENSIONS NO
)

if (CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(strzcpy PRIVATE
        -Wall
        -Wextra
        -Wpedantic
        -Werror
        -Wshadow
        -Wstrict-prototypes
        -Wmissing-prototypes
        -Wmissing-declarations
        -Wconversion
        -Wsign-conversion
        -Wcast-qual
        -Wcast-align
        -Wpointer-arith
        -Wwrite-strings
        -Wundef
        -Wformat=2
        -Wnull-dereference
        -Wdouble-promotion
        -Wvla
        -Wuninitialized
        -Winit-self
        -Wredundant-decls
        -Wold-style-definition
        -Wnested-externs
        -Wstrict-overflow=5
        -fno-common
    )
endif()

if (CMAKE_C_COMPILER_ID STREQUAL "GNU")
    target_compile_options(strzcpy PRIVATE
        -fanalyzer
        -Wno-analyzer-infinite-loop
    )
endif()

if (CMAKE_C_COMPILER_ID STREQUAL "MSVC")
    # FIXME: Figure out the strict compiler options for MSVC. Good issue for a first-time contributor!
endif()

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_options(strzcpy PRIVATE
        -O0 -g3 -fno-omit-frame-pointer
    )
endif()

if (BUILD_TESTS)
    include(CTest)
    enable_testing()

    add_executable(strzcpy_tests
        tests/test_strzcpy.c
    )

    set_target_properties(strzcpy_tests PROPERTIES
        C_STANDARD 17
        C_STANDARD_REQUIRED YES
        C_EXTENSIONS NO
    )

    target_link_libraries(strzcpy_tests PRIVATE strzcpy)

    if (CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
        target_compile_options(strzcpy_tests PRIVATE
            -Wall
            -Wextra
            -Wpedantic
            -Werror
            -Wshadow
            -Wstrict-prototypes
            -Wmissing-prototypes
            -Wconversion
            -Wsign-conversion
            -Wcast-qual
            -Wcast-align
            -Wpointer-arith
            -Wwrite-strings
            -Wundef
            -Wformat=2
            -Wnull-dereference
            -Wdouble-promotion
            -Wuninitialized
            -Winit-self
            -Wredundant-decls
            -Wold-style-definition
            -fno-common
        )
    endif()

    if (CMAKE_C_COMPILER_ID STREQUAL "MSVC")
        # FIXME: Figure out the strict compiler options for MSVC. Good issue for a first-time contributor!
    endif()

    if (CMAKE_C_COMPILER_ID STREQUAL "GNU")
        target_compile_options(strzcpy_tests PRIVATE -fanalyzer -Wno-analyzer-infinite-loop)
    endif()

    add_test(NAME strzcpy_tests COMMAND strzcpy_tests)
endif()
