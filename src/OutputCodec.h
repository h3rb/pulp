#pragma once

#include "Strings.h"

class OutputCodec : public ListItem {
public:
 char start,end;
 Zint length;
 Zbool caseSensitive;
 OutputCodec( char start, int length ) : ListItem() {
  this->start=start;
  this->end='\0';
  this->length=length;
 }
 OutputCodec( char start, char end ) : ListItem() {
  this->start=start;
  this->end=end;
 }
 Strings translation;
 void Add( char *code, char *value ) {
  KeyValuePair *k=new KeyValuePair;
  translation.Append(k);
 }
 string Evaluate( const char *in ) {
  char *o=buf2;
  const char *p=in;
  while ( *p != '\0' ) {
   if ( *p == start ) {
    if ( end == '\0' ) {
     char *q=buf;
     char *q0=buf;
     for ( int i=0; i<length; i++ ) {
      *q=*p;
      q++;
      p++;
     }
     *q='\0';
     KeyValuePair *kvp=null;
     if ( !caseSensitive ) kvp=(KeyValuePair *) translation.findCaseless(q0);
     else kvp=(KeyValuePair *) translation.find(q0);
     if ( kvp ) {
      const char *r=kvp->value.c_str();
      o=copy_to_string(o,r);
     } else {
     }
    } else {
     char *q=buf;
     char *q0=buf;
     if ( end == start ) {
      *q=*p;
      p++;
      q++;
     }
     while ( *p != end ) {
      *q=*p;
      p++;
      q++;
     }
     *q='\0';
     KeyValuePair *kvp=null;
     if ( !caseSensitive ) kvp=(KeyValuePair *) translation.findCaseless(q0);
     else kvp=(KeyValuePair *) translation.find(q0);
     if ( kvp ) {
      const char *r=kvp->value.c_str();
      o=copy_to_string(o,r);
     } else {
     }
    }
   } else {
    *o=*p;
    o++;
    p++;
   }
  }
  *o='\0';
  return string(o);
 }
};

class OutputCodecs : public LinkedList {
public:
 string Evaluate( const char *in ) {
  string out=string(in);
  FOREACH(OutputCodec,oc) {
   out=oc->Evaluate(out.c_str());
  }
  return out;
 }
 CLEARLISTRESET(OutputCodec);
};
