#pragma once

#include "Planet.h"

class Galaxy;

class System : public ListItem {
public:
 Zp<Galaxy> galaxy;
};

class Systems : public LinkedList {
public:
 void Save( const char *filename ) {
  string out=toString();
  string_append_file(out.c_str(),filename);
 }
 CLEARLISTRESET(System);
};

extern Systems systems;
