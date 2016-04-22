/*
	The Project Port Class is a bridge between runtime objects and portable data
	format. This Port Class is a CSV variant which handles importing and
	exporting of Material data via CSV format strings.
*/
#ifndef PROJECT_PORT_H
#define PROJECT_PORT_H

#include <string>

#include "Material.h"

using std::string;


class ProjectPort
{
public:
	// Imports material data from CSV format source string (loaded from file/web)
	Material importMaterial(string source);
	// Generates a CSV format string from a Material object ready for file/web
	string exportMaterial(Material source);

private:
	// Internal function to collect data about a Material object
	string collate();
};

#endif
