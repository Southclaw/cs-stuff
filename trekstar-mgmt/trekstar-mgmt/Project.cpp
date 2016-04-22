/*
	Disk
*/
#include "Project.h"
#include "MaterialFactory.h"

using std::string;
using std::vector;
using std::pair;
using std::initializer_list;


bool Project::AddMaterial(string type, string id, string title, string format, string audio, int duration, string language, string price, string aspect, Packaging packaging, initializer_list<string> subTracks, initializer_list<string> audTracks)
{
	// If the project has gone gold, don't allow material additions.
	if(GetNowToReleaseDiff() < 0)
		return true;

	MaterialFactory mf;
	pair<string, Material*> p;

	Media* m = dynamic_cast<Media*>(mf.CreateMaterial(type, id, title, format, audio, duration, language, price, aspect, packaging, subTracks, audTracks));

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

