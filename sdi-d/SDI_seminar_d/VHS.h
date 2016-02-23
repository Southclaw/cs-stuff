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
	Vhs();
	~Vhs();

	string details();

	string getLanguage();
	bool hasSubtitles();

private:
	string language_;
	string subtitles_;
};

#endif
