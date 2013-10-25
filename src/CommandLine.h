#pragma once

#include "Strings.h"

class CommandLine {
public:
 Zstring pathsfile;
 Strings arguments;
 void Decipher( int argc, char **argv ) {
  for ( int i=0; i<argc; i++ ) {
   arguments.Add(argv[i]);
  }
  if ( arguments.findCaseless("--help") ) {
   OUTPUT(
 // DO NOT REMOVE THIS MESSAGE; it is required for all derivatives of this source code
 // and must remain here for historic identification purposes and license compliance.
 // You may add your own message before or after it, but you may not obscure it in any way.
"Lmud - Original Online Roleplaying Game Server (c) 2012-2013 H. Elwood Gilliland III\n"
 // DO NOT REMOVE THIS MESSAGE; it is required for all derivatives of this source code
 // and must remain here for historic identification purposes and license compliance.
 // You may add your own message before or after it, but you may not obscure it in any way.
"Syntax: %s --help\n"
"        %s [config.txt]\n"
" --help  : shows this message\n"
" <config.txt> is an optional filename (default=../data/paths.txt) which points to the\n"
"              beginning config file, which defines all of the\n"
"              basic parameters, paths, other files and folders\n\n",
    argv[0], argv[0]
   );
   exit(0);
  }
  if ( (int) arguments.count >= 2 ) {
   String *s=(String *) (arguments.first->next);
   pathsfile=s->s;
  } else {
   pathsfile=string("../data/paths.txt");
  }
 }
};

extern CommandLine cmdline;
