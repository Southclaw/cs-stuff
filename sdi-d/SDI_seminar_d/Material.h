/*
	Material
*/
#ifndef MATERIAL_H
#define MATERIAL_H

#include <string>
#include <vector>

#include "Project.h"
#include "Packaging.h"

using std::string;
using std::vector;


class Material
{
public:
	string details();

protected:
	Packaging cardboard_vhs("cardboard_vhs");
	Packaging plastic_vhs("plastic_vhs");
	Packaging plastic_dvd("plastic_dvd");
	Packaging plastic_blu("plastic_blu");
	Packaging cardboard_boxset("cardboard_boxset");

	Project project_;
	string id_;
	string title_;
	string format_;
	string audio_;
	int duration_;
	string language_;
	string price_;
	string aspect_;
	t_package packaging_;
};

#endif