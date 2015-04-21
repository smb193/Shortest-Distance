#include "Sets.h"
#include <cassert>
#include <iostream>

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
	}
	{
		assert(make_set(10, 2, "assert_test"));
		V_PAIR v = read_pairs("assert_test.txt");
		assert(!v.empty());
	}
	{
		V_PAIR v = read_pairs("not_a_file.txt");
		assert(v.empty());
	}
	{
		V_TRIP v = read_trips("not_a_file.txt");
		assert(v.empty());
	}
	return 0;
}