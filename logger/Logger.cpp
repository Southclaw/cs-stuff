#include "stdafx.h"
#include <string>
#include <cstdarg>
#include <ostream>

#include "Logger.h"
#include "../sdi-b/SDI_seminar_b/DynArray.h"
#include "../sdi-c/SDI_seminar_c/ArgParse.h"

using std::string;


Logger::Logger()
{
	output_ = console;
}

Logger::Logger(Level l)
{
	level_ = l;
	output_ = console;
}

Logger::Logger(string filename)
{
	output_ = file;
	outputFileName_ = filename;
	outputFile_.open(filename);
}

Logger::Logger(Level l, string filename)
{
	level_ = l;
	output_ = file;
	outputFileName_ = filename;
	outputFile_.open(filename);
}

Logger::Logger(string filename, int argc, char* argv[])
{
	set<char> args = SDI::parseArgsFlags(argc, argv);

	if (args.find('d') != args.end())
		level_ = debug;

	else if (args.find('i') != args.end())
		level_ = info;

	else if (args.find('w') != args.end())
		level_ = warning;

	else if (args.find('e') != args.end())
		level_ = error;

	else
		level_ = none;

	output_ = file;
	outputFileName_ = filename;
	outputFile_.open(filename);
}

Logger::Logger(int argc, char* argv[])
{
	set<char> args = SDI::parseArgsFlags(argc, argv);

	if (args.find('d') != args.end())
		level_ = debug;

	else if (args.find('i') != args.end())
		level_ = info;

	else if (args.find('w') != args.end())
		level_ = warning;

	else if (args.find('e') != args.end())
		level_ = error;

	else
		level_ = none;

	output_ = console;
}

Logger::~Logger()
{
	outputFile_.close();
}

void Logger::level(Level l)
{
	level_ = l;
}

void Logger::out(Level l, string msg, ...)
{
	if(l < level_)
		return;

	int len = msg.length() + 1;
	char* buffer = new char[len];

	va_list va;
	va_start(va, msg);

	vsprintf_s(buffer, len, msg.c_str(), va);
	send(buffer);

	va_end(va);
	delete buffer;
}

void Logger::buf(Level l, string msg, ...)
{
	if (l < level_)
		return;

	char* buffer = new char[msg.length()];

	va_list va;
	va_start(va, msg);

	vsprintf_s(buffer, msg.length(), msg.c_str(), va);
	buffer_.push_back(buffer);

	va_end(va);
	delete buffer;
}

void Logger::flush()
{
	for(int i = 0; i < buffer_.size(); ++i)
		send(buffer_.get(i));

	buffer_.clear();
}

void Logger::send(string msg)
{
	if(output_ == console)
	{
		std::cout << msg << std::endl;
	}
	else
	{
		outputFile_ << msg << std::endl;
	}
}