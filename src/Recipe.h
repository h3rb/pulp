#pragma once

#include "LinkedList.h"
#include "TemplateReference.h"

/* Forward declarations */
class Material;
class Prototype;
class Genetics;
class Blueprint;

/* Local forward declarations */
class Ingredients;

class Ingredient : public ListItem {
public:
 Zdouble quantity;
 Zp<Material> material;
 TemplateReference tr;
 Zp<Ingredients> substitutes;
 Ingredient( Material *m, double quantity );
 Ingredient( Prototype *p, double quantity );
 Ingredient( Genetics *g, double quantity );
 Ingredient( Blueprint *b, double quantity );
 Ingredient( Material *m, double quantity, Ingredients *substitutes );
 Ingredient( Prototype *p, double quantity, Ingredients *substitutes );
 Ingredient( Genetics *g, double quantity, Ingredients *substitutes );
 Ingredient( Blueprint *b, double quantity, Ingredients *substitutes );
 void fromString( const char *s ) {
 }
 string toString() {
  return string("");
 }
};

class Ingredients : public LinkedList {
public:
 Zstring name;
 Ingredient *find( Material *m );
 Ingredient *find( Prototype *p );
 Ingredient *find( Genetics *g );
 Ingredient *find( Blueprint *b );
 void Set( Material *m, double quantity );
 void Set( Prototype *p, double quantity );
 void Set( Genetics *g, double quantity );
 void Set( Blueprint *b, double quantity );
 void Add( Material *m, double quantity );
 void Add( Prototype *p, double quantity );
 void Add( Genetics *g, double quantity );
 void Add( Blueprint *b, double quantity );
 void Set( Material *m, double quantity, Ingredients *substitutions );
 void Set( Prototype *p, double quantity, Ingredients *substitutions );
 void Set( Genetics *g, double quantity, Ingredients *substitutions );
 void Set( Blueprint *b, double quantity, Ingredients *substitutions );
 void Add( Material *m, double quantity, Ingredients *substititions );
 void Add( Prototype *p, double quantity, Ingredients *substititions );
 void Add( Genetics *g, double quantity, Ingredients *substititions );
 void Add( Blueprint *b, double quantity, Ingredients *substitutions );
 void Remove( Material *m );
 void Remove( Prototype *p );
 void Remove( Genetics *g );
 void Remove( Blueprint *b );
 CLEARLISTRESET(Ingredient);
};

class Substitutions : public LinkedList {
public:
 Ingredients *find( Ingredients *s ) {
  FOREACH(Ingredients,i) if ( i==s ) return i;
  return null;
 }
 Ingredients *find( const char *name ) {
  FOREACH(Ingredients,i) if ( !str_cmp(i->name.c_str(),name) ) return i;
  return null;
 }
 CLEARLISTRESET(Ingredients);
};

class Recipe {
public:
 Ingredients ingredients;
 Substitutions substitutions;
 void fromString( const char *s ) {
 }
 string toString() {
  return string("");
 }
 void Set( Material *m, double quantity );
 void Set( Material *m, double quantity, Ingredients *substitutes );
 void Add( Material *m, double quantity );
 void Add( Material *m, double quantity, Ingredients *substitutes );
 void Set( Prototype *p, double quantity );
 void Set( Prototype *p, double quantity, Ingredients *substitutes );
 void Add( Prototype *p, double quantity );
 void Add( Prototype *p, double quantity, Ingredients *substitutes );
 void Set( Genetics *g, double quantity );
 void Set( Genetics *g, double quantity, Ingredients *substitutes );
 void Add( Genetics *g, double quantity );
 void Add( Genetics *g, double quantity, Ingredients *substitutes );
 void Set( Blueprint *b, double quantity );
 void Set( Blueprint *b, double quantity, Ingredients *substitutes );
 void Add( Blueprint *b, double quantity );
 void Add( Blueprint *b, double quantity, Ingredients *substitutes );
 void Remove( Material *m );
 void Remove( Prototype *p );
 void Remove( Genetics *g );
 void Remove( Blueprint *b );
 void Add( Ingredients *s ) { substitutions.Append(s); }
 void Remove( const char *s ) {
  Ingredients *found=(substitutions.find(s));
  if ( found ) {
   substitutions.Remove(found);
   delete found;
   found=null;
  }
 }
 void Remove( Ingredients *s ) {
  substitutions.Remove(s);
 }
 void Remove( Ingredients *s, bool confirm ) {
  Ingredients *found=(substitutions.find(s));
  if ( found ) {
   substitutions.Remove(found);
   delete found;
   found=null;
  }
 }
};
