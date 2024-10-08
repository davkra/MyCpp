# cmake -B build
# cmake --build ./build --target clean

cmake_minimum_required(VERSION 3.10)
project(MyCpp)

include_directories("./src/inc")

file(GLOB MyCpp_src "./src/*.cpp" "./src/*.c")
file(GLOB MyCpp_bin "./bin/*.cpp" "./bin/*.c")

foreach(bin_src ${MyCpp_bin})
  get_filename_component(bin ${bin_src} NAME_WE)
  add_executable(${bin} ${bin_src} ${MyCpp_src})
  target_compile_options(${bin} PRIVATE -Wall -g)
  set_target_properties(${bin} PROPERTIES CXX_STANDARD 11)
endforeach(bin_src ${MyCpp_bin})

# clean all properties
set_property(
  DIRECTORY
  APPEND
  PROPERTY ADDITIONAL_CLEAN_FILES
  # cmake files
  # ${CMAKE_CURRENT_BINARY_DIR}
  .cmake/
  CMakeCache.txt
  CMakeFiles/
  cmake_install.cmake
  compile_commands.json
  Makefile
)
