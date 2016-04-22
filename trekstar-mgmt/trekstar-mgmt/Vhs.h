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
	Vhs::Vhs(Project project, string id, string title, string format, string audio, int duration, string language, string price, string aspect, Packaging packaging, string subtitles, string dubbed);
	~Vhs();

	string details();

	string getSubtitles();
	string getDubbedLanguage();
	bool hasSubtitles();

private:
	string subtitles_;
	string dubbed_;
};

#endif
