#include "Distance.h"
#include <algorithm>

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
	double close = pt_distance(set[0], set[1]);
	points.first = set[0];
	points.second = set[1];
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
	double close = pt_distance(set[0], set[1]);

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

// Helper function for determining min distance of point pairs where one point is left of the median and one point is right.
std::pair<PAIR, PAIR> StripPoints(V_PAIR set, double dist)
{
	std::pair<PAIR, PAIR> min;
	min.first = set[0];
	min.second = set[1];
	double min_dist = dist;
	//This loop runs no more than six times: This function takes O(n) time.
	for (int i = 0; i < set.size(); i++)
		for (int j = i + 1; j < set.size() && (set[j].second - set[i].second) < dist; j++)
		{
			if (pt_distance(set[i], set[j]) < min_dist)
				min_dist = pt_distance(set[i], set[j]);
				min.first = set[i];
				min.second = set[j];
		}
	return min;
}

std::pair<PAIR, PAIR> DividePoints(V_PAIR set, int begin, int end)
{
	if (end - begin < 3)
	{
		V_PAIR subset;
		for (int i = begin; i <= end; i++)
		{
			subset.push_back(set[i]);
		}
		std::pair<PAIR, PAIR> p(ClosePoints(subset));
		return p;
	}
	double distl, distr;
	int xmid = set[(begin + end) / 2].first;
	std::pair<PAIR, PAIR> lpoints(DividePoints(set, begin, (end + begin) / 2));
	std::pair<PAIR, PAIR> rpoints(DividePoints(set, (end + begin) / 2 + 1, end));
	distl = pt_distance(lpoints.first, lpoints.second);
	distr = pt_distance(rpoints.first, rpoints.second);
	double min_so_far = std::fmin(distl, distr);
	double upper_range = xmid + min_so_far;
	double lower_range = xmid - min_so_far;
	V_PAIR strip;
	for (int i = begin; i < end; i++)
	{
		if (set[i].first > lower_range)
			if (set[i].first < upper_range)
				strip.push_back(set[i]);
			else
				break;
	}
	std::pair<PAIR, PAIR> lrpoints;
	double distlr = min_so_far;
	if (strip.size() > 1)
	{
		std::pair<PAIR, PAIR> p(StripPoints(strip, min_so_far));
		lrpoints = StripPoints(strip, min_so_far);
		distlr = pt_distance(lrpoints.first, lrpoints.second);
	}
	double abs_min = std::min(distlr, min_so_far);
	if (abs_min == distl)
		return lpoints;
	if (abs_min == distr)
		return rpoints;
	else
		return lrpoints;
}

std::pair<PAIR, PAIR> DividePoints(V_PAIR set)
{
	std::sort(set.begin(), set.end(), SortPair);
	return DividePoints(set, 0, set.size() - 1);
}