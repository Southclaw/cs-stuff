#include "Packaging.h"


Packaging::Packaging(string n)
{
	name = n
}

Packaging::~Packaging()
{
}

string Packaging::toString()
{
	return name;
}
