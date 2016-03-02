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
	Material(Project project_,
		string id_,
		string title_,
		string format_,
		string audio_,
		int duration_,
		string language_,
		string price_,
		string aspect_,
		Packaging packaging_);
		
	Project project_;
	string id_;
	string title_;
	string format_;
	string audio_;
	int duration_;
	string language_;
	string price_;
	string aspect_;
	Packaging packaging_;
};

#endif
