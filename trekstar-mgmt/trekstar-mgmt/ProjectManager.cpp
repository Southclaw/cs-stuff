/*
	ProjectManager
*/
#include <string>
#include <vector>
#include <direct.h>
#include <fstream>
#include <streambuf>
#include <sstream>

#include "Project.h"
#include "ProjectPort.h"
#include "ProjectManager.h"
#include "dirent.h"

using std::string;
using std::vector;
using std::ifstream;
using std::stringstream;


ProjectManager::ProjectManager()
{
	pp_ = ProjectPort();

	_mkdir("data");

	DIR* dir = opendir("data");
	struct dirent *ent;
	string filename;

	ifstream ifs;
	stringstream buffer;
	string buffer_string;
	Project* project;

	while((ent = readdir(dir)) != NULL)
	{
		if(strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0)
			continue;

		filename = "./data/";
		filename += ent->d_name;

		printf("Reading file '%s'...\n", filename.c_str());
		ifs = ifstream(filename);

		if(!ifs.is_open())
		{
			printf("ERROR: Could not read file\n");
			continue;
		}
		buffer << ifs.rdbuf();
		buffer_string = buffer.str();
		project = pp_.ImportProject(buffer_string);
		printf("Loaded project '%s'\n", project->GetProjectTitle().c_str());
		projects_.push_back(*project);
	}

}

ProjectManager::~ProjectManager()
{
}

void ProjectManager::Save()
{
	for(auto p : projects_)
	{
		//
	}
}
