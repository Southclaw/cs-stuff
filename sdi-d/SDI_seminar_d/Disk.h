/*
	Disk
*/
#ifndef DISK_H
#define DISK_H

#include <string>
#include <vector>
#include <initializer_list>

#include "Media.h"

using std::string;
using std::initializer_list;


class Disk : public Media
{
public:
	Disk(Project project, string id, string title, string format, string audio, int duration, string language, string price, string aspect, Packaging packaging, initializer_list<string> subTracks, initializer_list<string> audTracks);
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
