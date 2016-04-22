/*
	Media
*/
#ifndef MEDIA_H
#define MEDIA_H

#include "Material.h"


class Media : public Material
{
public:
	virtual ~Media(){}
	virtual string details() = 0;

protected:
	Media(string id, string title, string format, string audio, int duration, string language, string price, string aspect, Packaging packaging);
};

#endif
