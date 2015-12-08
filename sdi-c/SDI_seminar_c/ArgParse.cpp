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


namespace SDI
{

/*
	This function converts each of the parameters to a std::string and collects
	them all in a vector in the same order as argv; this vector is the return
	value of the function.
*/
vector<string> parseArgs(int argc, char * argv[])
{
	vector<string> ret(argc);

	return ret;
}

/*
	This variant collects single character flags that will be set with perhaps a
	‘-‘ or a ‘/’ on the command line; you are free to impose restrictions as
	appropriate, such as each flag must have its own ‘-‘ or all of them must be
	in a no-space string. Case sensitivity is a consideration.
*/
set<char> parseArgsFlags(int argc, char * argv[])
{
	set<char> ret;

	return ret;
}

/*
	This variant collects single character flags that are passed with values,
	such as
		"foo –x=12 –y=true –z=Simon"
	returning {(‘x’, “12”) , (‘y’, “true”) , (‘z’, “Simon”)} or
		"bar –a=no –s=Richard –p=88356"
	returning {(‘a’, “no”) , (‘p’, “88356”) , (‘s’, “Richard”)}
*/
map<char, string> parseArgsValues(int argc, char * argv[])
{
	map<char, string> ret;

	return ret;
}

}