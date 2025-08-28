cmake_minimum_required(VERSION 3.31)
project(ABC231)
file(GLOB ALL_CPP_FILES "*.cpp")

foreach(source_file ${ALL_CPP_FILES})
    message(STATUS "Adding target for ${source_file}")
    get_filename_component(target_name ${source_file} NAME_WE)
    add_executable(${target_name} ${source_file})
endforeach()
