#include "Recipe.h"

#include "Material.h"
#include "Prototype.h"
#include "Genetics.h"
#include "Blueprint.h"

Ingredient::Ingredient( Material *m, double quantity ) : ListItem() {
 material=m;
 this->quantity=quantity;
}

Ingredient::Ingredient( Prototype *p, double quantity ) : ListItem() {
 tr.Set(p);
 this->quantity=quantity;
}

Ingredient::Ingredient( Genetics *g, double quantity ) : ListItem() {
 tr.Set(g);
 this->quantity=quantity;
}

Ingredient::Ingredient( Blueprint *b, double quantity ) : ListItem() {
 tr.Set(b);
 this->quantity=quantity;
}

Ingredient::Ingredient( Material *m, double quantity, Ingredients *substitutes ) : ListItem() {
 material=m;
 this->quantity=quantity;
 this->substitutes=substitutes;
}

Ingredient::Ingredient( Prototype *p, double quantity, Ingredients *substitutes ) : ListItem() {
 tr.Set(p);
 this->quantity=quantity;
 this->substitutes=substitutes;
}

Ingredient::Ingredient( Genetics *g, double quantity, Ingredients *substitutes ) : ListItem() {
 tr.Set(g);
 this->quantity=quantity;
 this->substitutes=substitutes;
}

Ingredient::Ingredient( Blueprint *b, double quantity, Ingredients *substitutes ) : ListItem() {
 tr.Set(b);
 this->quantity=quantity;
 this->substitutes=substitutes;
}

Ingredient::Ingredient( Material *m, double quantity ) : ListItem() {
 material=m;
 this->quantity=quantity;
}

Ingredient( Material *m, double quantity, Ingredients *substitutes ) : ListItem() {
 material=m;
 this->quantity=quantity;
 this->substitutes=substitutes;
}

Ingredient *Ingredients::find( Material *m ) {
 FOREACH(Ingredient,i) if ( i->material == m ) return i;
 return null;
}

Ingredient *Ingredients::find( Prototype *p ) {
 FOREACH(Ingredient,i) if ( i->tr.references(p) ) return i;
}

Ingredient *Ingredients::find( Genetics *g ) {
 FOREACH(Ingredient,i) if ( i->tr.references(g) ) return i;
}

Ingredient *Ingredients::find( Blueprint *b ) {
 FOREACH(Ingredient,i) if ( i->tr.references(b) ) return i;
}

void Ingredients::Set( Material *m, double quantity ) {
 Ingredient *i=find(m);
 if ( i ) i->quantity=quantity;
 else Append(new Ingredient(m,quantity));
}

void Ingredients::Set( Prototype *p, double quantity ) {
 Ingredient *i=find(p);
 if ( i ) i->quantity=quantity;
 else Append(new Ingredient(p,quantity));
}

void Ingredients::Set( Genetics *g, double quantity ) {
 Ingredient *i=find(g);
 if ( i ) i->quantity=quantity;
 else Append(new Ingredient(g,quantity));
}

void Ingredients::Set( Blueprint *b, double quantity ) {
 Ingredient *i=find(b);
 if ( i ) i->quantity=quantity;
 else Append(new Ingredient(b,quantity));
}

void Ingredients::Add( Material *m, double quantity ) {
 Ingredient *i=find(m);
 if ( i ) i->quantity+=quantity;
 else Append(new Ingredient(m,quantity));
}

void Ingredients::Add( Prototype *p, double quantity ) {
 Ingredient *i=find(p);
 if ( i ) i->quantity+=quantity;
 else Append(new Ingredient(p,quantity));
}

void Ingredients::Add( Genetics *g, double quantity ) {
 Ingredient *i=find(g);
 if ( i ) i->quantity+=quantity;
 else Append(new Ingredient(g,quantity));
}

void Ingredients::Add( Blueprint *b, double quantity ) {
 Ingredient *i=find(b);
 if ( i ) i->quantity+=quantity;
 else Append(new Ingredient(b,quantity));
}

void Ingredients::Set( Material *m, double quantity, Ingredients *substitutions ) {
 Ingredient *i=find(m);
 if ( i ) { i->quantity=quantity; i->substititions=substitutions; }
 else Append(new Ingredient(m,quantity,substitutions));
}

void Ingredients::Set( Prototype *p, double quantity, Ingredients *substitutions ) {
 Ingredient *i=find(p);
 if ( i ) { i->quantity=quantity; i->substititions=substitutions; }
 else Append(new Ingredient(m,quantity,substitutions));
}

