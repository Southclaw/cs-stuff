/*
	Test code for logger module.
*/


#include "stdafx.h"
#include <iostream>

#include "Logger.h"


using namespace std;


int main(int argc, char* argv[])
{
	log_init("log_%Y-%m-%d.txt", argc, argv);

	log_lvl(DEBUG_CORE);

	logs(DEBUG_CORE) << "test stream 1";
	logs(DEBUG_CORE) << "test stream " << (1 + 1);

	logc(DEBUG_CORE, "test1");
	logf(DEBUG_CORE, "test%d", 2);

	cout << "Press Enter to close." << endl;
	getchar();

    return 0;
}

