#include "stdafx.h"
#include <string>
#include <cstdarg>

#include "Logger.h"

using std::string;


Logger::Logger()
{
	output_ = console;
}

Logger::Logger(string outputFile)
{
	output_ = file;
	outputFile_ = outputFile;
}

void Logger::out(Level l, string msg, ...)
{
	char str[256];

	va_list va;
	va_start(va, msg);

	vsprintf(str, msg.c_str(), va);
	perror(str);

	va_end(va);
}

void Logger::level(Level l)
{

}
