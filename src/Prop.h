#pragma once

#include "Entity.h"

class Props;

class Prop : public Entity {
public:
 Zp<Prototype> source;
};

class Props : public LinkedList {
public:
 void Save( const char *filename ) {
  string out=toString();
  string_append_file(out.c_str(),filename);
 }
 CLEARLISTRESET(Prop);
};

extern Props props;
