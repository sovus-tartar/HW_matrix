cmake_minimum_required(VERSION 3.16.3)
project(HW_matrix)
set(CMAKE_CXX_STANDARD 20)
include(CTest)
enable_testing()


add_executable(HW_matrix source/main.cpp headers/matrix.h)
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)



add_executable(unit_tests ./tests/unit_tests.cpp)
target_link_libraries(unit_tests GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(unit_tests)