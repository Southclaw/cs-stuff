/*
	Box Set
*/
#include <string>
#include <vector>

#include "BoxSet.h"

using std::string;
using std::vector;


BoxSet::BoxSet(string title, vector<Media*> contents)
{
	title_ = title;
/*
	for(auto i : contents)
	{
		contents_.push_back(i);
	}
	*/
}

BoxSet::~BoxSet()
{
}

string BoxSet::details()
{
	string s;

	s = "BoxSet:" + title_;
	/*
	for (auto i : contents_)
		s += " ", s += i.details();
	*/
	return s;
}
