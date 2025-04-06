cmake_minimum_required(VERSION 3.5.0)
set(PROJECT_TESTED ${PROJECT_NAME})
set(PROJECT_TESTS ${PROJECT_NAME}_tests)
project(${PROJECT_TESTS} LANGUAGES C CXX)

# Add tests
message("Detected " ${PROJECT_TESTS})

add_executable(${PROJECT_TESTS} 
    "tests_defs.cpp"
    "tests.cpp"
    "testsn.cpp"    
)

target_include_directories(${PROJECT_TESTS} PRIVATE
    "include/"
)

target_link_libraries(${PROJECT_TESTS} PRIVATE
    ${PROJECT_TESTED}
    GTest::gtest_main
)

gtest_discover_tests(${PROJECT_TESTS})