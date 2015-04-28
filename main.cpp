#include "Distance.h"
#include "Sets.h"
#include <cassert>
#include <iostream>
#include <algorithm>
#include <chrono>

int main(int argc, char* argv[])
{
	srand(12309);
	make_set(20000, 2, "test");
	V_PAIR v = read_pairs("test.txt");
	V_PAIR v2 = read_pairs("test.txt");

	std::chrono::high_resolution_clock::time_point t = std::chrono::high_resolution_clock::now();
	std::pair<PAIR, PAIR> closest = ClosePoints(v);
	std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();

	auto time = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t).count();

	t = std::chrono::high_resolution_clock::now();
	std::pair<PAIR, PAIR> closest2 = DividePoints(v2);
	t2 = std::chrono::high_resolution_clock::now();

	auto time2 = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t).count();

	std::cout << "closest points:  " << closest.first.first << "," << closest.first.second
		<< "   " << closest.second.first << "," << closest.second.second << std::endl;
	std::cout << "distance=" << pt_distance(closest.first, closest.second) << std::endl;

	std::cout << "Took " << time << " milliseconds.\n";
	std::cout << std::endl;

	std::cout << "closest points:  " << closest2.first.first << "," << closest2.first.second
		<< "   " << closest2.second.first << "," << closest2.second.second << std::endl;
	std::cout << "distance=" << pt_distance(closest2.first, closest2.second) << std::endl;
	std::cout << "Took " << time2 << " milliseconds.\n";
	std::cout << std::endl;

	std::cin >> argc;

	/*{
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
	}*/
	return 0;
}