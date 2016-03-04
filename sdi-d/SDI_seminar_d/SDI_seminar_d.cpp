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
		"TW0185",
		"Movie: The Movie",
		"4k",
		"DTS",
		86400,
		"ENG",
		"$20",
		"21x9",
		cardboard_vhs,

		"en_GB");

	Dvd dvd = Dvd(
		project,
		"TW0185",
		"Movie: The Movie",
		"4k",
		"DTS",
		86400,
		"ENG",
		"$20",
		"21x9",
		cardboard_vhs,
		{ "en_GB", "jp_JP", "in_IN" },
		{ "en_GB", "jp_JP", "in_IN" });

	D_Dvd ddvd = D_Dvd(
		project,
		"TW0185",
		"Movie: The Movie",
		"4k",
		"DTS",
		86400,
		"ENG",
		"$20",
		"21x9",
		cardboard_vhs,
		{ "en_GB", "jp_JP", "in_IN" },
		{ "en_GB", "jp_JP", "in_IN" });

	Bluray bluray = Bluray(
		project,
		"TW0185",
		"Movie: The Movie",
		"4k",
		"DTS",
		86400,
		"ENG",
		"$20",
		"21x9",
		cardboard_vhs,
		{ "en_GB", "jp_JP", "in_IN" },
		{ "en_GB", "jp_JP", "in_IN" });

	cout << "VHS:    " << vhs.details() << endl;
	cout << "DVD:    " << dvd.Material::details() << endl;
	cout << "DDVD:   " << ddvd.Material::details() << endl;
	cout << "Bluray: " << bluray.Material::details() << endl;

	getchar();

	return 0;
}
