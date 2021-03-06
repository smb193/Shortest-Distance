#ifndef SETS_H
#define SETS_H

#include <tuple>
#include <utility>
#include <vector>

#define PAIR std::pair<int, int>
#define V_PAIR std::vector<PAIR>

#define TRIP std::tuple<int, int, int>
#define V_TRIP std::vector<TRIP>

PAIR get_pair();
TRIP get_trip();

bool make_set(int points, int dim = 2, std::string fname = "");
V_PAIR read_pairs(std::string fname);
V_TRIP read_trips(std::string fname);

bool SortPair(PAIR, PAIR);
bool SortPairY(PAIR, PAIR);
bool SortTrip(TRIP, TRIP);
bool SortTripY(TRIP, TRIP);
bool SortTripZ(TRIP, TRIP);

#endif