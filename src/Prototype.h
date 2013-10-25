#pragma once

#include "Strings.h"
#include "Template.h"
#include "Material.h"
#include "Recipe.h"
#include "Flag.h"

/*
 * The template for a prop.
 */

class Prototypes;
class Prop;

class Prototype : public Template {
public:
 Strings keywords;
 Zp<Prototypes> parents;
 Zp<NonUniqueReferences> scripts;
 void Embue( Prop *target );
};

class Prototypes : public LinkedList {
public:
 void Save( const char *filename ) {
  string out=toString();
  string_append_file(out.c_str(),filename);
 }
 Prototype *byId( unsigned int i ) {
  FOREACH(Prototype,p) if ( p->id.is(i) ) return p;
  return null;
 }
 Prototype *byId( int i ) {
  FOREACH(Prototype,p) if ( p->id.is(i) ) return p;
  return null;
 }
 CLEARLISTRESET(Prototype);
};

extern Prototypes prototypes;
