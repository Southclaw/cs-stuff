#include <sstream>

#include "DVD.h"


Dvd::Dvd()
{
	id_ = "TW0185";
	title_ = "Movie: The Movie";
	format_ = "4k";
	audio_ = "DTS";
	duration_ = 86400;
	language_ = "ENG";
	price_ = "$20";
	aspect_ = "21x9";
	packaging_ = PKG_PLASTIC;

	subTracks_.push_back("en_GB");
	subTracks_.push_back("jp_JP");
	subTracks_.push_back("in_IN");
	audioTracks_.push_back("en_GB");
	audioTracks_.push_back("jp_JP");
	audioTracks_.push_back("in_IN");
}

Dvd::~Dvd()
{
}

std::string Dvd::details()
{
	std::stringstream s;
	std::string subs;
	std::string auds;

	subs += "Subtitles:";
	for (auto i : subTracks_)
		subs += " ", subs += i;

	auds += "Audio Tracks:";
	for (auto i : audioTracks_)
		auds += " ", auds += i;

	s	<< "ID: " << id_ << ", "
		<< "Title: " << title_ << ", "
		<< "Format: " << format_ << ", "
		<< "Audio: " << audio_ << ", "
		<< "Duration: " << duration_ << ", "
		<< "Language: " << language_ << ", "
		<< "Price: " << price_ << ", "
		<< subs << ", "
		<< auds << ", "
		<< "Aspect: " << aspect_ << ", "
		<< "Packaging: " << packaging_;

	return s.str();
}
