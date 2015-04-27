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

bool make_set(int points, int dim, std::string fname)
{
	//Only supports 2D and 3D
	if (!(dim == 2 || dim == 3))
	{
		std::cerr << "Invalid dimension\n";
		return false;
	}
	//Save to set_(#pts).txt if not given.
	if (fname.empty())
		fname = "set_" + std::to_string(points);
	fname += ".txt";
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
				ofile << std::get<0>(t) << " " << std::get<1>(t) << " " << std::get<2>(t);
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

V_PAIR read_pairs(std::string fname)
{
	std::ifstream ifile(fname);
	V_PAIR v;
	if (ifile.is_open())
	{
		int first, second;
		ifile >> first >> second;

		while (!ifile.eof())
		{
			PAIR p(first, second);
			v.push_back(p);
			ifile >> first >> second;
		}
		ifile.close();
	}
	else
		std::cerr << "Unable to open file.\n";
	return v;
}

V_TRIP read_trips(std::string fname)
{
	std::ifstream ifile(fname);
	V_TRIP v;
	if (ifile.is_open())
	{
		int first, second, third;
		while (!ifile.eof())
		{
			ifile >> first >> second >> third;
			TRIP t(first, second, third);
			v.push_back(t);
		}
		ifile.close();
	}
	else
		std::cerr << "Unable to open file.\n";
	return v;
}

//sort PAIR vector    sort(vector.begin(), vector.end(), SortPair);
bool SortPair(PAIR i, PAIR j) { return (i.first < j.first); }
bool SortPairY(PAIR i, PAIR j) { return (i.second < j.second); }
//sort TRIP vector    sort(vector.begin(), vector.end(), SortTRIP);
bool SortTrip(TRIP i, TRIP j) { return (std::get<0>(i) < std::get<0>(j)); }
bool SortTripY(TRIP i, TRIP j) { return (std::get<1>(i) < std::get<1>(j)); }
bool SortTripZ(TRIP i, TRIP j) { return (std::get<2>(i) < std::get<2>(j)); }