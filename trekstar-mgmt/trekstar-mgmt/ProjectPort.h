/*
	The Project Port Class is a bridge between runtime objects and portable data
	format. Projects are converted to a string representation which can then be
	imported at a later date to reconstruct a project's state.
*/
#ifndef PROJECT_PORT_H
#define PROJECT_PORT_H

#include <string>

#include "Project.h"

using std::string;


class ProjectPort
{
public:
	Project ImportProject(string source);
	string ExportProject(Project source);

private:
	string _build_param_string(string s, bool comma = true);
	string _build_param_vector(vector<string> v, bool comma = true);
};

#endif
