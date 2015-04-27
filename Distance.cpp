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
				if (abs(std::get<0>(set[i]) - std::get<0>(set[j]))> close)
					break;
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
				if (abs(std::get<0>(set[i]) - std::get<0>(set[j]))> close)
					break;
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

void display(V_PAIR set)
{
	for (int i = 0; i < set.size(); ++i)
	{
		std::cout << set[i].first << "," << set[i].second << std::endl;
	}
	std::pair<PAIR, PAIR> closest = ClosePoints(set);

	std::cout << "closest points:  " << closest.first.first << "," << closest.first.second
		<< "   " << closest.second.first << "," << closest.second.second << std::endl;
	std::cout << "distance=" << pt_distance(closest.first, closest.second) << std::endl;
}
void display(V_TRIP v)
{
	for (int i = 0; i < v.size(); ++i)
	{
		std::cout << std::get<0>(v[i]) << "," << std::get<1>(v[i]) << "," << std::get<2>(v[i]) << std::endl;
	}
	std::pair<TRIP, TRIP> closest = ClosePoints(v);

	std::cout << "closest points:  " << std::get<0>(closest.first) << "," << std::get<1>(closest.first) <<
		"," << std::get<2>(closest.first) << "   " << std::get<0>(closest.second) << "," << std::get<1>(closest.second) <<
		"," << std::get<2>(closest.second) << std::endl;
	std::cout << "distance=" << pt_distance(closest.first, closest.second) << std::endl;
}