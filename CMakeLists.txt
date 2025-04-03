cmake_minimum_required(VERSION 3.30)

# if(MSVC)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++17")
# endif(MSVC)
project(Project)

add_subdirectory(ThirdParty)
add_subdirectory(src)