#pragma once

#include "LinkedList.h"
#include "ConfigFile.h"
#include "Strings.h"

class InSession;

class OutputProcessor : public ListItem {
public:
 Zp<InSession> session;
 ConfigFile definitions;
 void Add( const char *search, const char *replace ) {
  definitions.Define(search,replace);
 }
 virtual void Preprocess() {}
 virtual string Process( string in ) {
  Preprocess();
  string out=in;
  EACH(definitions.definitions.first,KeyValuePair,definition)
   out=replace_all( out, definition->s, definition->value );
  return out;
 }
 virtual string Filter( string in ) {
  string empty=string("");
  string out=in;
  EACH(definitions.definitions.first,KeyValuePair,definition)
   out=replace_all( out, definition->s, empty );
  return out;
 }
};

class OutputProcessors : public LinkedList {
public:
 Zp<InSession> session;
 string Process( string in ) {
  string out=in;
  FOREACH(OutputProcessor,op) {
   op->session=session;
   out=op->Process(out);
  }
  return out;
 }
 CLEARLISTRESET(OutputProcessor);
};
