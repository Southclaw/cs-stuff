/*
	Disk
*/
#ifndef DISK_H
#define DISK_H

#include <string>
#include <vector>

#include "Media.h"

using std::string;
using std::vector;


class Disk : public Media
{
public:
	Disk(string id, string title, string format, string audio, int duration, string language, string price, string aspect, Packaging packaging, vector<string> subTracks, vector<string> audTracks);
	~Disk();

	operator Media&() { return *this; };

	vector<string> getSubTracks();
	vector<string> getAudioTracks();
	string details();


protected:
	vector<string> subTracks_;
	vector<string> audioTracks_;
	vector<string> bonus_;
};

#endif
