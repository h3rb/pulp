#pragma once

#include "Entity.h"

class Scene : public Entity {
public:
};

class Scenes : public LinkedList {
public:
 void Save( const char *filename ) {
  string out=toString();
  string_append_file(out.c_str(),filename);
 }
 CLEARLISTRESET(Scene);
};

extern Scenes scenes;
