#pragma once

#include "LinkedList.h"

class Flag : public ListItem {
public:
 Zstring name;
 Flag( string name ) : ListItem() {
  Set(name);
 }
 Flag( const char *name ) : ListItem() {
  Set(name);
 }
 string toString() { return string(str_protect(name.c_str())); }
 const char *ParseKey( const char *p, string key ) {
  name=key;
  return p;
 }
 void Set( string name ) {
  this->name=name;
 }
 void Set( const char *name ) {
  this->name=string(name);
 }
};

class Flags : public LinkedList {
public:
 Flags() : LinkedList() {}
 Flags( string name ) : LinkedList() {
  fromString(name);
 }
 Flags( Flags *flags ) : LinkedList() {
  EACH(flags->first,Flag,f) On(f->name.value);
 }
 void AppendFromString( string name ) {
  Append(new Flag(name));
 }
 void On( string name ) { On(name.c_str()); }
 void On( const char *name ) {
  if ( !Set(name) ) Append(new Flag(name));
 }
 void Off( string name ) { Off(name.c_str()); }
 void Off( const char *name ) {
  FOREACHN(Flag,f,{
   if ( !str_cmp(f->name.value,name) ) {
    Remove(f);
    delete f;
   }
  });
 }
 bool Toggle( string name ) { return Toggle( name.c_str() ); }
 bool Toggle( const char *name ) {
  if ( Set(name) ) {
   Off(name);
   return false;
  } else {
   On(name);
   return true;
  }
 }
 bool Set( string name ) { return Set(name.c_str()); }
 bool Set( const char *name ) {
  FOREACH(Flag,f) if ( !str_cmp(f->name.value,name) ) return true;
  return false;
 }
 CLEARLISTRESET(Flag);
};
