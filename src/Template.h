#pragma once

#include "ListItem.h"
#include "Unique.h"
#include "Flag.h"
#include "Strings.h"
#include "Recipe.h"

class Entity;
class Templates;

class Template : public ListItem {
public:
 Unique id;
 Zp<Templates> list;
 Recipe recipe;
 Flags flags;
 Strings values;
 Zstring noun,plural,detail;
 Template() : ListItem() {}
 Template( Template *t ) : ListItem() {
  Clone(t);
 }
 string templateToString() {
  string out=string("");
  out+=string("id ")+id.toString();
  out+=string("recipe {\n")+recipe.toString()+string("\n}\n");
  out+=string("flags {\n")+flags.toString()+string("\n}\n");
  out+=string("values {\n")+values.toString()+string("\n}\n");
  string _noun=string(str_protect(noun.c_str()));
  string _plural=string(str_protect(plural.c_str()));
  string _detail=string(str_protect(plural.c_str()));
  out+=string("noun ")+_noun+string("\n");
  out+=string("plural ")+_plural+string("\n");
  out+=string("detail ")+_detail+string("\n");
  return out;
 }
 bool templateFromString( const char *position, const char **moved_to ) {
  bool result=false;
  const char *p=position;
  char key[1024];
  string value;
  p=one_argument(p,key);
  if ( !str_cmp(key,"id") ) {
   result=true;
   (*moved_to)=string_argument(p,&value);
  } else if ( !str_cmp(key,"recipe") ) {
   result=true;
   (*moved_to)=string_argument(p,&value);
  } else if ( !str_cmp(key,"flags") ) {
   result=true;
   (*moved_to)=string_argument(p,&value);
  } else if ( !str_cmp(key,"values") ) {
   result=true;
   (*moved_to)=string_argument(p,&value);
  } else if ( !str_cmp(key,"noun" ) ) {
   result=true;
   (*moved_to)=string_argument(p,&value);
  } else if ( !str_cmp(key,"plural" ) ) {
   result=true;
   (*moved_to)=string_argument(p,&value);
  } else if ( !str_cmp(key,"detail") ) {
   result=true;
   (*moved_to)=string_argument(p,&value);
  } else {
   (*moved_to)=position;
  }
  return result;
 }
 virtual Template *Clone() {
  Template *clone=new Template(this);
  clone->Cloned();
  return clone;
 }
 virtual void Clone( Template *t ) {
  if ( t->list ) GetUniqueId(t->list);
  Cloning(t);
 }
 virtual void Cloning( Template *t ) { // Override this one
 }
 virtual Entity *Manufacture();
 virtual void Loaded() {}
 virtual void Unloaded() {}
 virtual void Cloned() {}
 virtual void Manufactured() {}
 virtual void Hit() {}
 virtual void Dispense() {}
 virtual void Decay() {}
 virtual void Between() {}
 virtual void Destroyed() {}  // Not when the memory is freed
 virtual void Deallocated() {}  // When the memory was freed
 ~Template() {
  Deallocated();
 }
 void GetUniqueId( Templates *list );
};

class Templates : public LinkedList {
public:
 CLEARLISTRESET(Template);
};
