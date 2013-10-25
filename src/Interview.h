#pragma once

#include "LinkedList.h"

class InSession;
class Interviews;

class Interview : public ListItem {
public:
 Zbool popMe;
 Zp<Interviews> interviews;
 virtual string Query( InSession *session ) { return string("Press return to continue: "); }
 virtual void Response( InSession *session, string in ) { popMe=true; }
};

class Interviews : public LinkedList {
public:
 Zp<InSession> interviewee;
 void Push( Interview *i ) {
  i->interviews=this;
  Append(i);
 }
 void Replace( Interview *a, Interview *b ) {
  b->interviews = a->interviews;
  b->prev=a->prev; a->next=null;
  b->next=a->next; a->prev=null;
  a->popMe=true;
 }
 void Continue();
 CLEARLISTRESET(Interview);
};
