/*
	Media
*/
#include <string>

#include "Media.h"

using std::string;


Media::Media(Project project, string id, string title, string format, string audio, int duration, string language, string price, string aspect, Packaging packaging)
	: Material(project, id, title, format, audio, duration, language, price, aspect, packaging)
{
}
