cmake_minimum_required(VERSION 3.14)

project(gtest_sample VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
option(BUILD_GMOCK "Builds the googlemock subprojects" OFF)
option(INSTALL_GTEST "Enables installation of googletest" OFF)

add_executable(${PROJECT_NAME}
    test.cpp
)

target_link_libraries(${PROJECT_NAME} gtest_main)

enable_testing()

# Replacement for "add_test(NAME test COMMAND ${PROJECT_NAME})"
include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})

if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4 /WX)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Werror -Wshadow -Wundef)
endif()
