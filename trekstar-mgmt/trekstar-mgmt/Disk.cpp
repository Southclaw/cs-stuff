/*
	Disk
*/
#include <string>
#include <vector>
#include <initializer_list>

#include "Disk.h"

using std::string;
using std::initializer_list;


Disk::Disk(string id, string title, string format, string audio, int duration, string language, string price, string aspect, Packaging packaging, initializer_list<string> subTracks, initializer_list<string> audTracks)
	: Media(id, title, format, audio, duration, language, price, aspect, packaging)
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

	for (auto i : subTracks)
	{
		subTracks_.push_back(i);
	}

	for (auto i : audTracks)
	{
		audioTracks_.push_back(i);
	}
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
	string s;
	string subs;
	string auds;

	subs += " Subtitles:";
	for (auto i : subTracks_)
		subs += " ", subs += i;

	auds += " Audio Tracks:";
	for (auto i : audioTracks_)
		auds += " ", auds += i;

	s = Material::details() + subs + auds;

	return s;
}