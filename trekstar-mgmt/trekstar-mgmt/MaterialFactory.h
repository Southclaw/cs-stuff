/*
	Material Factory
*/
#ifndef MATERIAL_FACTORY_H
#define MATERIAL_FACTORY_H

#include <string>
#include <memory>
#include <vector>

#include "Project.h"
#include "Material.h"
#include "Media.h"
#include "Disk.h"

#include "VHS.h"
#include "DVD.h"
#include "D_DVD.h"
#include "Bluray.h"

using std::string;
using std::unique_ptr;
using std::vector;


class MaterialFactory
{
public:
	Media* CreateMaterial(string type, string id, string title, string format, string audio, int duration, string language, string price, string aspect, Packaging packaging, vector<string> subTracks, vector<string> audTracks);
};

#endif