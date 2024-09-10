cmake_minimum_required(VERSION 3.10)
project(MyCpp)

include_directories("./src/inc")

file(GLOB MyCpp_src "./src/*.cpp")
file(GLOB MyCpp_bin "*.cpp")

foreach(bin_src ${MyCpp_bin})
  get_filename_component(bin ${bin_src} NAME_WE)
  add_executable(${bin} ${bin_src} ${MyCpp_src})
  target_compile_options(${bin} PRIVATE -std=c++11 -Wall -g)
  set_target_properties(${bin} PROPERTIES CXX_STANDARD 11)
endforeach(bin_src ${MyCpp_bin})

set_property(
  DIRECTORY
  APPEND
  PROPERTY ADDITIONAL_CLEAN_FILES

  # cmake files
  build/
  CMakeCache.txt
  CMakeFiles/
  cmake_install.cmake
  compile_commands.json
  Makefile
)
