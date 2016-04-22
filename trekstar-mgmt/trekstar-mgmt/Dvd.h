/*
	DVD
*/
#ifndef DVD_H
#define DVD_H

#include <string>
#include <vector>

#include "Disk.h"

using std::string;
using std::vector;


class Dvd : public Disk
{
public:
	Dvd(string id, string title, string format, string audio, int duration, string language, string price, string aspect, Packaging packaging, vector<string> subTracks, vector<string> audTracks);
	~Dvd();

private:
	//
};

#endif
