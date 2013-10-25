#pragma once

#include "Template.h"
#include "Material.h"

class Geology : public Template {
public:
 Zstring tile;
 MaterialRarities materials;
 string toString() {
  string out=templateToString();
  string _tile=string(str_protect(tile.c_str()));
  out += string("tile ")+_tile
   +string("\nrarities {\n")+materials.toString()+string("\n}\n");
  return out;
 }
 void fromString( const char *s ) {
  const char *p=s;
  string value;
  while ( *p != '\0' ) {
   if ( !templateFromString(p,&p) ) {
    p=string_argument(p,&value);
    if ( !str_cmp(value.c_str(),"tile") ) {
     p=string_argument(p,&value);
     tile=value;
    } else if ( !str_cmp(value.c_str(),"materials") ) {
     p=string_argument(p,&value);
     materials.fromString(value.c_str());
    } else {
     OUTPUT("Invalid key: %s\n", value.c_str() );
    }
   }
  }
 }
};

class Geologies : public LinkedList {
public:
 string toString() {
  string out=string("");
  FOREACH(Geology,g) out+=string("geology {\n")+g->toString()+string("\n}\n");
  return out;
 }
 void AppendFromString( string one ) {
  Geology *g=new Geology;
  g->fromString(one.c_str());
  Append(g);
 }
 void Save( const char *filename ) {
  string out=toString();
  string_append_file(out.c_str(),filename);
 }
 CLEARLISTRESET(Geology);
};

extern Geologies geologies;
