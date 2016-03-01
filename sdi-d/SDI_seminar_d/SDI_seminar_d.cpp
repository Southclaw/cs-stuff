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

// For lazy typing
using std::cout;
using std::endl;


int main(int argc, char* argv[])
{
	Vhs vhs;
	Dvd dvd;
	D_Dvd ddvd;
	Bluray bluray;

	cout << "VHS:    " << vhs.details() << endl;
	cout << "DVD:    " << dvd.Material::details() << endl;
	cout << "DDVD:   " << ddvd.Material::details() << endl;
	cout << "Bluray: " << bluray.Material::details() << endl;

	getchar();

	return 0;
}
