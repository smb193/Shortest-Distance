#include "Sets.h"
#include <cassert>
#include <iostream>

int main(int argc, char* argv[])
{
	assert(make_set(10));
	assert(make_set(10, 3));
	assert(make_set(10, 2, "assert_test"));
	return 0;
}