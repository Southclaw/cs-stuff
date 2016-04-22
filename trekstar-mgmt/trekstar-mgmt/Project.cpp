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
	time_t now;
	time(&now);

	if(difftime(release_, now) >= 0)
	{
		return 1;
	}

	wksales_ = sales;

	return 0;
}
