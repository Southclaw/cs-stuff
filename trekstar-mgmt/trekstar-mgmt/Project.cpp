/*
	Disk
*/
#include <string>
#include <vector>
#include <ctime>

#include "Project.h"

using std::string;


bool Project::setBoxOfficeWeeklySales(unsigned int sales)
{
	time_t now;
	time(&now);

	if(difftime(release_, now) >= 0)
	{
		return 1;
	}

	wksales_ = sales;

	return 0;
}
