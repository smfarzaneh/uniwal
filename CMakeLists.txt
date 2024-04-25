# CMakeLists.txt

cmake_minimum_required(VERSION 3.29)

set(CMAKE_CXX_STANDARD 11)

project(Uniwal VERSION 1.0 LANGUAGES CXX)

set(LIB_SRC_FILES
    uniwal/orbit.cpp
)

add_library(Uniwal STATIC ${LIB_SRC_FILES})
target_include_directories(Uniwal PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/uniwal)

add_executable(UniwalApp
    app/main.cpp
)
target_include_directories(UniwalApp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/app ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(UniwalApp PRIVATE Uniwal)
