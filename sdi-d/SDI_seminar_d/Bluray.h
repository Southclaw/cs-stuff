/*
	Blu-Ray Disk
*/
#ifndef BLURAY_H
#define BLURAY_H

#include <string>
#include "Disk.h"

using std::string;


class Bluray : public Disk
{
public:
	Bluray(Project project, string id, string title, string format, string audio, int duration, string language, string price, string aspect, Packaging packaging);
	~Bluray();

private:
	//
};

#endif
