cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

# ---- Project ----

project(Playground LANGUAGES CXX)

# ---- Fetch CPM ----

set(CPM_DOWNLOAD_VERSION 0.27.2) 
set(CPM_DOWNLOAD_LOCATION "${CMAKE_BINARY_DIR}/cmake/CPM_${CPM_DOWNLOAD_VERSION}.cmake")

if(NOT (EXISTS ${CPM_DOWNLOAD_LOCATION}))
  message(STATUS "Downloading CPM.cmake v${CPM_DOWNLOAD_VERSION}")
  file(DOWNLOAD https://github.com/TheLartians/CPM.cmake/releases/download/v${CPM_DOWNLOAD_VERSION}/CPM.cmake ${CPM_DOWNLOAD_LOCATION})
endif()

include(${CPM_DOWNLOAD_LOCATION})

# ---- Add dependencies via CPM ----
# See https://github.com/TheLartians/CPM.cmake for details and examples

CPMAddPackage(
  NAME Greeter
  GITHUB_REPOSITORY TheLartians/ModernCppStarter
  VERSION 0.10
)

# ---- Create executable ----

add_executable(Playground main.cpp)
set_target_properties(Playground PROPERTIES CXX_STANDARD 17)

target_link_libraries(Playground Greeter)