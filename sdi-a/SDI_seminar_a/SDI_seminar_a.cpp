#include "stdafx.h"

#include "ReadTextFile.h"


/*
	Testing and implementation demo
*/
int main(int argc, char* argv[])
{
	std::vector<std::string> lines = SDI::readTextFile("stuff.txt");

	printf("Result:\n");
	for(int i = 0, j = lines.size(); i < j; ++i)
		printf("line %d/%d: '%s'\n", i, j, lines.at(i).c_str());

	getchar(); // pause the console

	return 0;
}
