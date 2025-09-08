cmake_minimum_required(VERSION 3.16)
project(dslib CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ---------- Library ----------
add_library(dsa src/simple_vector.cpp)
target_include_directories(dsa PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# ---------- Catch2 ----------
include(FetchContent)
FetchContent_Declare(
  catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v3.6.0 # update if newer
)
FetchContent_MakeAvailable(catch2)

# ---------- Tests ----------
add_executable(simple_vector_test tests/simple_vector_test.cpp)
target_link_libraries(simple_vector_test PRIVATE dsa Catch2::Catch2WithMain)
