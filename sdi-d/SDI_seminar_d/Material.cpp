/*
	Material
*/
#include <string>
#include <sstream>

#include "Material.h"

using std::string;


Material::Material(Project project, string id, string title, string format, string audio, int duration, string language, string price, string aspect, Packaging packaging)
{
	project_ = project;
	id_ = id;
	title_ = title;
	format_ = format;
	audio_ = audio;
	duration_ = duration;
	language_ = language;
	price_ = price;
	aspect_ = aspect;
	packaging_ = packaging;
}

std::string Material::details()
{
	std::stringstream s;

	s << "ID: " << id_ << ", "
		<< "Title: " << title_ << ", "
		<< "Format: " << format_ << ", "
		<< "Audio: " << audio_ << ", "
		<< "Duration: " << duration_ << ", "
		<< "Language: " << language_ << ", "
		<< "Price: " << price_ << ", "
		<< "Aspect: " << aspect_ << ", "
		<< "Packaging: " << packaging_.toString();

	return s.str();
}
