/*
	Project
*/
#ifndef PROJECT_H
#define PROJECT_H

#include <string>
#include <vector>

using std::string;
using std::vector;


class Project
{
public:
	//

private:
	string title_;
	string summary_;
	string genre_;
	string release_;
	vector<string> sites_;
	string lang_;
	unsigned int duration_;
	vector<string> keywords_;
	unsigned int wksales_;
};

#endif