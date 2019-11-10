
cmake_minimum_required(VERSION 3.11)

set(VERSION 1.0)

project("svm")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
#set(CMAKE_VERBOSE_MAKEFILE ON)

file(GLOB_RECURSE SourceFiles "src/*.h" "src/*.cpp")

add_executable(svm ${SourceFiles})
