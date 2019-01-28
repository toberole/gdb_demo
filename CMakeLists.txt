cmake_minimum_required(VERSION 3.8)

project("gdb_demo")

add_compile_options(-std=c++14)

aux_source_directory(${CMAKE_CURRENT_LIST_DIR}/src SRC_FILES)

include_directories(${CMAKE_CURRENT_LIST_DIR}/include)

add_executable(demo ${SRC_FILES})

target_link_libraries(demo pthread)