/*
	The Material Port Class is a bridge between runtime objects and persistent
	data. This Port Class is a JSON variant which handles importing and exporting
	of Material data via JSON format strings.
*/
#ifndef MATERIAL_PORT_JSON_H
#define MATERIAL_PORT_JSON_H

#include <string>

#include "Material.h"

using std::string;


class MaterialPortJSON
{
public:
	// Imports material data from JSON format source string (loaded from file/web)
	Material importMaterial(string source);
	// Generates a JSON format string from a Material object ready for file/web
	string exportMaterial(Material source);

private:
	// Internal function to collect data about a Material object
	string collate();
};

#endif
