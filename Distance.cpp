#include "Distance.h"

double pt_distance(PAIR first, PAIR second)
{
	return std::sqrt(std::pow(first.first - second.first, 2) + std::pow(first.second - second.second, 2));
}

double pt_distance(TRIP first, TRIP second)
{
	return std::sqrt(std::pow(std::get<0>(first)-std::get<0>(second), 2) + std::pow(std::get<1>(first)-std::get<1>(second), 2) + std::pow(std::get<2>(first)-std::get<2>(second), 2));
}

std::pair<PAIR,PAIR> ClosePoints(V_PAIR set)
{
	std::pair<PAIR,PAIR> points;
	double close = pt_distance(set[0], set[1]);;

	for (int i = 0; i < set.size(); ++i)
	{
		if (i != set.size() - 1){
			for (int j = i + 1; j < set.size(); ++j)
			{
				
				if (pt_distance(set[i], set[j]) < close && pt_distance(set[i], set[j]) != 0)
				{
					close = pt_distance(set[i], set[j]);
					points.first = set[i];
					points.second = set[j];
				}
			}
		}
	}

	return points;
}

std::pair<TRIP, TRIP> ClosePoints(V_TRIP set)
{
	std::pair<TRIP, TRIP> points;
	double close = pt_distance(set[0], set[1]);;

	for (int i = 0; i < set.size(); ++i)
	{
		if (i != set.size() - 1){
			for (int j = i + 1; j < set.size(); ++j)
			{

				if (pt_distance(set[i], set[j]) < close && pt_distance(set[i], set[j]) != 0)
				{
					close = pt_distance(set[i], set[j]);
					points.first = set[i];
					points.second = set[j];
				}
			}
		}
	}

	return points;
}