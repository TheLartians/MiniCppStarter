# The MiniCppStarter
#
# Build and run by calling: 
# cmake -S. -Bbuild && cmake --build build && ./build/Playground

cmake_minimum_required(VERSION 3.16)

# ---- Project ----

project(Playground LANGUAGES CXX)

# ---- Fetch CPM ----

file(
  DOWNLOAD
  https://github.com/cpm-cmake/CPM.cmake/releases/download/v0.38.3/CPM.cmake
  ${CMAKE_CURRENT_BINARY_DIR}/cmake/CPM.cmake
  EXPECTED_HASH SHA256=cc155ce02e7945e7b8967ddfaff0b050e958a723ef7aad3766d368940cb15494
)
include(${CMAKE_CURRENT_BINARY_DIR}/cmake/CPM.cmake)

# ---- Add dependencies via CPM ----
# See https://github.com/TheLartians/CPM.cmake for details and examples

# the ModernCppStarter defines an example project called 'Greeter'
CPMAddPackage("gh:TheLartians/ModernCppStarter@0.17.3")

# ---- Create executable ----

# add your source files here
add_executable(Playground main.cpp)
# link to your dependencies' targets here
target_link_libraries(Playground Greeter::Greeter)
# setup your target's properties
set_target_properties(Playground PROPERTIES CXX_STANDARD 17)
