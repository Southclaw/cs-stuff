#include "Disk.h"


vector<string> Disk::getSubTracks()
{
	return subTracks_;
}

vector<string> Disk::getAudioTracks()
{
	return audioTracks_;
}

string Disk::details()
{
	std::string s;
	std::string subs;
	std::string auds;

	subs += "Subtitles:";
	for (auto i : subTracks_)
		subs += " ", subs += i;

	auds += "Audio Tracks:";
	for (auto i : audioTracks_)
		auds += " ", auds += i;

	s = Material::details() + subs + auds;

	return s;
}