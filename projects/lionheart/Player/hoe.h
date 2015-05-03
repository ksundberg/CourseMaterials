/********************************************************************************************************
 *                              ASSIGNMENT 11, LION HEART			                        			*
 *					                    hoe.h							                            	*
 *  Zachariah Yoshikawa                                                                      			*
 *  A01417300                                                                               			*
 *  CS1400 - 003 w/ Dan Watson                                      			                		*
 ********************************************************************************************************/
#ifndef hoe_H
#define hoe_H
#include "unit.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>

class hoe: public Unit {
public:
	hoe():Unit(){}

	hoe(int ir,int ic,int ihp,Dir idir,Rank irank,
	    bool idead, string itla):
	    Unit(ir,ic,ihp,idir,irank,idead,itla){}

	void Place(int minR,int maxR,int minC,int maxC, SitRep s); // put unit on board
	Action Recommendation(SitRep s); // tell someone what you want to do

private:

};
#endif
