cmake_minimum_required(VERSION 2.8)
project(NumMethPhy)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall")

include_directories(src/)


add_executable(balle main/balle.cpp src/Ball.h src/Ball.cpp)
target_link_libraries(balle jsoncpp)

add_executable(pendul main/pendul.cpp src/Pendulum.h src/Pendulum.cpp)

add_executable(netwn main/netwn.cpp src/fnewt.cpp src/ge.cpp)

add_executable(orbit main/orbit.cpp src/Comet.cpp src/Comet.h)
target_link_libraries(orbit armadillo)
add_library(Comet src/Comet.cpp src/Comet.h)
target_link_libraries(Comet armadillo)
