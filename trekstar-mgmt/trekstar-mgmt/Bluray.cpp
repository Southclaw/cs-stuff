/*
	Blu-Ray
*/
#include <string>
#include <initializer_list>

#include "Bluray.h"

using std::string;
using std::initializer_list;


Bluray::Bluray(string id, string title, string format, string audio, int duration, string language, string price, string aspect, Packaging packaging, initializer_list<string> subTracks, initializer_list<string> audTracks)
	: Disk(id, title, format, audio, duration, language, price, aspect, packaging, subTracks, audTracks)
{
}

Bluray::~Bluray()
{
}
