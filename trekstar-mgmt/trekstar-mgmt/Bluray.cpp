/*
	Blu-Ray
*/
#include <string>
#include <vector>

#include "Bluray.h"

using std::string;
using std::vector;


Bluray::Bluray(string id, string title, string format, string audio, int duration, string language, string price, string aspect, Packaging packaging, vector<string> subTracks, vector<string> audTracks)
	: Disk(id, title, format, audio, duration, language, price, aspect, packaging, subTracks, audTracks)
{
}

Bluray::~Bluray()
{
}
