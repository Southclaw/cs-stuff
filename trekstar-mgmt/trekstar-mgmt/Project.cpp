/*
	Project
*/
#include "Project.h"
#include "MaterialFactory.h"

using std::string;
using std::vector;
using std::pair;
using std::vector;


Project::Project(string title, string summary, string genre, time_t release, vector<string> sites, string lang, unsigned int duration, vector<string> keywords, unsigned int wksales, E_PROJECT_STATE state)
{
	title_ = title;
	summary_ = summary;
	genre_ = genre;
	release_ = release;
	sites_ = sites;
	lang_ = lang;
	duration_ = duration;
	keywords_ = keywords;
	wksales_ = wksales;
	state_ = state;
}

Project::~Project()
{
	//
}

bool Project::AddMaterial(string type, string id, string title, string format, string audio, int duration, string language, string price, string aspect, Packaging packaging, vector<string> subTracks, vector<string> audTracks,
		string s2_id, string s2_title, string s2_format, string s2_audio, int s2_duration, string s2_language, string s2_aspect)
{
	// If the project has gone gold, don't allow material additions.
//	if(GetNowToReleaseDiff() < 0)
//		return true;

	Media* m;
	MaterialFactory mf;
	pair<string, Material*> p;

	if(type == "ddvd")
	{
		m = dynamic_cast<Media*>(mf.CreateMaterial(type, id, title, format, audio, duration, language, price, aspect, packaging, subTracks, audTracks, s2_id, s2_title, s2_format, s2_audio, s2_duration, s2_language, s2_aspect));
	}
	else
	{
		m = dynamic_cast<Media*>(mf.CreateMaterial(type, id, title, format, audio, duration, language, price, aspect, packaging, subTracks, audTracks));
	}

	p.first = type;
	p.second = m;

	materials_.push_back(p);

	return false;
}

vector< pair<string, Material*> > Project::GetMaterials()
{
	return materials_;
}

bool Project::SetBoxOfficeWeeklySales(unsigned int sales)
{
	// If the project hasn't gone gold yet, disallow sales reports.
	if(GetNowToReleaseDiff() >= 0)
	{
		return 1;
	}

	wksales_ = sales;

	return 0;
}

double Project::GetNowToReleaseDiff()
{
	time_t now;
	time(&now);
	return difftime(release_, now);
}

string Project::GetProjectTitle()
{
	return title_;
}

string Project::GetProjectSummary()
{
	return summary_;
}

string Project::GetProjectGenre()
{
	return genre_;
}

time_t Project::GetProjectRelease()
{
	return release_;
}

vector<string> Project::GetProjectFilmingSites()
{
	return sites_;
}

string Project::GetProjectPrimaryLanguage()
{
	return lang_;
}

unsigned int Project::GetProjectDuration()
{
	return duration_;
}

vector<string> Project::GetProjectKeywords()
{
	return keywords_;
}

unsigned int Project::GetProjectWeeklySales()
{
	return wksales_;
}

Project::E_PROJECT_STATE Project::GetProjectState()
{
	return state_;
}

bool Project::SetProjectTitle(string title)
{
	title_ = title;
	return false;
}

bool Project::SetProjectSummary(string summary)
{
	summary_ = summary;
	return false;
}

bool Project::SetProjectGenre(string genre)
{
	genre_ = genre;
	return false;
}

bool Project::SetProjectRelease(time_t release)
{
	release_ = release;
	return false;
}

bool Project::SetProjectFilmingSites(vector<string> sites)
{
	sites_ = sites;
	return false;
}

bool Project::SetProjectPrimaryLanguage(string lang)
{
	lang_ = lang;
	return false;
}

bool Project::SetProjectDuration(unsigned int duration)
{
	duration_ = duration;
	return false;
}

bool Project::SetProjectKeywords(vector<string> keywords)
{
	keywords_ = keywords;
	return false;
}

bool Project::SetProjectWeeklySales(unsigned int wksales)
{
	wksales_ = wksales;
	return false;
}

bool Project::SetProjectState(E_PROJECT_STATE state)
{
	state_ = state;
	return false;
}