void Ingredients::Set( Genetics *g, double quantity, Ingredients *substitutions ) {
 Ingredient *i=find(g);
 if ( i ) { i->quantity=quantity; i->substititions=substitutions; }
 else Append(new Ingredient(m,quantity,substitutions));
}

void Ingredients::Set( Blueprint *b, double quantity, Ingredients *substitutions ) {
 Ingredient *i=find(b);
 if ( i ) { i->quantity=quantity; i->substititions=substitutions; }
 else Append(new Ingredient(m,quantity,substitutions));
}

void Ingredients::Add( Material *m, double quantity, Ingredients *substititions ) {
 Ingredient *i=find(m);
 if ( i ) { i->quantity=quantity; i->substititions=substitutions; }
 else Append(new Ingredient(m,quantity,substitutions));
}

void Ingredients::Add( Prototype *p, double quantity, Ingredients *substitions ) {
 Ingredient *i=find(p);
 if ( i ) { i->quantity=quantity; i->substititions=substitutions; }
 else Append(new Ingredient(m,quantity,substitutions));
}

void Ingredients::Add( Genetics *g, double quantity, Ingredients *substitutions ) {
 Ingredient *i=find(g);
 if ( i ) { i->quantity=quantity; i->substititions=substitutions; }
 else Append(new Ingredient(m,quantity,substitutions));
}

void Ingredients::Add( Blueprint *b, double quantity, Ingredients *substitutions ) {
 Ingredient *i=find(b);
 if ( i ) { i->quantity=quantity; i->substititions=substitutions; }
 else Append(new Ingredient(m,quantity,substitutions));
}

void Ingredients::Remove( Material *m ) {
 Ingredient *i=find(m);
 if ( i ) {
  Remove(i);
  delete i;
 }
}

void Ingredients::Remove( Prototype *p ) {
 Ingredient *i=find(m);
 if ( i ) {
  Remove(i);
  delete i;
 }
}

void Ingredients::Remove( Genetics *g ) {
 Ingredient *i=find(g);
 if ( i ) {
  Remove(i);
  delete i;
 }
}

void Ingredients::Remove( Blueprint *b ) {
 Ingredient *i=find(b);
 if ( i ) {
  Remove(i);
  delete i;
 }
}

void Recipe::Set( Material *m, double quantity ) { 
 ingredients.Set(m,quantity);
}

void Recipe::Set( Material *m, double quantity, Ingredients *substitutes ) { 
 ingredients.Set(m,quantity,substitutes);
}

void Recipe::Add( Material *m, double quantity ) {
 ingredients.Add(m,quantity);
}

void Recipe::Add( Material *m, double quantity, Ingredients *substitutes ) {
 ingredients.Add(m,quantity,substitutes);
}

void Recipe::Set( Prototype *p, double quantity ) {
 ingredients.Set(p,quantity);
}

void Recipe::Set( Prototype *p, double quantity, Ingredients *substitutes ) {
 ingredients.Set(p,quantity,substitutes);
}

void Recipe::Add( Prototype *p, double quantity ) {
 ingredients.Add(p,quantity);
}

void Recipe::Add( Prototype *p, double quantity, Ingredients *substitutes ) {
 ingredients.Add(p,quantity,substitutes);
}

void Recipe::Set( Genetics *g, double quantity ) {
 ingredients.Set(g,quantity);
}

void Recipe::Set( Genetics *g, double quantity, Ingredients *substitutes ) {
 ingredients.Set(g,quantity,substitutes);
}

void Recipe::Add( Genetics *g, double quantity ) {
 ingredients.Add(g,quantity);
}

void Recipe::Add( Genetics *g, double quantity, Ingredients *substitutes ) {
 ingredients.Add(g,quantity,substitutes);
}

void Recipe::Set( Blueprint *b, double quantity ) {
 ingredients.Set(b,quantity);
}

void Recipe::Set( Blueprint *b, double quantity, Ingredients *substitutes ) {
 ingredients.Set(b,quantity,substitutes);
}

void Recipe::Add( Blueprint *b, double quantity ) {
 ingredients.Add(b,quantity);
}

void Recipe::Add( Blueprint *b, double quantity, Ingredients *substitutes ) {
 ingredients.Add(b,quantity,substitutes);
}

void Recipe::Remove( Material *m ) {
 ingredients.Remove(m);
}

void Recipe::Remove( Prototype *p ) {
 ingredients.Remove(p);
}

void Recipe::Remove( Genetics *g ) {
 ingredients.Remove(g);
}

void Recipe::Remove( Blueprint *b ) {
 ingredients.Remove(b);
}
