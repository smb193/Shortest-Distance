#include "Distance.h"
#include "Sets.h"
#include <cassert>
#include <iostream>
#include <algorithm>
#include <ctime>

int main(int argc, char* argv[])
{
<<<<<<< HEAD
	V_PAIR v = read_pairs("assert_test.txt");
	std::clock_t time = clock();

	time = clock();
	std::pair<PAIR, PAIR> closest2 = DividePoints(v);
	std::cout << "closest points:  " << closest2.first.first << "," << closest2.first.second
		<< "   " << closest2.second.first << "," << closest2.second.second << std::endl;
	std::cout << "distance=" << pt_distance(closest2.first, closest2.second) << std::endl;
	std::cout << std::endl;
	time = clock() - time;
	std::cout << "Took " << (float)time / CLOCKS_PER_SEC << " seconds.\n";

	//std::pair<PAIR, PAIR> closest = ClosePoints(v);
	//std::cout << "closest points:  " << closest.first.first << "," << closest.first.second
	//	<< "   " << closest.second.first << "," << closest.second.second << std::endl;
	//std::cout << "distance=" << pt_distance(closest.first, closest.second) << std::endl;
	//time = clock() - time;
	//std::cout << "Took " << (float)time / CLOCKS_PER_SEC << " seconds.\n";
	//std::cout << std::endl;
	std::cin >> argc;
=======
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
		//std::sort(v.begin(), v.end(), SortTrip);
		//display(v);
	}
	
	{
		
		assert(make_set(10, 2, "assert_test"));
		V_PAIR v = read_pairs("assert_test.txt");
		assert(!v.empty());
		// sort/exhaust test
		//std::sort(v.begin(), v.end(), SortPair);
		//display(v);
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
>>>>>>> origin/master
	return 0;
}