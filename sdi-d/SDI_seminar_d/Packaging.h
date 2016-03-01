/*
	Packaging
*/
#ifndef PACKAGING_H
#define PACKAGING_H

#include <string>

using std::string;


class Packaging
{
public:
	Packaging(string name);
	string toString();

private:
	string name;
};

#endif