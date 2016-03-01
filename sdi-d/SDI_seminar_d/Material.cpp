#include <sstream>

#include "Material.h"


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
		<< "Packaging: " << packaging_;

	return s.str();
}
