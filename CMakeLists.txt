cmake_minimum_required(VERSION 3.10)
project(MyCpp)

include_directories(./src/inc)

file(GLOB MyCpp_src "./src/*.cpp")
file(GLOB MyCpp_bin *.cpp)

foreach(bin_src ${MyCpp_bin})
  get_filename_component(bin ${bin_src} NAME_WE)
  add_executable(${bin} ${bin_src} ${MyCpp_src})
  target_compile_options(${bin} PRIVATE -std=c++11 -Wall -g)
  set_target_properties(${bin} PROPERTIES CXX_STANDARD 11)
endforeach(bin_src ${MyCpp_bin})

add_custom_target(clean_cmake_files
    COMMAND make clean && ${CMAKE_COMMAND} -E rm -rf
        CMakeCache.txt
        CMakeFiles
        cmake_install.cmake
        Makefile
        compile_commands.json
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Removing CMake-generated files"
)

add_custom_target(distclean
    DEPENDS clean_cmake_files
    COMMENT "Running custom clean (removes CMake files)"
)
