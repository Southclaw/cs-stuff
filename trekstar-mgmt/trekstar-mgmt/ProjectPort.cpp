/*
	ProjectPort
*/
#include <string>
#include <vector>
#include <ctime>

#include "Project.h"
#include "MaterialFactory.h"
#include "ProjectPort.h"

using std::string;
using std::vector;


Project* ProjectPort::ImportProject(string source)
{
	Project* project = nullptr;

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

	// material properties
	string type;
	string id;
	string material_title;
	string format;
	string audio;
	unsigned int material_duration;
	string language;
	string price;
	string aspect;
	Packaging packaging;
	vector<string> subTracks;
	vector<string> audTracks;

	string s2_id = "";
	string s2_title = "";
	string s2_format = "";
	string s2_audio = "";
	int s2_duration = 0;
	string s2_language = "";
	string s2_aspect = "";

	// format markers
	char c = 0; // character in context
	unsigned int s_st = -1; // selection start index
	bool in_function = false;
	bool in_string = false;
	bool in_list = false;
	unsigned int func_idx = 0;
	unsigned int param_idx = 0;

	for(unsigned int i = 0; i < source.size(); ++i, c = source[i])
	{
		//printf("[%c] : %02d - in_function:%d in_string:%d in_list:%d param_idx:%d\n", c, i, in_function, in_string, in_list, param_idx);

		if(in_function)
		{
			if(c == ')')
			{
				if(func_idx > 0)
				{
					// Commit material to project
					if(project == nullptr)
					{
						printf("Error encountered while parsing Project string: project pointer is null");
						return nullptr;
					}

					project->AddMaterial(type, id, material_title, format, audio, material_duration, language, price, aspect, packaging, subTracks, audTracks,
						s2_id, s2_title, s2_format, s2_audio, s2_duration, s2_language, s2_aspect);
				}
				param_idx = 0;
				func_idx++;
				in_function = false;
				continue;
			}
		}

		if(in_string)
		{
			if(c == '\"')
			{
				in_string = false;

				if(func_idx == 0)
				{
					if(in_list)
					{
						//printf("C %d EXTRACTED FOR LIST '%s'\n", param_idx, source.substr(s_st, i - s_st).c_str());

						switch(param_idx)
						{
							case 4: // param 4 = sites list
							sites.push_back(source.substr(s_st, i - s_st));
							break;

							case 7: // param 7 = keywords
							keywords.push_back(source.substr(s_st, i - s_st));
							break;
						}
					}
					else
					{
						//printf("C %d EXTRACTED '%s'\n", param_idx, source.substr(s_st, i - s_st).c_str());

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
							project = new Project(title, summary, genre, release, sites, lang, duration, keywords, wksales, state);
							break;
						}
					}
				}
				else
				{
					if(in_list)
					{
						//printf("M %d EXTRACTED FOR LIST '%s'\n", param_idx, source.substr(s_st, i - s_st).c_str());

						switch(param_idx)
						{
							case 11:
							subTracks.push_back(source.substr(s_st, i - s_st));
							break;

							case 12:
							audTracks.push_back(source.substr(s_st, i - s_st));
							break;
						}
					}
					else
					{
						//printf("M %d EXTRACTED '%s'\n", param_idx, source.substr(s_st, i - s_st).c_str());

						switch(param_idx)
						{
							case 0:
							type = source.substr(s_st, i - s_st);
							break;

							case 1:
							id = source.substr(s_st, i - s_st);
							break;

							case 2:
							material_title = source.substr(s_st, i - s_st);
							break;

							case 3:
							format = source.substr(s_st, i - s_st);
							break;

							case 4:
							audio = source.substr(s_st, i - s_st);
							break;

							case 5:
							material_duration = stoi(source.substr(s_st, i - s_st));
							break;

							case 6:
							language = source.substr(s_st, i - s_st);
							break;

							case 7:
							price = source.substr(s_st, i - s_st);
							break;

							case 8:
							aspect = source.substr(s_st, i - s_st);
							break;

							case 9:
							packaging = source.substr(s_st, i - s_st);
							break;

							case 10:
							s2_id = source.substr(s_st, i - s_st);
							break;

							case 11:
							s2_title = source.substr(s_st, i - s_st);
							break;

							case 12:
							s2_format = source.substr(s_st, i - s_st);
							break;

							case 13:
							s2_audio = source.substr(s_st, i - s_st);
							break;

							case 14:
							s2_duration = stoi(source.substr(s_st, i - s_st));
							break;

							case 15:
							s2_language = source.substr(s_st, i - s_st);
							break;

							case 16:
							s2_aspect = source.substr(s_st, i - s_st);
							break;
						}
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

	return project;

}

string ProjectPort::ExportProject(Project p)
{
	string project;

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

	vector< pair<string, Material*> > materials = p.GetMaterials();

	for(auto m : materials)
	{
		project += "\nMaterial(";

		if(m.first == "vhs")
		{
			Vhs* material = dynamic_cast<Vhs*>(m.second);
			project += _build_param_string("vhs");
		}
		else if(m.first == "dvd")
		{
			Dvd* material = dynamic_cast<Dvd*>(m.second);
			project += _build_param_string("dvd");
		}
		else if(m.first == "ddvd")
		{
			string id;
			string title;
			string format;
			string audio;
			int duration;
			string language;
			string aspect;

			D_Dvd* material = dynamic_cast<D_Dvd*>(m.second);
			material->GetSideTwoData(id, title, format, audio, duration, language, aspect);

			project += _build_param_string("ddvd")+
				_build_param_string(material->GetId())+
				_build_param_string(material->GetTitle())+
				_build_param_string(material->GetFormat())+
				_build_param_string(material->GetAudio())+
				_build_param_string(std::to_string(material->GetDuration()))+
				_build_param_string(material->GetLanguage())+
				_build_param_string(material->GetPrice())+
				_build_param_string(material->GetAspect())+
				_build_param_string(material->GetPackaging().toString())+
				_build_param_string(id)+
				_build_param_string(title)+
				_build_param_string(format)+
				_build_param_string(audio)+
				_build_param_string(std::to_string(duration))+
				_build_param_string(language)+
				_build_param_string(aspect, false) + ")";
		}
		else if(m.first == "bluray")
		{
			Bluray* material = dynamic_cast<Bluray*>(m.second);
			project += _build_param_string("bluray");
		}
		else
		{
			// unknown type
		}

	}

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
