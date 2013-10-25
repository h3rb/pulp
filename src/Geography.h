#pragma once

#include "ListItem.h"
#include "Indexed.h"
#include "Geology.h"
#include "Entity.h"
#include "Weather.h"

class Geography : public Entity {
public:
 Indexed<Geology> map;
};

class Geographies : public LinkedList {
public:
 void Save( const char *filename ) {
  string out=toString();
  string_append_file(out.c_str(),filename);
 }
 CLEARLISTRESET(Geography);
};

extern Geographies geographies;
