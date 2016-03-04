/*
	Double-sided DVD
*/
#include <string>
#include <initializer_list>

#include "D_Dvd.h"

using std::string;
using std::initializer_list;


D_Dvd::D_Dvd(Project project, string id, string title, string format, string audio, int duration, string language, string price, string aspect, Packaging packaging, initializer_list<string> subTracks, initializer_list<string> audTracks)
	: Disk(project, id, title, format, audio, duration, language, price, aspect, packaging, subTracks, audTracks)
{
}

D_Dvd::~D_Dvd()
{
}
