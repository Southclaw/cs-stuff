/*
	Project
*/
#ifndef PROJECT_H
#define PROJECT_H

#include <string>
#include <vector>
#include <ctime>
#include <utility>
#include <initializer_list>

#include "Material.h"

using std::string;
using std::vector;
using std::pair;
using std::initializer_list;


class Project
{
public:
	bool AddMaterial(string type, string id, string title, string format, string audio, int duration, string language, string price, string aspect, Packaging packaging, initializer_list<string> subTracks, initializer_list<string> audTracks);
	vector< pair< string, Material* > > GetMaterials();

	bool SetBoxOfficeWeeklySales(unsigned int sales);

private:
	string title_;
	string summary_;
	string genre_;
	time_t release_;
	vector<string> sites_;
	string lang_;
	unsigned int duration_;
	vector<string> keywords_;
	unsigned int wksales_;

	vector< pair< string, Material* > > materials_;
};

#endif