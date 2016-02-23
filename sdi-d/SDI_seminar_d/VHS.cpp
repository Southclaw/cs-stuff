#include <sstream>

#include "VHS.h"


Vhs::Vhs()
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

	subtitles_ = "en_GB";
}

Vhs::~Vhs()
{
}

string Vhs::details()
{
	std::stringstream s;

	s	<< "ID: " << id_ << ", "
		<< "Title: " << title_ << ", "
		<< "Format: " << format_ << ", "
		<< "Audio: " << audio_ << ", "
		<< "Duration: " << duration_ << ", "
		<< "Language: " << language_ << ", "
		<< "Price: " << price_ << ", "
		<< "Subtitles: " << subtitles_ << ", "
		<< "Aspect: " << aspect_ << ", "
		<< "Packaging: " << packaging_;

	return s.str();
}
