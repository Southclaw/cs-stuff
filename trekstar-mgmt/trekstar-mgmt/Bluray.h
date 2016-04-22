/*
	Blu-Ray Disk
*/
#ifndef BLURAY_H
#define BLURAY_H

#include <string>
#include <vector>

#include "Disk.h"

using std::string;
using std::vector;


class Bluray : public Disk
{
public:
	Bluray(string id, string title, string format, string audio, int duration, string language, string price, string aspect, Packaging packaging, vector<string> subTracks, vector<string> audTracks);
	~Bluray();

private:
	//
};

#endif
