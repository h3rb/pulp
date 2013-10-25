#pragma once

#include "LinkedList.h"

class InSession;

class InputProcessor : public ListItem {
public:
 Zp<InSession> session;
 virtual void Process() {}
 virtual string Process( string in ) { return in; }
};

class InputProcessors : public LinkedList {
public:
 Zp<InSession> session;
 virtual string Process( string in ) {
  string input=in;
  FOREACH(InputProcessor,p) {
   p->session=session;
   p->Process();
   input=p->Process(input);
  }
  return input;
 }
 CLEARLISTRESET(InputProcessor);
};
