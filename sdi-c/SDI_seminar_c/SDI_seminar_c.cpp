#include "stdafx.h"
#include <vector>
#include <string>
#include <set>
#include <map>

#include "ArgParse.h"


int main(int argc, char* argv[])
{
	std::vector<std::string> a;
	a = SDI::parseArgs(argc, argv);

    return 0;
}
