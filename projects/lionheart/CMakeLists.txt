cmake_minimum_required(VERSION 2.8)
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
      set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --std=c++14")
      set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wcast-qual -pedantic -Wcast-align -Wformat=2 -Wfloat-equal")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror")
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
    tiny.in
    test.in
    map.in
    navy.in
   )
foreach(map ${Map_files})
  configure_file(resources/maps/${map} ${map} COPYONLY)
endforeach()
###############################
# Player files
set(Player_srcs
  Player/SittingDuck.hpp
  Player/Goldfish.hpp
  Player/ChargingBadger.hpp
  Player/WildBoar.hpp
  Player/SnappingTurtle.hpp
  Player/CirclingShark.hpp
  Player/CrouchingTiger.hpp
  Player/HiddenDragon.hpp
  Player/ExamplePlayer.hpp
  Player/ExamplePlayer.cpp

  Player/ChrisIrvine.cpp
  Player/ChrisIrvine.hpp
  Player/BrandonSmith.hpp
  Player/BrandonSmith.cpp
  Player/MathewWarenski.hpp
  Player/MathewWarenski.cpp


)

set(PlayerIncludes)
set(PlayerPushBacks)
foreach(p ${Player_srcs})
  STRING(REGEX MATCH ".+\\.hpp$" header ${p})
  if(header)
    set(PlayerIncludes "${PlayerIncludes}\n#include \"${p}\"")
    string(SUBSTRING ${p} 7 -1  p)
    string(REGEX REPLACE "\\.hpp$" "" p ${p})
    set(PlayerPushBacks "${PlayerPushBacks}\n  players.push_back(std::make_shared<lionheart::${p}>());")
  endif(header)
endforeach(p)
################################
# Displays
find_package(PNG)
set(Display_srcs
  Display.hpp
  ConsoleDisplay.cpp
  ConsoleDisplay.hpp
  AnsiDisplay.cpp
  AnsiDisplay.hpp
  )
if(PNG_FOUND)
  set(PngDisplay_srcs
      CombinedPngDisplay.hpp
      CombinedPngDisplay.cpp
      PngDisplay.hpp
      PngDisplay.cpp
      PngUtils.hpp
      PngUtils.cpp
     )
  list(APPEND Display_srcs ${PngDisplay_srcs})
  add_definitions(-DFOUND_PNG)
endif(PNG_FOUND)


################################
# Units
set(Unit_srcs
  Archer.cpp
  Archer.hpp
  Crown.hpp
  Infantry.hpp
  Knight.hpp
  Unit.cpp
  Unit.hpp
  )

################################
# Provided Sources
set(Aux_srcs
  Action.cpp
  Action.hpp
    Game.cpp
  Game.hpp
  Gauntlet.cpp
  Gauntlet.hpp
  Map.cpp
  Map.hpp
  Plan.cpp
  Plan.hpp
  Player.hpp
  SituationReport.hpp
  Tournament.hpp
  SingleElimination.cpp
  SingleElimination.hpp
  Swiss.cpp
  Swiss.hpp
  )

##############################
#
configure_file(getPlayers.hpp.in getPlayers.hpp)
##############################
# Lionheart
set(lionheart_srcs
  lionheart_main.cpp
  getPlayers.hpp
  )

list(APPEND lionheart_srcs ${Aux_srcs})
list(APPEND lionheart_srcs ${Display_srcs})
list(APPEND lionheart_srcs ${Unit_srcs})
list(APPEND lionheart_srcs ${Player_srcs})
add_executable(lionheart ${lionheart_srcs})
if(PNG_FOUND)
  target_link_libraries(lionheart ${PNG_LIBRARIES})
endif()
###############################
# Developer Tests
set(Test_srcs
  test/catch.hpp
  test/MapTest.cpp
  test/PathsTest.cpp
  test/UnitTest.cpp
  test/UniqueBlazonTest.cpp
  test/test_main.cpp
  Map.cpp
  )

if(PNG_FOUND)
  list(APPEND Test_srcs test/PngTest.cpp)
endif(PNG_FOUND)
list(APPEND Test_srcs ${Display_srcs})
list(APPEND Test_srcs ${Unit_srcs})
list(APPEND Test_srcs ${Aux_srcs})
list(APPEND Test_srcs ${Player_srcs})
add_executable(lionheart_test ${Test_srcs})
if(PNG_FOUND)
  target_link_libraries(lionheart_test ${PNG_LIBRARIES})
endif()

