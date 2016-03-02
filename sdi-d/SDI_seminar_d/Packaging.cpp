#include "Packaging.h"


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
