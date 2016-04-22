/*
	DVD
*/
#ifndef DVD_H
#define DVD_H

#include <string>
#include <initializer_list>

#include "Disk.h"

using std::string;
using std::initializer_list;


class Dvd : public Disk
{
public:
	Dvd(string id, string title, string format, string audio, int duration, string language, string price, string aspect, Packaging packaging, initializer_list<string> subTracks, initializer_list<string> audTracks);
	~Dvd();

private:
	//
};

#endif
