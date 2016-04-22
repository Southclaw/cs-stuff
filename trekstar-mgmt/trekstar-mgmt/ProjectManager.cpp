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
using std::ofstream;
using std::endl;
using std::stringstream;


ProjectManager::ProjectManager()
{
	pp_ = ProjectPort();

	_mkdir("data");

	DIR* dir = opendir("data");
	struct dirent *ent;
	string filename;
	int path_delim;
	string projectname;
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
		path_delim = string(ent->d_name).find('.');

		if(path_delim == -1)
			continue;

		projectname = string(ent->d_name).substr(0, path_delim);

		printf("Reading file '%s'...\n", projectname.c_str());
		ifs = ifstream(filename);

		if(!ifs.is_open())
		{
			printf("ERROR: Could not read file\n");
			continue;
		}
		buffer << ifs.rdbuf();
		buffer_string.clear();
		buffer_string = buffer.str();
		project = pp_.ImportProject(buffer_string);

		if(projectname.compare(project->GetProjectTitle()))
		{
			printf("ERROR: Filename ('%s') must match project name ('%s')\n", ent->d_name, projectname.c_str());
			continue;
		}

		printf("Loaded project '%s' with %d materials\n", project->GetProjectTitle().c_str(), project->GetMaterials().size());
		projects_.push_back(*project);
		ifs.close();
	}
}

ProjectManager::~ProjectManager()
{
	Save();
}

void ProjectManager::Save()
{
	string filename;
	ofstream ofs;
	stringstream ss;

	for(auto p : projects_)
	{
		filename = "./data/" + p.GetProjectTitle() + ".txt";
		ofs = ofstream(filename);

		if(!ofs.is_open())
		{
			printf("ERROR: Could not open file for writing\n");
			continue;
		}

		ofs << pp_.ExportProject(p) << endl;
		ofs.close();
	}
}
