#include "Interview.h"

void Interviews::Continue() {
 Interview *top=(Interview *) first;
 if ( !top ) return;
 if ( waitingForInput ) {
  if ( count_char( interviewee->input.c_str(), "\n" ) > 0 ) {
   waitingForInput=false;
   top->Response( interviewee, interviewee->pop_line() );
   if ( !top->next && !top->prev ) delete top;
  }
 } else {
  top->Query( interviewee );
 }
 // Remove those slated for deletion...
 FOREACH(Interview,i) if ( i->popMe ) {
  Remove(i);
  delete i;
 }
}
