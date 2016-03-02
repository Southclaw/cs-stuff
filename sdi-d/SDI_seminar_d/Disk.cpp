#include "Disk.h"


Disk::Disk(Project project, string id, string title, string format, string audio, int duration, string language, string price, string aspect, Packaging packaging)
	: Media(project, id, title, format, audio, duration, language, price, aspect, packaging)
{
	id_ = id;
	title_ = title;
	format_ = format;
	audio_ = audio;
	duration_ = duration;
	language_ = language;
	price_ = price;
	aspect_ = aspect;
	packaging_ = packaging;

	subTracks_.push_back("en_GB");
	subTracks_.push_back("jp_JP");
	subTracks_.push_back("in_IN");
	audioTracks_.push_back("en_GB");
	audioTracks_.push_back("jp_JP");
	audioTracks_.push_back("in_IN");
}

Disk::~Disk()
{
}

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