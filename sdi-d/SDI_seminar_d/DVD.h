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
	Dvd();
	~Dvd();

	string details();

private:
	//
};

#endif
