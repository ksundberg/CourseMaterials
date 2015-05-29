#ifndef LIONHEART2_H
#define LIONHEART2_H

#include <string>

//the name of the map file
const std::string INFILE="forts.in"; 
//set to true for more real estate and less detail
const bool TINYMAP = false; 
//set to true if you want dots to represent open space
const bool DOTS = false;
// set to true if you have an ANSI terminal for colored armies, not for WINDOWS console :-(
const bool ANSI= true;

const bool AUTOTOURNEY = false;
const int AUTONUMMATCHES = 5;
const int MAXTURNS = 500;
const int INFANTRYHP = 10;
const int ARCHERHP = 10;
const int KNIGHTHP = 5;
const int CROWNHP = 1;

//max total number of units on board
const int NUM         =    60;
const int NUMKNIGHTS  =    12;
const int NUMARCHERS  =    16;

#endif
