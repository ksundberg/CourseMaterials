cmake_minimum_required(VERSION 3.0)
project(lionheart)
include_directories(
${CMAKE_SOURCE_DIR}
${CMAKE_BINARY_DIR}
)
#################################
# set compiler options

  if(WIN32 AND MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /WX")
  else()
    if(CMAKE_COMPILER_IS_GNUCXX OR ${CMAKE_CXX_COMPILER_ID} MATCHES "Clang")
      set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --std=c++11") 
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -Wno-maybe-uninitialized -Wcast-align -Wformat=2 -Wfloat-equal -Wno-psabi")
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror")
  endif()
  endif()
##############################
# Map Files
set(Map_files
    4player.in
    map1.in
    map2.in
    map3.in
    map4.in
    map6.in
    forts.in
    map.in
    navy.in
   )
foreach(map ${Map_files})
  configure_file(resources/maps/${map} ${map} COPYONLY)
endforeach()
###############################
# Student Files
set(Student_tlas
    adn alt ben bri dww ian jcl jmh oss pld sll tbb
)
set(tla_includes)
set(tla_list)
list(LENGTH Student_tlas tla_count)
foreach(tla ${Student_tlas})
  set(tla_includes "${tla_includes}\n#include \"Player/${tla}.h\"")
  set(tla_list "${tla_list}\"${tla}\",")
  list(APPEND student_sources "Player/${tla}.cpp")
  list(APPEND student_sources "Player/${tla}.h")
  list(APPEND tla_create "\nif(tla==\"${tla}\") return new ${tla}(0,0,hp,up,rank,false,tla)")
endforeach(tla)

source_group("Player" FILES ${student_sources})
list(APPEND lionheart_srcs ${student_sources})

################################
# Provided Sources
configure_file(lionheart.h.in lionheart.h)
set(Provided_srcs
    lionheart.cpp
    lionheart2.h
    lionheart.h
    Board.hpp
    unit.cpp
    unit.h)
source_group("" FILES ${Provided_srcs})
list(APPEND lionheart_srcs ${Provided_srcs})

add_executable(lionheart ${lionheart_srcs})

