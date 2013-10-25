#pragma once

#include "OutputProcessor.h"

// Supports a small subset of codes so that saved files
// can translate appropriate characters overriding any
// other constraints.

class OutputHTML : public OutputProcessor {
public:
 OutputHTML() : OutputProcessor() {
  Add( "&#32;", " " );
  Add( "&nbsp;", " " );
  Add( "&#33;", "!" );
  Add( "&#34;", "\"" );
  Add( "&#35;", "#" );
  Add( "&#36;", "$" );
  Add( "&#37;", "%" );
  Add( "&#38;", "&" );
  Add( "&amp;", "&" );
  Add( "&#39;", "'" );
  Add( "&#40;", "(" );
  Add( "&#41;", ")" );
  Add( "&#42;", "*" );
  Add( "&#43;", "+" );
  Add( "&#44;", "," );
  Add( "&#45;", "-" );
  Add( "&#46;", "." );
  Add( "&#47;", "/" );
  Add( "&#48;", "0" );
  Add( "&#49;", "1" );
  Add( "&#50;", "2" );
  Add( "&#51;", "3" );
  Add( "&#52;", "4" );
  Add( "&#53;", "5" );
  Add( "&#54;", "6" );
  Add( "&#55;", "7" );
  Add( "&#56;", "8" );
  Add( "&#57;", "9" );
  Add( "&#58;", ":" );
  Add( "&#59;", ";" );
  Add( "&#60;", "<" );
  Add( "&lt;",  "<" );
  Add( "&#61;", "=" );
  Add( "&#62;", ">" );
  Add( "&gt;",  ">" );
  Add( "&#63;", "?" );
  Add( "&#64;", "@" );
  ///
  Add( "&#91;", "[");
  Add( "&#92;", "\\");
  Add( "&#93;", "]");
  Add( "&#94;", "^");
  Add( "&#95;", "_");
  Add( "&#96;", "`");
  ///
  Add( "&#123;", "{");
  Add( "&#124;", "|");
  Add( "&#125;", "}");
  Add( "&#126;", "~");

 }
};
