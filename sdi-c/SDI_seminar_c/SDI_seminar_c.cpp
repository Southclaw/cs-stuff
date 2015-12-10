#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>

#include "ArgParse.h"


using std::vector;
using std::string;
using std::set;
using std::map;

using namespace SDI;

int main(int argc, char* argv[])
{
	printf("Test 1: parseArgs\n\n");

	vector<std::string> a;
	a = parseArgs(argc, argv);

	for(auto i : a)
		printf("'%s'\n", i.c_str());

	printf("Test 2: parseArgsFlags\n\n");

	set<char> f;
	f = parseArgsFlags(argc, argv);

	for (auto i : f)
		printf("'%c'\n", i);

	printf("Test 3: parseArgsValues\n\n");

	map<char, string> v;
	v = parseArgsValues(argc, argv);

	for (auto i : v)
		std::cout << "'" << i.first << "': " << "'" << i.second << "'" << std::endl;

	getchar();

    return 0;
}
