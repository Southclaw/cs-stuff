#include "stdafx.h"

#include <vector>


namespace SDI
{
	/*
	sdi::vector<std::string> SDI::readTextFile(const std::string);

	The initial specification is to read a text file – the name of the file is
	the parameter, which can include a path. The return value will be a vector
	of strings with these rules for the file

	- Empty files (zero length) return an empty vector
	- Not-found files return an empty vector
	- Text files return one line per vector element, in file order (one line is
	defined by whatever is returned by getline

	Other requirements to respect
	- declare & define the function it in the namespace SDI
	- add debug code to provide a commentary when it is switched on – which
	functions are called, what parameters they are passed, return values,
	- debug code should be conditionally compiled (guarded by _DEBUG which VS
	sets automatically for debug mode
	- no console Input in the function (keep it in main() only for the moment)
	- send debug output to std::clog
	*/

	std::vector<std::string> readTextFile(const std::string fileName);
}
