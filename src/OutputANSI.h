#pragma once

#include "OutputProcessor.h"

class OutputANSI : public OutputProcessor {
public:
 OutputANSI() : OutputProcessor() {
  Add( "\\q", "\x01b[30m" );
  Add( "\\w", "\x01b[31m" );
  Add( "\\e", "\x01b[32m" );
  Add( "\\r", "\x01b[33m" );
  Add( "\\t", "\x01b[34m" );
  Add( "\\y", "\x01b[35m" );
  Add( "\\u", "\x01b[36m" );
  Add( "\\i", "\x01b[37m" );
  Add( "\\o", "\x01b[0m" );
  Add( "\\Q", "\x01b[1\x01b[31m" );
  Add( "\\W", "\x01b[1\x01b[31m" );
  Add( "\\E", "\x01b[1\x01b[31m" );
  Add( "\\R", "\x01b[1\x01b[31m" );
  Add( "\\T", "\x01b[1\x01b[31m" );
  Add( "\\Y", "\x01b[1\x01b[31m" );
  Add( "\\U", "\x01b[1\x01b[31m" );
  Add( "\\I", "\x01b[1\x01b[31m" );
  Add( "\\O", "\x01b[0m" );
  Add( "\\B", "\x01b[1m" );
  Add( "\\N", "\x01b[7m" );
  Add( "\\A", "\x01b[40m" );
  Add( "\\S", "\x01b[41m" );
  Add( "\\D", "\x01b[42m" );
  Add( "\\F", "\x01b[43m" );
  Add( "\\G", "\x01b[44m" );
  Add( "\\H", "\x01b[45m" );
  Add( "\\J", "\x01b[46m" );
  Add( "\\K", "\x01b[47m" );
  Add( "\\C", "\x01b[2J\x01b[H" );
 }
};
