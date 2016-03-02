/*
	DVD
*/
#ifndef DVD_H
#define DVD_H

#include <string>
#include "Disk.h"

using std::string;


class Dvd : public Disk
{
public:
	Dvd(Project project, string id, string title, string format, string audio, int duration, string language, string price, string aspect, Packaging packaging);

private:
	//
};

#endif
