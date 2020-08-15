cmake_minimum_required(VERSION 3.18.0-rc1)

project(nexustec_project)
include_directories(include)

file(GLOB SOURCES "src/*.cpp" "include/*.h")
add_executable(nexustec ${SOURCES})
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT nexustec)
target_compile_features(nexustec PUBLIC cxx_std_17)




