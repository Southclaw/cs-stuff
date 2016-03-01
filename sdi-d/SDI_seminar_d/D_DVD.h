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
	D_Dvd();
	~D_Dvd();

	string details();

private:
	//
};

#endif
