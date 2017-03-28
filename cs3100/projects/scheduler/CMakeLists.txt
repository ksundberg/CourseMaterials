cmake_minimum_required(VERSION 2.8)
project(scheduler)
#################################
# set compiler options
if(WIN32 AND MSVC)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /WX")
else()
  if(CMAKE_COMPILER_IS_GNUCXX OR ${CMAKE_CXX_COMPILER_ID} MATCHES "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --std=c++14")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wcast-qual -pedantic -Wcast-align -Wformat=2 -Wfloat-equal")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror")
  endif()
endif()
################################
set(scheduler_srcs
  AlwaysInCache.hpp
  CacheAlgorithm.hpp
  Event.hpp
  FifoReadyQueue.cpp
  FifoReadyQueue.hpp
  ReadyQueue.hpp
  ShortestJobFirstReadyQueue.cpp
  ShortestJobFirstReadyQueue.hpp
  ApproximateShortestJobFirstReadyQueue.cpp
  ApproximateShortestJobFirstReadyQueue.hpp
  Simulation.cpp
  Simulation.hpp
  Task.cpp
  Task.hpp
  scheduler_main.cpp
  )
add_executable(scheduler ${scheduler_srcs})



