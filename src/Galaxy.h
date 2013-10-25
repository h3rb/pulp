#pragma once

#include "System.h"

class Dimension;

class Galaxy : public ListItem {
public:
 Zp<Dimension> dimension;
};

class Galaxies : public LinkedList {
public:
 void Save( const char *filename ) {
  string out=toString();
  string_append_file(out.c_str(),filename);
 }
 CLEARLISTRESET(Galaxy);
};

extern Galaxies galaxies;
