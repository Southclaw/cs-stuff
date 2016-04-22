/*
	ProjectPort
*/
#include <string>
#include <ctime>

#include "Project.h"
#include "MaterialFactory.h"
#include "ProjectPort.h"

using std::string;
using std::vector;
using std::pair;
using std::initializer_list;


Project ProjectPort::ImportProject(string source)
{
	// project properties
	string title;
	string summary;
	string genre;
	time_t release = 0;
	vector<string> sites;
	string lang;
	unsigned int duration = 0;
	vector<string> keywords;
	unsigned int wksales = 0;
	Project::E_PROJECT_STATE state = Project::PROJECT_STATE_PROD;

	// format markers
	char c = 0; // character in context
	unsigned int s_st = -1; // selection start index
	bool in_function = false;
	bool in_string = false;
	bool in_list = false;
	unsigned int param_idx = 0;

	for(unsigned int i = 0; i < source.size(); ++i, c = source[i])
	{
		//printf("[%c] : %02d - in_function:%d in_string:%d in_list:%d param_idx:%d\n", c, i, in_function, in_string, in_list, param_idx);

		if(in_function)
		{
			if(c == ')')
			{
				in_function = false;
				continue;
			}
		}

		if(in_string)
		{
			if(c == '\"')
			{
				in_string = false;

				if(in_list)
				{
					printf("%d EXTRACTED FOR LIST '%s'\n", param_idx, source.substr(s_st, i - s_st).c_str());

					switch(param_idx)
					{
					case 4: // param 4 = sites list
					{
						sites.push_back(source.substr(s_st, i - s_st));
						break;
					}
					case 7: // param 7 = keywords
					{
						keywords.push_back(source.substr(s_st, i - s_st));
						break;
					}
					}
				}
				else
				{
					printf("%d EXTRACTED '%s'\n", param_idx, source.substr(s_st, i - s_st).c_str());

					switch(param_idx)
					{
					case 0:
						title = source.substr(s_st, i - s_st);
						break;

					case 1:
						summary = source.substr(s_st, i - s_st);
						break;

					case 2:
						genre = source.substr(s_st, i - s_st);
						break;

					case 3:
						release = stoi(source.substr(s_st, i - s_st));
						break;

					case 5:
						lang = source.substr(s_st, i - s_st);
						break;

					case 6:
						duration = stoi(source.substr(s_st, i - s_st));
						break;

					case 8:
						wksales = stoi(source.substr(s_st, i - s_st));
						break;

					case 9:
						state = (Project::E_PROJECT_STATE)stoi(source.substr(s_st, i - s_st));
						break;
					}
				}
				continue;
			}
		}

		if(in_list)
		{
			if(c == ']')
			{
				in_list = false;
				continue;
			}
		}

		if(c == '(')
		{
			in_function = true;
			continue;
		}

		if(c == '\"')
		{
			in_string = true;
			s_st = i + 1;
			continue;
		}

		if(c == '[')
		{
			in_list = true;
			continue;
		}

		if(c == ',' && in_function && !in_string && !in_list)
		{
			param_idx++;
		}
	}

	return Project(title, summary, genre, release, sites, lang, duration, keywords, wksales, state);

}

string ProjectPort::ExportProject(Project p)
{
	string project;
	vector<string> materials;

	project = "Project("+
		_build_param_string(p.GetProjectTitle()) +
		_build_param_string(p.GetProjectSummary()) +
		_build_param_string(p.GetProjectGenre()) +
		_build_param_string(std::to_string(p.GetProjectRelease())) +
		_build_param_vector(p.GetProjectFilmingSites()) +
		_build_param_string(p.GetProjectPrimaryLanguage()) +
		_build_param_string(std::to_string(p.GetProjectDuration())) +
		_build_param_vector(p.GetProjectKeywords()) +
		_build_param_string(std::to_string(p.GetProjectWeeklySales())) +
		_build_param_string(std::to_string(p.GetProjectState()), false) + ")";

	return project;
}

string ProjectPort::_build_param_string(string s, bool comma)
{
	if(comma)
		return "\"" + s + "\", ";
	else
		return "\"" + s + "\"";
}

string ProjectPort::_build_param_vector(vector<string> v, bool comma)
{
	string output;
	bool delimiter = false;

	output = "[";
	for(string s : v)
	{
		if(delimiter)
		{
			output += ", ";
		}

		delimiter = true;

		output += "\"" + s + "\"";
	}

	if(comma)
		output += "], ";
	else
		output += "]";

	return output;
}
