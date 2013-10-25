#pragma once

#include "Template.h"
#include "Skill.h"

/*
 * The prototype for an actor.
 */

class Genetics : public Template {
public:
 Zstring name,proper;
 String keywords;
 Skills skills;
 Strings nemesis;
 string toString() {
  string _name=string(str_protect(name));
  string _proper=string(str_protect(proper));
  string _keywords=string(str_protect(keywords.s));
  return
   string("name ")+_name
  +string("\nproper ")+_proper
  +string("\nkeywords ")+_keywords
  +string("\nskills {\n")+skills.toString()+string("\n}\n")
  +string("\nnemesis {\n")+nemesis.toString()+string("\n}\n")
  ;
 }
};

class Species : public LinkedList {
public:
 string toString() {
  string out=string("");
  FOREACH(Genetics,g) out+=string("genetics {\n")+g->toString()+string("\n}\n");
  return out;
 }
 void Save( const char *filename ) {
  string out=toString();
  string_append_file(out.c_str(),filename);
 }
 Genetics *byId( unsigned int i ) {
  FOREACH(Genetics,g) if ( g->id.is(i) ) return g;
  return null;
 }
 Genetics *byId( int i ) {
  FOREACH(Genetics,g) if ( g->id.is(i) ) return g;
  return null;
 }
 CLEARLISTRESET(Genetics);
};

extern Species species;
