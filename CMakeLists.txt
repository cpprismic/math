cmake_minimum_required(VERSION 3.14)
project(MathLib VERSION 1.0.0 LANGUAGES CXX)

add_library(math_lib INTERFACE)

target_include_directories(math_lib INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

add_library(MathLib::MathLib ALIAS math_lib)