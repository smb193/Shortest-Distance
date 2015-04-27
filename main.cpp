#include "Distance.h"
#include "Sets.h"
#include <cassert>
#include <iostream>
#include <algorithm>
#include <ctime>

int main(int argc, char* argv[])
{
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
	return 0;
}