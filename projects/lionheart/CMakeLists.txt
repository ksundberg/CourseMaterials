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
    adc adi adn akf akf all alt amo ark asd ben
    boo bos bot bri bro bug bwc cal car cdg cjt
    ckc clg cls clu cmd cow cra crb crd csq ctu
    cwc cze dfv die dih djh dkb dkd dlr dlt dnd
    dos drb drc dre dsc dss dww dxv edb eds emj
    fed god gst gwh hlz hoe hsa hug ian icl ike
    ipm jaz jbp jcl jdd jds jen jfr jmf jmh jms
    jmt jps jrp jrw jta jtd jtg jwl kac kdf kfc
    klb klh knk lam lav lel lhm lia lmn loz m11
    maa mad med mjn mlg mlm mlp mmh mos mpf mrr
    msw mtc nac naw nva ork oss per pez phx pim
    pld pox psg pts rdt rgw rha roa rob rtb sah
    sd9 sdw sgj slj sll sps tas tbb tcg tdm tds
    tgf tgy the thl tlp tom tpa trh tsm usa
)
set(tla_includes)
set(tla_list)
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
#configure_file(lionheart.h.in lionheart.h)
#configure_file(lionheart.cpp.in lionheart.cpp)
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

