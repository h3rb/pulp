#pragma once

#include "LinkedList.h"

class System;

class Planet : public ListItem {
public:
 Zp<System> system;
};

class Planets : public LinkedList {
public:
 void Save( const char *filename ) {
  string out=toString();
  string_append_file(out.c_str(),filename);
 }
 CLEARLISTRESET(Planet);
};

extern Planets planets;
