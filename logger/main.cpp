/*
	Test code for logger module.
*/


#include "stdafx.h"
#include <iostream>

#include "Logger.h"


using namespace std;


int main(int argc, char* argv[])
{
	log_init("test.txt", argc, argv);

	log_lvl(DEBUG_CORE);

	log(DEBUG_CORE) << "test stream 1";
	log(DEBUG_CORE) << "test stream " << (1 + 1);

	d(DEBUG_CORE, "test1");
	df(DEBUG_CORE, "test%d", 2);

	cout << "Press Enter to close." << endl;
	getchar();

    return 0;
}

