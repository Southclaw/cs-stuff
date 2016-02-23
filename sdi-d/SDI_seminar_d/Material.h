/*
	Material
*/
#ifndef MATERIAL_H
#define MATERIAL_H

#include <string>
#include <vector>

#include "Project.h"

using std::string;
using std::vector;


class Material
{
public:
	//

protected:
	enum PACKAGING
	{
		PKG_PLASTIC,
		PKG_CARDBOARD
	};

	Project project_;
	string id_;
	string title_;
	string format_;
	string audio_;
	int duration_;
	string language_;
	string price_;
	string aspect_;
	string packaging_;
};

#endif