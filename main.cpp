#include "Distance.h"
#include "Sets.h"
#include <cassert>
#include <iostream>
#include <algorithm>

int main(int argc, char* argv[])
{
	{
		assert(make_set(10));
		V_PAIR v = read_pairs("set_10.txt");
		assert(!v.empty());
	}
	{
		
		assert(make_set(10, 3));
		V_TRIP v = read_trips("set_10.txt");
		
		assert(!v.empty());
		// sort/exhaust test
		/*std::sort(v.begin(), v.end(), SortTrip);
		for (int i = 0; i < v.size(); ++i)
		{
			std::cout << std::get<0>(v[i]) << "," << std::get<1>(v[i]) <<","<< std::get<2>(v[i]) << std::endl;
		}
		std::pair<TRIP, TRIP> closest = ClosePoints(v);
		std::cout << "closest points:  " << std::get<0>(closest.first) << "," << std::get<1>(closest.first) <<
			"," << std::get<2>(closest.first) << "   " << std::get<0>(closest.second) << "," << std::get<1>(closest.second) <<
			"," << std::get<2>(closest.second)<<std::endl;
		std::cout << "distance=" << pt_distance(closest.first, closest.second) << std::endl;*/
	}
	{
		
		assert(make_set(10, 2, "assert_test"));
		V_PAIR v = read_pairs("assert_test.txt");
		assert(!v.empty());
		// sort/exhaust test
		/*std::sort(v.begin(), v.end(), SortPair);
		for (int i = 0; i < v.size(); ++i)
		{
			std::cout << v[i].first << "," << v[i].second << std::endl;
		}
		std::pair<PAIR, PAIR> closest = ClosePoints(v);
		std::cout << "closest points:  " << closest.first.first << "," << closest.first.second 
				<< "   " << closest.second.first << "," << closest.second.second << std::endl;
		std::cout << "distance=" << pt_distance(closest.first, closest.second)<<std::endl;*/
	}
	{
		V_PAIR v = read_pairs("not_a_file.txt");
		assert(v.empty());
	}
	{
		V_TRIP v = read_trips("not_a_file.txt");
		assert(v.empty());
	}
	{
		PAIR p1(0, 0);
		PAIR p2(0, 0);
		assert(pt_distance(p1, p2) == 0);
	}	
	{
		TRIP p1 = std::make_tuple(0, 0, 0);
		TRIP p2 = std::make_tuple(0, 0, 0);
		assert(pt_distance(p1, p2) == 0);
	}
	{
		PAIR p1(0, 0);
		PAIR p2(3, 4);
		assert(pt_distance(p1, p2) == 5);
	}
	{
		TRIP p1 = std::make_tuple(0, 0, 0);
		TRIP p2 = std::make_tuple(1, 2, 2);
		assert(pt_distance(p1, p2) == 3);
	}
	return 0;
}