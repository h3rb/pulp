#pragma once

#include "LinkedList.h"

class Unique : public ListItem {
public:
 Zuint id;
 Unique() : ListItem() {}
 Unique( unsigned int value ) : ListItem() { id=value; }
 Unique( int value ) : ListItem() { id.value=(unsigned int) value; }
 bool is( Unique *u      ) { return ( u->id.value == id.value ); }
 bool is( int i          ) { return ( (unsigned int) i == id.value ); }
 bool is( unsigned int i ) { return ( i == id.value ); }
 bool is( const char *c  ) { return ( (unsigned int) atoi(c) == id.value ); }
 void Set( unsigned int i ) { this->id=i; }
 void Set( int i ) { this->id=(unsigned int) i; }
 string toString() {
  char b[512];
  return FORMAT(b,512,"%d",(int)id);
 }
 void fromString( const char *s ) {
  id.value=(unsigned int) atoi(s);
 }
 Unique *clone() {
  return new Unique(id.value);
 }
};

class UniqueReferences : public LinkedList {
public:
 string toString() {
  string out=string("");
  FOREACH(Unique,id) {
   out+=id->toString();
   if ( id->next ) out+=string(" ");
  }
  return out;
 }
 void fromString( const char *s ) {
  const char *p=s;
  string value;
  while ( *p != '\0' ) {
   p=string_argument(p,&value);
   Add( (unsigned int) atoi(value.c_str()) );
  }
 }
 bool references( unsigned int i ) {
  FOREACH(Unique,id) if ( id->is(i) ) return true;
  return false;
 }
 bool references( int i ) { return references( (unsigned int) i ); }
 bool references( Unique *u ) {
  FOREACH(Unique,id) if ( id->is(u) ) return true;
  return false;
 }
 void Add( int i ) {
  if ( !references(i) ) Add( (unsigned int) i );
 }
 void Add( unsigned int i ) {
  if ( !references(i) ) Append( new Unique(i) );
 }
 void Add( Unique *id ) {
  if ( !references(id) ) Append(id->clone());
 }
 void RemoveAll( Unique *u ) {
  // Must be careful not to remove u when deleting here.
  // (Self-referencing list not ok)
  FOREACHN(Unique,id,{
   if ( id->is(u) ) {
    Remove(id);
    delete id;
   }
  });
 }
 CLEARLISTRESET(Unique);
};

class NonUniqueReferences : public LinkedList {
public:
 bool references( unsigned int i ) {
  FOREACH(Unique,id) if ( id->is(i) ) return true;
  return false;
 }
 bool references( int i ) { return references( (unsigned int) i ); }
 bool references( Unique *u ) {
  FOREACH(Unique,id) if ( id->is(u) ) return true;
  return false;
 }
 void Add( int i          ) { Add( (unsigned int) i ); }
 void Add( unsigned int i ) { Append( new Unique(i) ); }
 void Add( Unique *id     ) { Append(id->clone());     }
 void RemoveAll( Unique *u ) {
  // Must be careful not to remove u when deleting here.
  // (Self-referencing list not ok)
  FOREACHN(Unique,id,{
   if ( id->is(u) ) {
    Remove(id);
    delete id;
   }
  });
 }
 CLEARLISTRESET(Unique);
};
