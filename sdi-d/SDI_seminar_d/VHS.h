/*
	Vhs
*/
#ifndef VHS_H
#define VHS_H

#include <string>
#include "Media.h"

using std::string;


class Vhs : public Media
{
public:
	Vhs::Vhs(Project project, string id, string title, string format, string audio, int duration, string language, string price, string aspect, Packaging packaging, string subtitles);
	~Vhs();

	string details();

	string getLanguage();
	string getSubtitles();
	bool hasSubtitles();

private:
	string language_;
	string subtitles_;
};

#endif
