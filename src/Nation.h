#pragma once

#include "LinkedList.h"
#include "Currency.h"

class Nation : public ListItem {
public:
 Currencies currencies; // local currency
};

class Nations : public LinkedList {
public:
 void Save( const char *filename ) {
  string out=toString();
  string_append_file(out.c_str(),filename);
 }
 CLEARLISTRESET(Nation);
};

extern Nations nations;
