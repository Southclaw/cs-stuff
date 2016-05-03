#include <iostream>
#include <string>
#include <utility>
#include <sstream>

#include "Project.h"
#include "Material.h"
#include "Media.h"
#include "Disk.h"
#include "VHS.h"
#include "DVD.h"
#include "D_DVD.h"
#include "Bluray.h"
#include "BoxSet.h"
#include "MaterialFactory.h"
#include "ProjectPort.h"
#include "ProjectManager.h"

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::pair;


void GetCommands(string, vector<string>*);
void testing();

int main(int argc, char* argv[])
{
	//testing();

	ProjectManager pm = ProjectManager();

	string command;
	vector<string> commands;

	while(true)
	{
		cout << "Enter command: ls, mat, find, addp, remp, addm, remm, exit" << endl;
		commands.clear();
		std::getline(std::cin, command);
		GetCommands(command, &commands);

		/*
			todo: process commands

			command list:

				ls - list all projects currently loaded
				mat <project> - list materials associated with a project
				find <query> <type> - search projects by title and media type
				addp <project ctor parameters> - add a new project
				remp <project title> - remove a project
				addm <project title> <material ctor parameters> - add a material
				remm <project title> <material id> - remove a material
				sales <project title> <sales> - set boxoffice sales
				exit - exit the shell
		*/
		if(commands[0] == "ls")
		{
			if(commands.size() != 1)
			{
				cout << "Command takes no parameters" << endl;
				continue;
			}

			cout << "Project list:\n";
			vector<Project*> l = pm.GetProjectList();

			for(Project* i : l)
				cout << "  " << i->GetProjectTitle() << endl;
			cout << "\n";
			continue;
		}

		if(commands[0] == "mat")
		{
			if(commands.size() != 2)
			{
				cout << "Command takes 1 parameter" << endl;
				continue;
			}

			cout << "Materials for " << commands[1] << endl;
			Project* p = pm.GetProjectFromName(commands[1]);

			if(p == nullptr)
			{
				cout << "Project not found!" << endl;
			}
			else
			{
				cout << "Project materials:\n";
				vector< pair<string, Material*> > m = p->GetMaterials();

				for(auto i : m)
					cout << "[" << i.first << "]: " << i.second->details() << endl;
			}

			continue;
		}

		if(commands[0] == "find")
		{
			if(commands.size() != 3)
			{
				cout << "Command takes 2 parameters" << endl;
				continue;
			}

			cout << "Searching for " << commands[1] << endl;
			Project* p = pm.GetProjectFromPartName(commands[1]);

			if(p == nullptr)
			{
				cout << "Project not found!" << endl;
			}
			else
			{
				cout << "Result: " << p->GetProjectTitle();
			}
			
			continue;
		}

		if( commands[0] == "addp")
		{
			if(commands.size() != 1)
			{
				cout << "Command takes 9 parameters" << endl;
				continue;
			}

			continue;
		}

		if(commands[0] == "remp")
		{
			if(commands.size() != 2)
			{
				cout << "Command takes 1 parameters" << endl;
				continue;
			}

			continue;
		}

		if(commands[0] == "addm")
		{
			if(commands.size() != 2)
			{
				cout << "Command takes 9 parameters" << endl;
				continue;
			}

			continue;
		}

		if(commands[0] == "remm")
		{
			if(commands.size() != 2)
			{
				cout << "Command takes 1 parameters" << endl;
				continue;
			}

			continue;
		}

		if(commands[0] == "sales")
		{
			if(commands.size() != 3)
			{
				cout << "Command takes 2 parameters" << endl;
				continue;
			}

			cout << "Setting weekly sales for " << commands[1] << endl;
			Project* p = pm.GetProjectFromName(commands[1]);

			if(p == nullptr)
			{
				cout << "Project not found!" << endl;
			}
			else
			{
				cout << "Set weekly sales for " << commands[1] << endl;
				p->SetBoxOfficeWeeklySales(stoi(commands[2]));
			}

			continue;
		}

		if(commands[0] == "exit")
		{
			break;
		}
	}

	pm.Save();

	getchar();

	return 0;
}

void GetCommands(string s, vector<string>* commands)
{
	std::stringstream command(s);
	string item;

	while(std::getline(command, item, ' '))
		commands->push_back(item);
}

/*
	Testing area
*/

void testing()
{
	vector<string> sites;
	vector<string> keywords;

	sites.push_back("London");
	sites.push_back("Paris");
	sites.push_back("Toronto");

	keywords.push_back("action");
	keywords.push_back("adventure");
	keywords.push_back("family");
	keywords.push_back("fun");

	Packaging cardboard_vhs = Packaging("cardboard_vhs");
	Packaging plastic_vhs = Packaging("plastic_vhs");
	Packaging plastic_dvd = Packaging("plastic_dvd");
	Packaging plastic_blu = Packaging("plastic_blu");
	Packaging cardboard_boxset = Packaging("cardboard_boxset");

	Project project = Project("Movie: The Movie",
		"A breathtaking journey through a movie.",
		"Action Adventure",
		1461342876,
		sites,
		"English",
		200,
		keywords,
		0,
		Project::PROJECT_STATE_PROD);

	project.AddMaterial(
		"vhs",
		"TW0013",
		"Movie: The Movie",
		"640x480",
		"Mono",
		200,
		"ENG",
		"$15",
		"16x9",
		cardboard_vhs,
		{"en_GB"},
		{"en_GB"});


	project.AddMaterial(
		"dvd",
		"TW0181",
		"Movie: The Movie",
		"SD",
		"DTS",
		200,
		"ENG",
		"$20",
		"16x9",
		plastic_dvd,
		{ "en_GB", "jp_JP", "in_IN" },
		{ "en_GB", "jp_JP", "in_IN" });

	project.AddMaterial(
		"ddvd",
		"TW0185",
		"Movie: The Movie With Extras",
		"SD",
		"DTS",
		230,
		"ENG",
		"$30",
		"16x9",
		plastic_dvd,
		{ "en_GB", "jp_JP", "in_IN" },
		{ "en_GB", "jp_JP", "in_IN" },
			"TW0186",
			"Movie: The Movie Extras Side",
			"SD",
			"DTS",
			140,
			"ENG",
			"16x9");

	project.AddMaterial(
		"bluray",
		"TW0220",
		"Movie: The Movie HD",
		"4k",
		"DTS",
		216,
		"ENG",
		"$40",
		"21x9",
		plastic_blu,
		{ "en_GB", "jp_JP", "in_IN" },
		{ "en_GB", "jp_JP", "in_IN" });

	ProjectPort p;

	cout << "\n\nExporting...\n\n";
	string ex = p.ExportProject(project);
	cout << ex << endl;

	cout << "\n\nImporting...\n\n";
	Project* project2 = p.ImportProject(ex);
	cout << "\n\nExporting imported project to string...\n\n";
	ex = p.ExportProject(*project2);
	cout << ex << endl;

	cout << p.ExportProject(project).compare(p.ExportProject(*project2)) << endl;

	getchar();
}
