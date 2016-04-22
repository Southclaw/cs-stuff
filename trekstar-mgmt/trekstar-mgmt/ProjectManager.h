/*
	Material
*/
#ifndef PROJECT_MANAGER_H
#define PROJECT_MANAGER_H

#include <string>
#include <vector>

#include "Project.h"
#include "ProjectPort.h"

using std::string;
using std::vector;


class ProjectManager
{
public:
	ProjectManager();
	~ProjectManager();

	void Save();

private:
	ProjectPort pp_;
	vector<Project> projects_;
};

#endif
