#pragma once

#include "LinkedList.h"
#include "TCPIncoming.h"
#include "InputProcessor.h"
#include "OutputProcessor.h"
#include "ClientProfile.h"
#include "Interview.h"
#include "Player.h"

class InSession : public ListItem {
public:
 Zdouble input_delay;
 Zbool New,end;
 Zp<TCPIncoming> connection;
 Zstring in,out;
 InputProcessors inputs;
 OutputProcessors outputs;
 ClientProfile client;
 Interviews interviews;
 Players players;
 Zp<Player> player;
 InSession( TCPIncoming *s ) : ListItem() {
  New=true;
  Initialize();
 }
 void Initialize();
 int inlines() {
  return count_char( in.value, '\n' );
 }
 string pop_line() {
  string out=string("");
  in=string(pop_1stline(in.c_str(),&out));
  return out;
 }
 void Between() {
  if ( input_delay > 0 ) {
   input_delay-=FRAMETIME;
  } else {
   if ( interviews.count > 0 ) {
    interviews.Continue();
   } else {
    inputs.session=this;
    string input=inputs.Process(in.value);
   }
  }
  outputs.session=this;
  string output=outputs.Process(out.value);
  if ( connection ) connection->Write(output);
 }
 void Write( string output ) {
  out+=output;
 }
 void Close() {}
 ~InSession() {
  Close();
 }
};

class InSessions : public LinkedList {
public:
 void Dropped( TCPIncoming *t ) {
  FOREACH(InSession,s) if ( s->connection == t ) s->connection=NULL;
 }
 void Between() {
  FOREACHN(InSession,s,{
   if ( s->end ) {
    Remove(s);
    delete s;
   }
   s->Between();
  });
 }
 CLEARLISTRESET(InSession);
};
