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
	/*
	Materials Vector stores Material type pointers which are dynamic_cast'd up
	to the Material superclass on creation (which happens in the MaterialFactory
	then, are cast down to subclasses on usage. Knowing what class to downcast
	to could have been done automatically but the advantages in this context
	seem negligible so the Material vector actually stores pairs where the first
	element is a string to denote the type of the Material stored in the second.
	*/
	bool AddMaterial(string type, string id, string title, string format, string audio, int duration, string language, string price, string aspect, Packaging packaging, initializer_list<string> subTracks, initializer_list<string> audTracks);

	/*
	Returns a copy of the Material list for a project. The pair format mentioned
	above is retained so dynamic_cast is required to downcast the Material* to a
	derived type using a check on the first element to get the type.
	*/
	vector< pair< string, Material* > > GetMaterials();

	/*
	This function is restricted to only be usable after the movie release date.
	Such a check is done by comparing the system epoch to the release timestamp
	ergo said restriction could be circumnavigated by adjusting the system time.
	The only logical solution for this would be to initiate a secure socket
	connection to a timeserver and perform the check using that data instead.
	*/
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

	double GetReleaseDateDifference
};

#endif