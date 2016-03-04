/*
	Double Sided DVD
*/
#ifndef D_DVD_H
#define D_DVD_H

#include <string>
#include <initializer_list>

#include "Disk.h"

using std::string;
using std::initializer_list;


class D_Dvd : public Disk
{
public:
	D_Dvd(Project project, string id, string title, string format, string audio, int duration, string language, string price, string aspect, Packaging packaging, initializer_list<string> subTracks, initializer_list<string> audTracks);
	~D_Dvd();

private:
	//
};

#endif
