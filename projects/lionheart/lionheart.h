#ifndef LIONHEART_H
#define LIONHEART_H
#include "unit.h"

#include "Player/adc.h"
#include "Player/adn.h"
#include "Player/alt.h"
#include "Player/ben.h"
#include "Player/bos.h"
#include "Player/bri.h"
#include "Player/dww.h"
#include "Player/ian.h"
#include "Player/jcl.h"
#include "Player/jmh.h"
#include "Player/oss.h"
#include "Player/pld.h"
#include "Player/sll.h"
#include "Player/tbb.h"

#include "lionheart2.h"

bool noPlay[NUMTLAS]={
    1,     0,     0,     0,     0,     0,     1,     0,     0,     0,
    1,     1,     0,     0,     0,     1,     0,     0,     0,     0,
    1,     0,     0,     0,     0,     0,     0,     0,     0,     1,
    0,     0,     0,     0,     0,     0,     0,     1,     0,     0,
    0,     0,     1,     0,     0,     0,     1,     0,     0,     0,
    1,     0,     0,     0,     0,     0,     0,     0,     0,     1,
    1,     0,     0,     1,     1,     0,     0,     0,     0,     0,
    0,     1,     0,     0,     0,     0,     0,     0,     1,     0,
    1,     0,     0,     0,     0,     0,     1,     1,     0,     1,
    1,     1,     0,     0,     0,     1,     0,     1,     0,     1,
    0,     0,     1,     0,     1,     0,     0,     0,     0,     0,
    0,     1,     0,     0,     0,     0,     0,     0,     0,     0,
    1,     0,     0,     0,     0,     0,     0,     0,     0,     1,
    0,     0,     0,     0,     0,     1,     0,     1,     0,     0,
    1,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    0,     1,     0,     0,     1,     1,     0,     0,     0,     0,
    0,     1,     1,     0,     0,     1,     1,     0,     0,     0
};
static const string tlalist[NUMTLAS+1]={
"adc","adn","alt","ben","bos","bri","dww","ian","jcl","jmh","oss","pld","sll","tbb",""
};
#endif
