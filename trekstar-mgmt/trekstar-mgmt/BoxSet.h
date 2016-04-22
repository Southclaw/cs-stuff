/*
	Box Set
*/
#ifndef BOXSET_H
#define BOXSET_H

#include <string>
#include <vector>
#include <vector>

#include "Media.h"

using std::string;
using std::vector;


class BoxSet
{
public:
	BoxSet(string title, vector<Media*> contents);
	~BoxSet();

	string details();

private:
	string title_;
	vector<Media> contents_;
};

#endif
