#include <sstream>

#include "Dvd.h"


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
	packaging_ = cardboard_vhs;

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
