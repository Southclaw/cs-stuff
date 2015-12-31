/*
	Logger

	Barnaby Keene 2015
*/

#include <string>
#include <vector>

using std::string;


#ifndef LOGGER_INCLUDED
#define LOGGER_INCLUDED

enum Level
{
	none,
	error,
	warning,
	info,
	debug
};

enum Output
{
	file,
	console
};

class Logger
{
public:
	Logger();
	Logger(string outputFile);

	void out(Level l, string msg, ...);
	void level(Level l);

private:
	Level level_;
	Output output_;
	string outputFile_;
};

#endif