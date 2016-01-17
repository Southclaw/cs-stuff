/*
	Test code for logger module.
*/


#include "stdafx.h"
#include <iostream>

#include "Logger.h"


using namespace std;


int main(int argc, char* argv[])
{
	Logger log("test.txt", argc, argv);

	log.level(info);
/*
none
error
warning
info
debug
*/
	log.out(info, "test1");
	log.out(warning, "test2");
	log.out(info, "test3");

	cout << "Press Enter to close." << endl;
	getchar();

    return 0;
}

