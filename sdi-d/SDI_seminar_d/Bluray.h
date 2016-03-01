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
	Bluray();
	~Bluray();

	string details();

private:
	//
};

#endif
