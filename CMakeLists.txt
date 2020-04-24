cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

# ---- Project ----

project(Playground LANGUAGES CXX)

# ---- Fetch CPM ----

set(CPM_DOWNLOAD_LOCATION "${CMAKE_BINARY_DIR}/cmake/CPM.cmake")
set(CPM_VERSION 0.18)

if(NOT EXISTS ${CPM_DOWNLOAD_LOCATION})
  message(STATUS "Downloading CPM.cmake")
  file(DOWNLOAD https://github.com/TheLartians/CPM.cmake/releases/download/v${CPM_VERSION}/CPM.cmake ${CPM_DOWNLOAD_LOCATION})
endif(NOT EXISTS ${CPM_DOWNLOAD_LOCATION})

include(${CPM_DOWNLOAD_LOCATION})

# ---- Add dependencies via CPM ----

CPMAddPackage(
  NAME Greeter
  GITHUB_REPOSITORY TheLartians/ModernCppStarter
  VERSION 0.9
)

# ---- Create executable ----

add_executable(Playground main.cpp)
set_target_properties(Playground PROPERTIES CXX_STANDARD 17)

target_link_libraries(Playground Greeter)