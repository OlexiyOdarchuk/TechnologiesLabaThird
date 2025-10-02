cmake_minimum_required(VERSION 3.15)

project(ArrayApp)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

include_directories(
    ${PROJECT_SOURCE_DIR}/oop/include
    ${PROJECT_SOURCE_DIR}/func/include
)

file(GLOB OOPSOURCES ${PROJECT_SOURCE_DIR}/oop/src/*.cpp)
file(GLOB FUNCSOURCES ${PROJECT_SOURCE_DIR}/func/src/*.cpp)
file(GLOB OOPONESOURCES ${PROJECT_SOURCE_DIR}/onefile/oopOneFile.cpp)
file(GLOB FUNCONESOURCES ${PROJECT_SOURCE_DIR}/onefile/funcOneFile.cpp)

add_executable(oopArrayApp ${OOPSOURCES})
add_executable(funcArrayApp ${FUNCSOURCES})
add_executable(oopOneFileArrayApp ${OOPONESOURCES})
add_executable(funcOneFileArrayApp ${FUNCONESOURCES})
