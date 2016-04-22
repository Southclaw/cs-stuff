/*
	Blu-Ray Disk
*/
#ifndef BLURAY_H
#define BLURAY_H

#include <string>
#include <initializer_list>

#include "Disk.h"

using std::string;
using std::initializer_list;


class Bluray : public Disk
{
public:
	Bluray(string id, string title, string format, string audio, int duration, string language, string price, string aspect, Packaging packaging, initializer_list<string> subTracks, initializer_list<string> audTracks);
	~Bluray();

private:
	//
};

#endif
