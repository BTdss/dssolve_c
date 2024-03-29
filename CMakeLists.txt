cmake_minimum_required(VERSION 3.14)

set(CMAKE_C_COMPILER_NAMES clang gcc icc cc)
set(CMAKE_CXX_COMPILER_NAMES clang++ g++ icpc c++ cxx)

set(CMAKE_DEBUG_POSTFIX d)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)
add_compile_definitions(EIGEN_MPL2_ONLY)

if (MSVC)
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded")
endif()

project(dssolve_c)
add_subdirectory(src)
add_subdirectory(eigen)

set_target_properties(dssolve PROPERTIES DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX})
target_compile_options(dssolve PRIVATE -fpie)

find_package(Eigen3 3.4 REQUIRED NO_MODULE)

target_link_libraries(dssolve Eigen3::Eigen)
target_link_libraries(dssolve -static)

SET(FOLDER_OUT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/dssolve_c")
SET(DSSOLVE_OUT_DIR "${FOLDER_OUT_DIR}/lib")
set_target_properties(dssolve PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${DSSOLVE_OUT_DIR})

if (MSVC)
    set_target_properties(dssolve PROPERTIES OUTPUT_NAME libdssolve)
    set_target_properties(dssolve PROPERTIES ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${DSSOLVE_OUT_DIR})
endif ()

SET(README_PATH "${CMAKE_CURRENT_SOURCE_DIR}/README.md")
SET(LICENSE_APACHE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE-APACHE")
SET(LICENSE_MIT_PATH "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE-MIT")
SET(HEADER_PATH "${CMAKE_CURRENT_SOURCE_DIR}/src/dssolve.h")
file(COPY ${README_PATH} ${LICENSE_MIT_PATH} ${LICENSE_APACHE_PATH} DESTINATION ${FOLDER_OUT_DIR}) 
file(COPY ${HEADER_PATH}  DESTINATION "${FOLDER_OUT_DIR}/include")

IF(CMAKE_BUILD_TYPE MATCHES Debug)
    set_target_properties(test_dssolve PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${FOLDER_OUT_DIR})
ENDIF(CMAKE_BUILD_TYPE MATCHES Debug)
