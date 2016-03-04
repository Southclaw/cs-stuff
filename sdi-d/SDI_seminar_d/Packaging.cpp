/*
	Packaging
*/
#include <string>

#include "Packaging.h"

using std::string;


Packaging::Packaging()
{
	name = "unknown";
}

Packaging::Packaging(string n)
{
	name = n;
}

Packaging::~Packaging()
{
}

string Packaging::toString()
{
	return name;
}
