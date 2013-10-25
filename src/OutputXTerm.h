#pragma once

#include "OutputProcessor.h"

class OutputXTerm : public OutputProcessor {
public:
 OutputXTerm() : OutputProcessor() {
 }
 void Process( string in ) {
  const char *p=in.c_str();
  p=advance_to(p,'#');
  char a,b,c,d,e,f;
  if ( 
 }
 void Filter( string in ) {
 }
};
