/*
	Material Factory
*/
#include <string>
#include <memory>
#include <vector>

#include "Project.h"
#include "Material.h"
#include "Media.h"
#include "Disk.h"

#include "VHS.h"
#include "DVD.h"
#include "D_DVD.h"
#include "Bluray.h"
#include "MaterialFactory.h"

using std::string;
using std::unique_ptr;
using std::vector;


Media* MaterialFactory::CreateMaterial(string type, string id, string title, string format, string audio, int duration, string language, string price, string aspect, Packaging packaging, vector<string> subTracks = vector<string>(), vector<string> audTracks = vector<string>())
{
	if(type == "vhs")
	{
		string sub;
		string dub;

		if(subTracks.size() == 0)
			sub = *subTracks.begin();

		if(audTracks.size() == 0)
			dub = *audTracks.begin();

		return dynamic_cast<Media*>(new Vhs(id, title, format, audio, duration, language, price, aspect, packaging, sub, dub));
	}

	if (type == "dvd")
	{
		return dynamic_cast<Media*>(new Dvd(id, title, format, audio, duration, language, price, aspect, packaging, subTracks, audTracks));
	}

	if (type == "ddvd")
	{
		return dynamic_cast<Media*>(new D_Dvd(id, title, format, audio, duration, language, price, aspect, packaging, subTracks, audTracks));
	}

	if (type == "bluray")
	{
		return dynamic_cast<Media*>(new Bluray(id, title, format, audio, duration, language, price, aspect, packaging, subTracks, audTracks));
	}

	return nullptr;
}
