#ifndef DISTANCE_H
#define DISTANCE_H

#include "Sets.h"
#include <cmath>
#include <iostream>

double pt_distance(PAIR first, PAIR second);
double pt_distance(TRIP first, TRIP second);

std::pair<PAIR, PAIR> ClosePoints(V_PAIR set);
std::pair<TRIP, TRIP> ClosePoints(V_TRIP set);

std::pair<PAIR, PAIR> DividePoints(V_PAIR& set);
void display(V_PAIR);
void display(V_TRIP);

#endif