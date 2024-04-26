# CMakeLists.txt

cmake_minimum_required(VERSION 3.29)
set(CMAKE_CXX_STANDARD 14) # googletest requires at least C++14
set(CMAKE_CXX_STANDARD_REQUIRED True)
project(Uniwal VERSION 1.0 LANGUAGES CXX)

# library
set(LIB_SRC_FILES
    uniwal/orbit.cpp
    uniwal/random.cpp
)
add_library(Uniwal STATIC ${LIB_SRC_FILES})
target_include_directories(Uniwal PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/uniwal)

# testing 
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
## For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
include(CTest)
enable_testing()
set(TEST_SRC_FILES
    uniwal/random.test.cpp
)
add_executable(UniwalTest ${TEST_SRC_FILES})
target_include_directories(UniwalTest PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/uniwal)
add_test(NAME UniwalTestAll  COMMAND UniwalTest)
target_link_libraries(UniwalTest PRIVATE Uniwal GTest::gtest_main)

# application
add_executable(UniwalApp
    app/main.cpp
)
target_include_directories(UniwalApp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/app ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(UniwalApp PRIVATE Uniwal)
