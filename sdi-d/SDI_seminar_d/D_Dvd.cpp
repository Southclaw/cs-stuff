#include "stdafx.h"
#include "D_DVD.h"

D_Dvd::D_Dvd(Project project, string id, string title, string format, string audio, int duration, string language, string price, string aspect, Packaging packaging)
	: Disk(project, id, title, format, audio, duration, language, price, aspect, packaging)
{
}

D_Dvd::~D_Dvd()
{
}
