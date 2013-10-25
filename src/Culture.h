#pragma once
#include "LinkedList.h"
#include "Template.h"

class Culture : public Template {
public:
};

class Cultures : public LinkedList {
public:
 void Save( const char *filename ) {
  string out=toString();
  string_append_file(out.c_str(),filename);
 }
 CLEARLISTRESET(Culture);
};

extern Cultures cultures;
