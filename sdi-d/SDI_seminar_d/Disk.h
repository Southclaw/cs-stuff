/*
	Disk
*/
#ifndef DISK_H
#define DISK_H

#include "Media.h"


class Disk : public Media
{
public:
	Disk(Project project, string id, string title, string format, string audio, int duration, string language, string price, string aspect, Packaging packaging);
	~Disk();

	vector<string> getSubTracks();
	vector<string> getAudioTracks();
	string details();


protected:
	vector<string> subTracks_;
	vector<string> audioTracks_;
	vector<string> bonus_;
};

#endif
