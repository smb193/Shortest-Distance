#include "Distance.h"
#include <algorithm>
#include <iterator>

double pt_distance(PAIR first, PAIR second)
{
	return std::sqrt(std::pow(first.first - second.first, 2) + std::pow(first.second - second.second, 2));
}

double pt_distance(TRIP first, TRIP second)
{
	return std::sqrt(std::pow(std::get<0>(first)-std::get<0>(second), 2) + std::pow(std::get<1>(first)-std::get<1>(second), 2) + std::pow(std::get<2>(first)-std::get<2>(second), 2));
}

std::pair<PAIR, PAIR> ClosePoints(V_PAIR set)
{
	std::pair<PAIR, PAIR> points = std::make_pair(set[0], set[1]);
	double close = pt_distance(set[0], set[1]);
	if (set.size() == 2)
		return points;
	std::sort(set.begin(), set.end(), SortPair);
	for (int i = 0; i < set.size() - 1; ++i)
	{
		for (int j = i + 1; j < set.size(); ++j)
		{
//			if ((set[j].first - set[i].first) > close)
//				break;
			double dist = pt_distance(set[i], set[j]);
			if (dist < close && dist != 0)
			{
				close = dist;
				points.first = set[i];
				points.second = set[j];
			}
		}
	}
	return points;
}

std::pair<TRIP, TRIP> ClosePoints(V_TRIP set)
{
	std::pair<TRIP, TRIP> points;
	double close = pt_distance(set[0], set[1]);

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


std::pair<PAIR, PAIR> DividePoints(V_PAIR& set)
{
	if (set.size() <= 3)
		return ClosePoints(set);
	int size = set.size();
	V_PAIR left_set, right_set;
	std::copy(set.begin(), set.begin() + (size / 2), std::back_inserter(left_set));
	std::copy(set.begin() + (size / 2), set.end(), std::back_inserter(right_set));
	int middle = set[size / 2].first;
	std::pair<PAIR, PAIR> left_pair = DividePoints(left_set);
	std::pair<PAIR, PAIR> right_pair = DividePoints(right_set);
	double left_dist = pt_distance(left_pair.first, left_pair.second);
	double right_dist = pt_distance(right_pair.first, right_pair.second);
	std::pair<PAIR, PAIR> min_pair = (left_dist < right_dist) ? left_pair : right_pair;
	double strip_dist = std::fmin(left_dist, right_dist);
	std::sort(set.begin(), set.end(), SortPairY);
	V_PAIR strip;
	std::copy_if(set.begin(), set.end(), std::back_inserter(strip), [&middle, &strip_dist](const PAIR& p)
		{ return abs(middle - p.first) < strip_dist; });
	double min_dist = strip_dist;
	for (int i = 0; i < strip.size() - 1; ++i)
		for (int j = i + 1; j < strip.size() &&
			((strip[j].second - strip[i].second) < strip_dist); ++j)
		{
			double temp_dist = pt_distance(strip[i], strip[j]);
			if (temp_dist < min_dist)
			{
				min_dist = temp_dist;
				min_pair = std::make_pair(strip[i], strip[j]);
			}
		}
	return min_pair;
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