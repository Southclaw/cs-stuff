/*
	Double Sided DVD
*/
#ifndef D_DVD_H
#define D_DVD_H

#include <string>
#include "Disk.h"

using std::string;


class D_Dvd : public Disk
{
public:
	D_Dvd(Project project, string id, string title, string format, string audio, int duration, string language, string price, string aspect, Packaging packaging);
	~D_Dvd();

private:
	//
};

#endif
