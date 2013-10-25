#pragma once

#include "Template.h"

#include "Cue.h"

/*
 * The template for a scene
 */

class Blueprint : public Template {
public:
 void fromString( const char *s ) {
  const char *p=s;
  string value;
  while ( *p != '\0' ) {
   if ( !templateFromString(p,&p) ) {
    p=string_argument(p,&value);
   }
  }
 }
 string toString() {
  string out=templateToString();
  return out;
 }
};

class Blueprints : public LinkedList {
public:
 string toString() {
  string out=string("");
  FOREACH(Blueprint,b) out+=string("blueprint {\n")+b->toString()+string("\n}\n");
  return out;
 }
 void AppendFromString( string one ) {
  Blueprint *b=new Blueprint;
  b->fromString(one.c_str());
  Append(b);
 }
 void Save( const char *filename ) {
  string out=toString();
  string_append_file(out.c_str(),filename);
 }
 Blueprint *byId( unsigned int i ) {
  FOREACH(Blueprint,b) if ( b->id.is(i) ) return b;
  return null;
 }
 Blueprint *byId( int i ) {
  FOREACH(Blueprint,b) if ( b->id.is(i) ) return b;
  return null;
 }
 CLEARLISTRESET(Blueprint);
};

extern Blueprints blueprints;
