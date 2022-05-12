cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(dssolve_c)
add_subdirectory(src)
add_subdirectory(eigen)

find_package(Eigen3 3.4 REQUIRED NO_MODULE)

target_link_libraries(dssolve Eigen3::Eigen)
