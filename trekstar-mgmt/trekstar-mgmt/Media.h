/*
	Media
*/
#ifndef MEDIA_H
#define MEDIA_H

#include "Material.h"


class Media : public Material
{
protected:
	Media(Project project, string id, string title, string format, string audio, int duration, string language, string price, string aspect, Packaging packaging);
};

#endif
