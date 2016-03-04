/*
	Testing area
*/
#include <iostream>

#include "Project.h"
#include "Material.h"
#include "Media.h"
#include "Disk.h"
#include "DVD.h"
#include "D_DVD.h"
#include "Bluray.h"
#include "VHS.h"
#include "BoxSet.h"

#include "MaterialPort_JSON.h"
#include "MaterialPort_CSV.h"
#include "SDI_seminar_d.h"

// For lazy typing
using std::cout;
using std::endl;


int main(int argc, char* argv[])
{
	Project project = Project();

	Packaging cardboard_vhs = Packaging("cardboard_vhs");
	Packaging plastic_vhs = Packaging("plastic_vhs");
	Packaging plastic_dvd = Packaging("plastic_dvd");
	Packaging plastic_blu = Packaging("plastic_blu");
	Packaging cardboard_boxset = Packaging("cardboard_boxset");

	Vhs vhs = Vhs(
		project,
		"TW0013",
		"Movie: The Movie",
		"640x480",
		"Mono",
		200,
		"ENG",
		"$15",
		"16x9",
		cardboard_vhs,

		"en_GB");

	Dvd dvd = Dvd(
		project,
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
		project,
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
		{ "en_GB", "jp_JP", "in_IN" });

	Bluray bluray = Bluray(
		project,
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

	BoxSet boxset = BoxSet("Awesome Movie Collection", {bluray, dvd});

	cout << "VHS:    " << vhs.details() << endl;
	cout << "\n\n";

	cout << "DVD:    " << dvd.details() << endl;
	cout << "\n\n";

	cout << "DDVD:   " << ddvd.details() << endl;
	cout << "\n\n";

	cout << "Bluray: " << bluray.details() << endl;
	cout << "\n\n";

	cout << "BoxSet: " << boxset.details() << endl;

	getchar();

	return 0;
}
