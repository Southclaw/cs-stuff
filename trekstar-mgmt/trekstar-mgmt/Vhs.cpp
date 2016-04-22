#include <sstream>

#include "Vhs.h"


Vhs::Vhs(Project project, string id, string title, string format, string audio, int duration, string language, string price, string aspect, Packaging packaging, string subtitles = "", string dubbed = "")
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

	dubbed_ = dubbed;
	subtitles_ = subtitles;
}

Vhs::~Vhs()
{
}

string Vhs::details()
{
	return Material::details() + " " + subtitles_;
}

string Vhs::getDubbedLanguage()
{
	return dubbed_;
}

string Vhs::getSubtitles()
{
	return subtitles_;
}

bool Vhs::hasSubtitles()
{
	return !subtitles_.empty();
}
