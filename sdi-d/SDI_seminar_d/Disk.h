/*
	Disk
*/
#ifndef DISK_H
#define DISK_H

#include "Media.h"


class Disk : public Media
{
public:
	vector<string> getSubTracks();
	vector<string> getAudioTracks();
	string details();


protected:
	vector<string> subTracks_;
	vector<string> audioTracks_;
	vector<string> bonus_;
};

#endif
