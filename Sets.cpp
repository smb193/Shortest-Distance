#include "Sets.h"
#include <cerrno>
#include <fstream>
#include <iostream>
#include <random>
#include <string>

PAIR get_pair()
{
	int first = rand();
	int second = rand();
	PAIR p(first, second);
	return p;
}

TRIP get_trip()
{
	int first = rand();
	int second = rand();
	int third = rand();
	return std::make_tuple(first, second, third);
}

bool make_set(int points, int dim)
{
	//Only supports 2D and 3D
	if (!(dim == 2 || dim == 3))
	{
		std::cerr << "Invalid dimension\n";
		return false;
	}

	//Save to set_(#pts).txt
	std::string fname = "set_" + std::to_string(points) + ".txt";
	std::ofstream ofile(fname);
	if (ofile.is_open())
	{
		if (dim == 2)
		{
			for (int i = 0; i < points; i++)
			{
				PAIR p = get_pair();
				ofile << p.first << " " << p.second << "\n";
			}
		}
		else
		{
			for (int i = 0; i < points; i++)
			{
				TRIP t = get_trip();
				ofile << std::get<0>(t) << " " << std::get<1>(t) << " " << std::get<2>(t) << "\n";
			}
		}
		ofile.close();
		return true;
	}
	else
	{
		std::cerr << "Unable to open file.\n";
		return false;
	}
}