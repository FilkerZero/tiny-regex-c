cmake_minimum_required(VERSION 3.5.0)
project(tiny-regex-c LANGUAGES C)

## Specify path to GTest, e.g.:
# set(CMAKE_PREFIX_PATH "/some/path/to/gtest/")

add_library(${PROJECT_NAME} STATIC
    "re.c"
)
target_include_directories(${PROJECT_NAME} PUBLIC
    "/"
)

## Uncomment the following line to enable tests
# enable_testing()

if(${BUILD_TESTING} true)
    # Set required C++ standard for GoogleTest
    set(CMAKE_CXX_STANDARD 14)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)

    # Find GoogleTest
    find_package(GTest REQUIRED)

    # Find tests
    add_subdirectory("gtests/")
endif()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
