#pragma once

#include "Galaxy.h"

class Dimension : public ListItem {
public:
};

class Dimensions : public LinkedList {
public:
 void Save( const char *filename ) {
  string out=toString();
  string_append_file(out.c_str(),filename);
 }
 CLEARLISTRESET(Dimension);
};

extern Dimensions dimensions;
