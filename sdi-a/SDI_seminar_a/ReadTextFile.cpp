#include "stdafx.h"
#include <stdarg.h>
#include <vector>
#include <string>

#include "ReadTextFile.h"


/*
	Quick and dirty debug printing system

	This works by instead of doing the #if check inside a db function, it
	actually redefines the function call. When the code is compiled	in release
	mode, the db function calls do not exist instead of	calling a pointless
	empty function (instruction calls don't grow on	trees! /s)
*/

void _db(const char* str, ...);
#ifdef _DEBUG
#define db(str, ...) _db(str, __VA_ARGS__) // deprecated in some compilers :(
#else
#define db(str, ...) // do nothing
#endif

std::vector<std::string> SDI::readTextFile(const std::string fileName)
{
	db("readTextFile %s\n", fileName);
	FILE* f;
	std::vector<std::string> v;

	fopen_s(&f, fileName.c_str(), "r");

	if (f != nullptr)
	{
		char* temp_string;

		// get file length
		fseek(f, 0, SEEK_END);
		int length = ftell(f);
		fseek(f, 0, SEEK_SET);

		// allocate for chars, assuming we're only handling 8 bit characters
		char* buffer = new char[length * sizeof(char)];

		fread(buffer, sizeof(char), length, f);
		fclose(f);

		// process for windows line endings (stupid windows)
		int begin = 0;
		bool waitForNextLine = false;
		for (int i = 0; i < length; ++i)
		{
			db("Looping buffer: %d/%d '%c'", i, length, buffer[i]);
			if (buffer[i] > 255) // woah! not ascii - do something
			{
				// raise exception, handle gracefully
				db("ERROR! Non ASCII character found!");
			}

			if (waitForNextLine)
			{
				if (buffer[i] == '\0')
				{
					// End of line! (?)
					// Somehow before the i reached length.
					// Break anyway.
					db("Loop reached \0 character before i (%d) == length (%d)", i, length);
					break;
				}

				if (buffer[i] != '\r' && buffer[i] != '\n')
				{
					// Update the beginning point to the current point
					begin = i;
					waitForNextLine = false;
				}

			}

			if (buffer[i] == '\r' || buffer[i] == '\n') // windows and linux
			{
				// Now a line ending has been reached, a temp string is
				// allocated with the size of the line.
				temp_string = new char[i - begin];

				// Copy the contents of buffer[begin:i] into the temp
				int j = 0;
				for (int k = (i - begin); j < k; ++j)
				{
					db("Grabbing char '%c' from %d/%d", buffer[begin + j], j, k);
					temp_string[j] = buffer[begin + j];
				}
				temp_string[j] = '\0'; // fill in the missing EOS

				db("Pushing '%s'", temp_string);
				// do a char* to string conversion and push back
				v.push_back(temp_string);

				// Flag the loop to wait until it hits a valid character
				// on the next line, unless that line is blank in which
				// case, it will be skipped.
				waitForNextLine = true;
			}
		}
	}

	return v;
}


void _db(const char* str, ...)
{
	printf("DEBUG: ");

	va_list vargs;
	va_start(vargs, str);
	//vfprintf(std::clog, str, vargs); // check if clog is an old cpp thing at uni
	vprintf(str, vargs);
	va_end(vargs);

	printf("\n"); // too lazy to write \n in every debug print!
}
