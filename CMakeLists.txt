cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

# ---- Project ----

project(Playground LANGUAGES CXX)

# ---- Fetch CPM ----

set(CPM_DOWNLOAD_LOCATION "${CMAKE_BINARY_DIR}/cmake/CPM.cmake")
set(CPM_DOWNLOAD_VERSION 0.25.1)

if(NOT (EXISTS ${CPM_DOWNLOAD_LOCATION} AND CPM_VERSION STREQUAL CPM_DOWNLOAD_VERSION))
  message(STATUS "Downloading CPM.cmake")
  file(DOWNLOAD https://github.com/TheLartians/CPM.cmake/releases/download/v${CPM_DOWNLOAD_VERSION}/CPM.cmake ${CPM_DOWNLOAD_LOCATION})
endif()

include(${CPM_DOWNLOAD_LOCATION})

# ---- Add dependencies via CPM ----

CPMAddPackage(
  NAME Greeter
  GITHUB_REPOSITORY TheLartians/ModernCppStarter
  VERSION 0.10
)

# ---- Create executable ----

add_executable(Playground main.cpp)
set_target_properties(Playground PROPERTIES CXX_STANDARD 17)

target_link_libraries(Playground Greeter)