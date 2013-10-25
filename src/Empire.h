#pragma once

#include "Nation.h"

class Empire : public ListItem {
};

class Empires : public LinkedList {
public:
 void Save( const char *filename ) {
  string out=toString();
  string_append_file(out.c_str(),filename);
 }
 CLEARLISTRESET(Empire);
};

extern Empires empires;
