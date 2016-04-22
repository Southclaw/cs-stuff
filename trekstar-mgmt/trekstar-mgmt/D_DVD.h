/*
	Double Sided DVD
*/
#ifndef D_DVD_H
#define D_DVD_H

#include <string>
#include <vector>

#include "Disk.h"
#include "Dvd.h"

using std::string;
using std::vector;


class D_Dvd : public Disk
{
public:
	D_Dvd(string id, string title, string format, string audio, int duration, string language, string price, string aspect, Packaging packaging, vector<string> subTracks, vector<string> audTracks);
	~D_Dvd();

	string details();

	D_Dvd& sideTwo(string id, string title, string format, string audio, int duration, string language, string aspect, vector<string> subTracks, vector<string> audTracks);

private:
	/*
	The plan was:
	Dvd sideTwo_;
	for the second side.
	But the compiler insists on  no appropriate default constructor despite using
	the ctor initialisation-list feature (compiler bug or oversight? it was cited
	as the solution to this design issue by many people but doesn't appear to work
	on my particular compiler.

	Slow way it is then:
	*/

	// Member data for Double Sided DVD side two:
	string id_;
	string title_;
	string format_;
	string audio_;
	int duration_;
	string language_;
	string aspect_;
};

#endif
