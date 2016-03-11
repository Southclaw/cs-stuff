/*
	Material Factory
*/
#include <string>
#include <initializer_list>

#include "Project.h"
#include "Material.h"
#include "Media.h"
#include "Disk.h"

#include "VHS.h"
#include "DVD.h"
#include "D_DVD.h"
#include "Bluray.h"
#include "MaterialFactory.h"


std::auto_ptr<Media> MaterialFactory::CreateMaterial(string type, Project project, string id, string title, string format, string audio, int duration, string language, string price, string aspect, Packaging packaging, initializer_list<string> subTracks = initializer_list<string>(), initializer_list<string> audTracks = initializer_list<string>())
{
	if(type == "vhs")
	{
		string sub;
		string dub;

		if(subTracks.size() == 0)
			sub = *subTracks.begin();

		if(audTracks.size() == 0)
			dub = *audTracks.begin();

		return std::auto_ptr<Media>(new Vhs(project, id, title, format, audio, duration, language, price, aspect, packaging, sub, dub));
	}

	if (type == "dvd")
	{
		return std::auto_ptr<Media>(new Dvd(project, id, title, format, audio, duration, language, price, aspect, packaging, subTracks, audTracks));
	}

	if (type == "ddvd")
	{
		return std::auto_ptr<Media>(new D_Dvd(project, id, title, format, audio, duration, language, price, aspect, packaging, subTracks, audTracks));
	}

	if (type == "bluray")
	{
		return std::auto_ptr<Media>(new Bluray(project, id, title, format, audio, duration, language, price, aspect, packaging, subTracks, audTracks));
	}

	return std::auto_ptr<Media>(nullptr);
}
