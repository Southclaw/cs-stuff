/*
	Box Set
*/
#ifndef BOXSET_H
#define BOXSET_H

#include <string>
#include <vector>
#include <initializer_list>

#include "Media.h"

using std::string;
using std::initializer_list;


class BoxSet
{
public:
	BoxSet(string title, initializer_list<Media> contents);
	~BoxSet();

	string details();

private:
	string title_;
	vector<Media> contents_;
};

#endif
