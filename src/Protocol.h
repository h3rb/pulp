#pragma once

#include "LinkedList.h"
#include "Strings.h"

class ProtocolRule : public ListItem {
public:
 virtual bool Evaluate( const char *in ) { return false; }
 virtual string Result() { return string(""); }
};

class ProtocolRules : public LinkedList {
public:
 virtual string Evaluate( const char *in ) {
  FOREACH(ProtocolRule,r) if ( r->Evaluate(in) ) return r->Result();
  return string("");
 }
};

class Protocol : public ListItem {
 ProtocolRules rules;
 virtual string Evaluate( string in ) {
  string out=string("");
  const char *p=in.c_str();
  while ( *p != '\0' ) {
   string result=rules.Evaluate(p);
   if ( result.length() > 0 ) out+=result;
   else out+=*p;
   p++;
  }
  return out;
 }
};
