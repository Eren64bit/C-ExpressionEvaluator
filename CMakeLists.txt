cmake_minimum_required(VERSION 3.16)

project(CPPExpressionEvaluator VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable(CPPExpressionEvaluator ${SOURCES})

target_compile_options(CPPExpressionEvaluator PRIVATE
    -Wall 
    -Wextra
    -Wpedantic
    -g
)