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
	packaging_ = cardboard_vhs;

	subtitles_ = "en_GB";
}

Vhs::~Vhs()
{
}

string Vhs::details()
{
	return Material::details() + subtitles_;
}
