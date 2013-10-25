#pragma once

#include "Entity.h"

class Actor : public Entity {
public:
};

class Actors : public LinkedList {
public:
 void Save( const char *filename ) {
  string out=toString();
  string_append_file(out.c_str(),filename);
 }
 CLEARLISTRESET(Actor);
};

extern Actors actors;
