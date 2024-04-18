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
  https://github.com/cpm-cmake/CPM.cmake/releases/download/v0.39.0/CPM.cmake
  ${CMAKE_CURRENT_BINARY_DIR}/cmake/CPM.cmake
  EXPECTED_HASH SHA256=66639BCAC9DD2907B2918DE466783554C1334446B9874E90D38E3778D404C2EF
)
include(${CMAKE_CURRENT_BINARY_DIR}/cmake/CPM.cmake)

# ---- Add dependencies via CPM ----
# See https://github.com/TheLartians/CPM.cmake for details and examples

# the ModernCppStarter defines an example project called 'Greeter'
CPMAddPackage("gh:TheLartians/ModernCppStarter@0.18.0")

# ---- Create executable ----

# add your source files here
add_executable(Playground main.cpp)
# link to your dependencies' targets here
target_link_libraries(Playground Greeter::Greeter)
# setup your target's properties
set_target_properties(Playground PROPERTIES CXX_STANDARD 17)
