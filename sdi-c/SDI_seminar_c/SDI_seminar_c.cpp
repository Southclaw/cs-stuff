#include "stdafx.h"
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

	for(auto s : a)
		printf("'%s'\n", s.c_str());

	printf("Test 2: parseArgsFlags\n\n");

	set<char> f;
	f = parseArgsFlags(argc, argv);

	for (auto s : f)
		printf("'%c'\n", s);


	getchar();

    return 0;
}
