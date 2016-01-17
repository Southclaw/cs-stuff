/*
	Logger

	Barnaby Keene 2015
*/

#include <string>
#include <vector>
#include <fstream>
#include "../sdi-b/SDI_seminar_b/DynArray.h"

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
	Logger(Level);
	Logger(string outputFile);
	Logger(Level, string outputFile);
	Logger(string outputFile, int argc, char* argv[]);
	Logger(int argc, char* argv[]);
	~Logger();

	void level(Level l);
	void out(Level l, string msg, ...);
	void buf(Level l, string msg, ...);
	void flush();


private:
	Level level_;
	Output output_;
	string outputFileName_;
	std::ofstream outputFile_;
	DynArray<std::string> buffer_;

	void send(string msg);
};

#endif