#include <iostream>
#include <utility>

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

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::pair;


void testing();

int main(int argc, char* argv[])
{
	Project project = Project();

	Packaging cardboard_vhs = Packaging("cardboard_vhs");
	Packaging plastic_vhs = Packaging("plastic_vhs");
	Packaging plastic_dvd = Packaging("plastic_dvd");
	Packaging plastic_blu = Packaging("plastic_blu");
	Packaging cardboard_boxset = Packaging("cardboard_boxset");


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

	vector< pair<string, Material*> > m = project.GetMaterials();

	

	for(auto i : m)
	{
		if(i.first == "vhs")
		{
			cout << "vhs:" << dynamic_cast<Vhs*>(i.second)->details() << endl;
		}
		else if(i.first == "dvd")
		{
			cout << "dvd:" << dynamic_cast<Dvd*>(i.second)->details() << endl;
		}

	}

	getchar();

	return 0;
}

/*
	Testing area
*/

void testing()
{
	Project project = Project();

	Packaging cardboard_vhs = Packaging("cardboard_vhs");
	Packaging plastic_vhs = Packaging("plastic_vhs");
	Packaging plastic_dvd = Packaging("plastic_dvd");
	Packaging plastic_blu = Packaging("plastic_blu");
	Packaging cardboard_boxset = Packaging("cardboard_boxset");

	Vhs vhs = Vhs(
		"TW0013",
		"Movie: The Movie",
		"640x480",
		"Mono",
		200,
		"ENG",
		"$15",
		"16x9",
		cardboard_vhs,

		"en_GB",
		"en_GB");

	Dvd dvd = Dvd(
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

	D_Dvd ddvd = D_Dvd(
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
		{ "en_GB", "jp_JP", "in_IN" }).sideTwo(
			"TW0185",
			"Movie: The Movie Extras Side",
			"SD",
			"DTS",
			140,
			"ENG",
			"16x9",
			{ "en_GB", "jp_JP", "in_IN" },
			{ "en_GB", "jp_JP", "in_IN" });

	Bluray bluray = Bluray(
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

	BoxSet boxset = BoxSet("Awesome Movie Collection", {&bluray, &dvd});

	cout << "VHS:    " << vhs.details() << endl;
	cout << "\n\n";

	cout << "DVD:    " << dvd.details() << endl;
	cout << "\n\n";

	cout << "DDVD:   " << ddvd.details() << endl;
	cout << "\n\n";

	cout << "Bluray: " << bluray.details() << endl;
	cout << "\n\n";

	cout << "BoxSet: " << boxset.details() << endl;
	cout << "\n\n";

	MaterialFactory f;

	Dvd* dvd2 = dynamic_cast<Dvd*>(f.CreateMaterial("dvd",
		"TW0260",
		"Factory Movie",
		"1080p",
		"DTS",
		216,
		"ENG",
		"$40",
		"21x9",
		plastic_dvd,
		{ "en_GB", "jp_JP", "in_IN" },
		{ "en_GB", "jp_JP", "in_IN" }));

	cout << dvd2->details();

	getchar();
}