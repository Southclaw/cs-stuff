/*
	Project
*/
#ifndef PROJECT_H
#define PROJECT_H

#include <string>
#include <vector>
#include <ctime>
#include <utility>
#include <vector>

#include "Material.h"

using std::string;
using std::vector;
using std::pair;
using std::vector;


class Project
{
public:

	enum E_PROJECT_STATE
	{
		PROJECT_STATE_PROD,
		PROJECT_STATE_CINE,
		PROJECT_STATE_RELE
	};

	Project(string title, string summary, string genre, time_t release, vector<string> sites, string lang, unsigned int duration, vector<string> keywords, unsigned int wksales, E_PROJECT_STATE state);
	~Project();

	/*
	Materials Vector stores Material type pointers which are dynamic_cast'd up
	to the Material superclass on creation (which happens in the MaterialFactory
	then, are cast down to subclasses on usage. Knowing what class to downcast
	to could have been done automatically but the advantages in this context
	seem negligible so the Material vector actually stores pairs where the first
	element is a string to denote the type of the Material stored in the second.
	*/
	bool AddMaterial(string type, string id, string title, string format, string audio, int duration, string language, string price, string aspect, Packaging packaging, vector<string> subTracks, vector<string> audTracks);

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

	/*
	Generic interface getters
	*/

	string GetProjectTitle();
	string GetProjectSummary();
	string GetProjectGenre();
	time_t GetProjectRelease();
	vector<string> GetProjectFilmingSites();
	string GetProjectPrimaryLanguage();
	unsigned int GetProjectDuration();
	vector<string> GetProjectKeywords();
	unsigned int GetProjectWeeklySales();
	E_PROJECT_STATE GetProjectState();

	/*
	Generic interface setters
	These return boolean values to indicate success (false) however some have no
	failure	branch. Further validation of input can be added in future though.
	*/

	bool SetProjectTitle(string);
	bool SetProjectSummary(string);
	bool SetProjectGenre(string);
	bool SetProjectRelease(time_t);
	bool SetProjectFilmingSites(vector<string>);
	bool SetProjectPrimaryLanguage(string);
	bool SetProjectDuration(unsigned int);
	bool SetProjectKeywords(vector<string>);
	bool SetProjectWeeklySales(unsigned int);
	/*
	Project state refers to whether the project is still in production, running
	in cinemas or being sold on consumable media. Todo: disallow transitioning
	to previous states (a movie can't go from cinema back to production).
	*/
	bool SetProjectState(E_PROJECT_STATE state);


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
	E_PROJECT_STATE state_;

	vector< pair< string, Material* > > materials_;

	double GetNowToReleaseDiff();
};

#endif
