/*
	Test code for logger module.
*/


#include "stdafx.h"
#include <iostream>

#include "Logger.h"


using namespace std;


int main()
{
	Logger log;

	log.level(info);
/*
none
error
warning
info
debug
*/
	log.out(info, "test");

	cout << "Press Enter to close." << endl;
	getchar();

    return 0;
}

