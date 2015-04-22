#include "Distance.h"

double pt_distance(PAIR first, PAIR second)
{
	return std::sqrt(std::pow(first.first - second.first, 2) + std::pow(first.second - second.second, 2));
}

double pt_distance(TRIP first, TRIP second)
{
	return std::sqrt(std::pow(std::get<0>(first)-std::get<0>(second), 2) + std::pow(std::get<1>(first)-std::get<1>(second), 2) + std::pow(std::get<2>(first)-std::get<2>(second), 2));
}