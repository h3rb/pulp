#pragma once

#include "LinkedList.h"
#include "Interview.h"
#include "InSession.h"

// Special interview questions for setting up terminal / emulation
// Listed in reversed order of use for referencing heirarchy reasons


class Interview_MSSP_request : public ListItem {
};

class Interview_LClient_request : public ListItem {
public:
};


class Interview_XTerm_color : public ListItem {
public:
 void Query( InSession *session ) {
 }
 bool Response( InSession *session, string in ) {
 }
};


class Interview_ANSI_arrows_b : public ListItem {
public:
 string Query( InSession *session ) {
  return
   string(
    "Special key emulation is possible with some terminals.\n\r"
    "If you know yours does not support F-keys remotely,\n\r"
    "simply press the return key.\n\r"
    "Now press your F-keys and hit return:\n\r"
   );
 }
 void Response( InSession *session, string in ) {
 }
};

class Interview_ANSI_arrows_a : public ListItem {
public:
 string Query( InSession *session ) {
  return
   string(
    "To determine if your terminal supports VT/ANSI\n\r"
    "terminal keys, type one or more arrow keys and hit return:\n\r"
   );
 }
 void Response( InSession *session, string in ) {
 }
};


#define LINE_WRAP "11223344556677889900!!@@##$$%%^^&&**(())--==__++[[]]{{}};;''::,,..''~~//??>><<AABBCCDDEEFFGGHHIIJKKLLMMNNOOPPQQRRSSTTUUVVWWXXYYZZaabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyyzz"
#define BLANKWRAP "                                                                                                                                                                                     "

class Interview_Width_request : public ListItem {
public:
 void Query( InSession *session ) {
  return
    string(
 "To figure out your precise screen width,\n\r"
 "a long line of characters will be output\n\r"
 "on your screen.  If this line hits the right\n\r"
 "side, we can get a precise measurement by\n\r"
 "asking what character hit the right side.\n\r"
 "If you know your terminal's column width,\n\r"
 "you can simply enter a number instead of\n\r"
 "answering yes or no.\n\r\n\rTest line:\n\r"
   )
   +string(LINE_WRAP)
   +string("\n\r");
   +string("\n\rDid the line hit the right side (Yes/no) ? ");
 }
 void Response( InSession *session, string in ) {
  string response=string("");
  const char *p=string_argument(p,&response);
  const char *s=response.c_str();
  if ( is_integer(response.c_str()) ) {
  } else if ( *s == 'y' ) {
  } else {
  }
 }
};

class Interview_Width_requestb : public ListItem {
 string Query( InSession *session ) {
  return
   string( "\n\rWhat character hit the right side? ");
 }
 void Response( InSession *session, string in ) {
 }
};

class Interview_Width_request4 : public ListItem {
public:
 string Query( InSession *session ) {
  return
    string(BLANKWRAP)+string("\n\r")
   +string(BLANKWRAP)+string("\n\r")
   +string(BLANKWRAP)+string("\n\r")
   +string(LINE_WRAP)
   +string("\n\r")
   +string("\n\rDid the line hit the right side (Yes/no) ? ");
 }
 void Response( InSession *session, string in ) {
  string response=string("");
  const char *p=string_argument(p,&response);
  const char *s=response.c_str();
  if ( is_integer(response.c_str()) ) {
  } else if ( *s == 'y' ) {
  } else {
  }
 }
};

class Interview_Width_request4b : public ListItem {
 string Query( InSession *session ) {
  return
   string( "\n\rWhat character hit the right side? ");
 }
 void Response( InSession *session, string in ) {
 }
};

class Interview_Width_request3 : public ListItem {
public:
 void Query( InSession *session ) {
  return
    string(BLANKWRAP)+string("\n\r")
   +string(BLANKWRAP)+string("\n\r")
   +string(LINE_WRAP)
   +string("\n\r")
   +string("\n\rDid the line hit the right side (Yes/no) ? ");
 }
 void Response( InSession *session, string in ) {
  string response=string("");
  const char *p=string_argument(p,&response);
  const char *s=response.c_str();
  if ( is_integer(response.c_str()) ) {
  } else if ( *s == 'y' ) {
  } else {
  }
 }
};

class Interview_Width_request3b : public ListItem {
 void Query( InSession *session ) {
  return
   string( "\n\rWhat character hit the right side? ");
 }
 void Response( InSession *session, string in ) {
 }
};

class Interview_Width_request2 : public ListItem {
public:
 void Query( InSession *session ) {
  return
    string(BLANKWRAP)+string("\n\r")
   +string(LINE_WRAP)
   +string("\n\r")
   +string("\n\rDid the line hit the right side (Yes/no) ? ");
 }
 void Response( InSession *session, string in ) {
  string response=string("");
  const char *p=string_argument(p,&response);
  const char *s=response.c_str();
  if ( is_integer(response.c_str()) ) {
  } else if ( *s == 'y' ) {
  } else {
  }
 }
};

class Interview_Width_request2b : public ListItem {
 void Query( InSession *session ) {
  string out=
   string( "\n\rWhat character hit the right side? ");
 }
 void Response( InSession *session, string in ) {
 }
};

class Interview_Height_request : public ListItem {
public:
 void Query( InSession *session ) {
  string out=string("");
  for ( int i=500; i>1; i-- ) {
   out+=FORMAT(buf,10,"%d\n\r",i );
  }
  out+=string("What number is at the top? ");
 }
 bool Response( InSession *session, string in ) {
  string response=string("");
  const char *p=string_argument(p,&response);
  if ( !is_integer(response.c_str()) ) {
   return;
  } else {
   int value=atoi(response.c_str());
   session->client.height=value;
  }
 }
};


class Interview_ANSI_repositionH : public ListItem {
public:
 string Query( InSession *session ) {
  string out=
   FORMAT*buf,512,
    "\x01b[5;5HX <- this appears near line 5 column 5\x01b0m\n\r"
    "\n\rIs this statement true (yes/No) ? "
   );
 }
 void Response( InSession *session, string in ) {
  string response=string("");
  const char *p=string_argument(p,&response);
  const char *s=response.c_str();
  if ( *s == 'y' ) {
   session->client.ANSI_repositionH=true;
  } else {
   session->client.ANSI_repositionH=false;
  }
 }
};

class Interview_ANSI_repositionf : public ListItem {
public:
 string Query( InSession *session ) {
  return
   FORMAT*buf,512,
    "\x01b[5;5fX <- this appears near line 5 column 5\x01b0m\n\r"
    "\n\rIs this statement true (yes/No) ? "
   );
 }
 void Response( InSession *session, string in ) {
  string response=string("");
  const char *p=string_argument(p,&response);
  const char *s=response.c_str();
  if ( *s == 'y' ) {
   session->client.ANSI_repositionf=true;
   interviews->Replace( this, new Interview_ANSI_repositionH );
  } else {
   session->client.ANSI_repositionf=false;
   interviews->Replace( this, new Interview_ANSI_repositionH );
  }
 }
};

class Interview_ANSI_bgcolors : public ListItem {
public:
 string Query( InSession *session ) {
  return
   FORMAT*buf,512,
    "\x01b32;1;45mThis is green on purple\x01b0m\n\r"
    "\x01b35;1;44mThis is cyan on blue\x01b0m\n\r"
    "\x01b37;2;41mThis is grey on red\x01b0m\n\r"
    "\x01b0mThis is colorless\x01b0m\n\r"
    "\n\rAre the above close to what they describe (yes/No) ? "
   );
 }
 void Response( InSession *session, string in ) {
  string response=string("");
  const char *p=string_argument(p,&response);
  const char *s=response.c_str();
  if ( *s == 'y' ) {
   session->client.ANSI_bgcolors=true;
   interviews->Replace( this, new Interview_ANSI_repositionf );
  } else {
   session->client.ANSI_bgcolors=false;
   interviews->Replace( this, new Interview_ANSI_repositionf );
  }
 }
};

class Interview_ANSI_color : public ListItem {
public:
 string Query( InSession *session ) {
  return
   FORMAT(buf,512,
    "\x01b32mThis is green\x01b0m\n\r"
    "\x01b33mThis is yellow or brown\x01b0m\n\r"
    "\x01b35;1mThis is bright purple\x01b0m\n\r"
    "\x01b0mThis is colorless\x01b0m\n\r"
    "\n\rAre the above in 3 or more colors (yes/No) ? "
   );
 }
 void Response( InSession *session, string in ) {
  string response=string("");
  const char *p=string_argument(p,&response);
  const char *s=response.c_str();
  if ( *s == 'y' ) {
   session->client.ANSI_color=true;
   interviews->Replace( this, new Interview_ANSI_bgcolors );
  } else {
   session->client.ANSI_color=false;
   interviews->Replace( this, new Interview_ANSI_repositionf );
  }
 }
};

class Interview_ANSI_bgcolors_colorblind : public ListItem {
public:
 string Query( InSession *session ) {
  return
   FORMAT*buf,512,
    "\x01b32;1;45mThis is green on purple\x01b0m\n\r"
    "\x01b35;1;44mThis is cyan on blue\x01b0m\n\r"
    "\x01b37;2;41mThis is grey on red\x01b0m\n\r"
    "\n\rAre the above in boxes of multiple colors (yes/No) ? "
   );
 }
 void Response( InSession *session, string in ) {
  string response=string("");
  const char *p=string_argument(p,&response);
  const char *s=response.c_str();
  if ( *s == 'y' ) {
   session->client.ANSI_bgcolors=true;
   interviews->Replace( this, new Interview_ANSI_repositionf );
  } else {
   session->client.ANSI_bgcolors=false;
   interviews->Replace( this, new Interview_ANSI_repositionf );
  }
 }
};

class Interview_ANSI_color_colorblind : public ListItem {
public:
 string Query( InSession *session ) {
  return
   FORMAT(buf,512,
    "\x01b32mThis is green\x01b0m\n\r"
    "\x01b33mThis is yellow or brown\x01b0m\n\r"
    "\x01b35;1mThis is bright purple\x01b0m\n\r"
    "\x01b0mThis is colorless\x01b0m\n\r"
    "\x01b31mThis is red\x01b0m\n\r"
    "\n\rAre the above in multiple colors (yes/No) ? "
   );
 }
 void Response( InSession *session, string in ) {
  string response=string("");
  const char *p=string_argument(p,&response);
  const char *s=response.c_str();
  if ( *s == 'y' ) {
   session->client.ANSI_color=true;
   interviews->Replace( this, new Interview_ANSI_bgcolors_colorblind );
  } else {
   session->client.ANSI_color=false;
   interviews->Replace( this, new Interview_ANSI_repositionf );
  }
 }
};

class Interview_Colorblind2 : public ListItem {
public:
 string Query( InSession *session ) {
  return
   FORMAT(buf,512,
    "What kind of colorblindness do you have?\n\r"
    "Enter 0 for monochromacy or total color blindness\n\r"
    "Enter 1 for protanopic dichromacy (red is dark)\n\r"
    "Enter 2 for deuteranopic dichromacy (red-green)\n\r"
    "Enter 3 for tritanopic dichromacy (no blue)\n\r"
    "Enter 4 for protonamlic trichromacy (red-green)\n\r"
    "Enter 5 for deuteranomalic trichromacy (red-green)\n\r"
    "Enter 6 for tritanomalic trichromacy (blue-yellow)\n\r"
    "Make your choice (0-6) now: \n\r",
   );
 }
 void Response( InSession *session, string in ) {
  string response=string("");
  const char *p=string_argument(p,&response);
  if ( is_integer(response.c_str()) ) {
   int value=atoi(response.c_str());
   if ( value < 0 || value > 6 ) {
    return;
   } else {
    session->client.colorblindedness=value;
    interviews->Replace( this, new Interview_ANSI_color_colorblind );
   }
  }
 }
};

class Interview_Colorblind : public ListItem {
public:
 string Query( InSession *session ) {
  return
   FORMAT(buf,512,
    "By answering yes to the following question,\n\r"
    "an alternative color-coding system will be used.\n\r"
    "Are you color-blind (yes/No) ? "
   );
 }
 void Response( InSession *session, string in ) {
  string response=string("");
  const char *p=string_argument(p,&response);
  const char *s=response.c_str();
  if ( *s == 'y' ) {
   session->client.colorblind=true;
   interviews->Replace( this, new Interview_Colorblind2 );
  } else {
   session->client.colorblind=false;
   interviews->Replace( this, new Interview_ANSI_color );
  }
 }
};

class Interview_ANSI_clrscr : public ListItem {
public:
 string Query( InSession *session ) {
  return
   FORMAT(buf,512,
    "\x01b[2J"
    "This test determines if you support\n\r"
    "a special ANSI code for clearing the view.\n\r"
    "Are these three lines the only text you see on the screen now (yes/No) ? "
   );
 }
 void Response( InSession *session, string in ) {
  string response=string("");
  const char *p=string_argument(p,&response);
  const char *s=response.c_str();
  if ( *s == 'y' ) {
   session->client.ANSI_clrscr=true;
   interviews->Replace( this, new Interview_Colorblind );
  } else {
   session->client.ANSI_clrscr=false;
   interviews->Replace( this, new Interview_Colorblind );
  }
 }
};

class Interview_VTInverse : public ListItem {
public:
 string Query( InSession *session ) {
  return
   FORMAT(buf,1024,
    "The next test determines if you support\n\r",
    "the classic VT-100 terminal inverted text code.\n\r"
    "\n\r"
    "\x01b7mInverted\x01b0m\n\r"
    "\n\rWas the text "Inverted" contained in a box (yes/No) ? "
   );
 }
 void Response( InSession *session, string in ) {
  string response=string("");
  const char *p=string_argument(p,&response);
  const char *s=response.c_str();
  if ( *s == 'n' ) {
   session->client.vt_inverse=false;
   interviews->Replace( this, new Interview_ANSI_clrscr );
  } else {
   session->client.vt_inverse=true;
   interviews->Replace( this, new Interview_ANSI_clrscr );
  }
 }
};

class Interview_CR : public ListItem {
public:
 string Query( InSession *session ) {
  return
   FORMAT(buf,1024,
    "The following is a test for support of\n\r"
    "the carriage return.  Carriage returns\n\r"
    "move the cursor to the beginning of the line,\n\r"
    "but do not advance to a new line.\n\r"
    "\n\r"
    "This text should appear only once.\r"
    "This text should appear only once.\n\r"
    "\n\rHow many times did the line appear (1 or 2) ? "
   );
 }
 void Response( InSession *session, string in ) {
  string response=string("");
  const char *p=string_argument(p,&response);
  const char *s=response.c_str();
  if ( *s == '1' ) {
   session->client.carriage_return=true;
   interviews->Replace( this, new Interview_VTInverse );
  } else if ( *s == '2' ) {
   session->client.carriage_return=false;
   interviews->Replace( this, new Interview_VTInverse );
  }
 }
};

class Interview_AGE : public ListItem {
public:
 string Query( InSession *session ) {
  return
   FORMAT(buf,1024,
  "This game provides an ASCII Graphics Engine\n\r"
  "that generates ASCII renderings of pictures,\n\r"
  "geometric figures, bar graphs and other charts,\n\r"
  "draws scenes and shows sprites.  It is not\n\r"
  "intended for use by people with screen readers,\n\r"
  "the visually disabled or people who just want\n\r"
  "a non-visual textual depiction exclusively.\n\r"
  "\n\r"
  "Activate this mode (Yes/no) ? "
  );
 }
 void Response( InSession *session, string in ) {
  string response=string("");
  const char *p=string_argument(p,&response);
  const char *s=response.c_str();
  if ( *s == 'n' ) {
   session->client.AGE=false;
   interviews->Replace( this, new Interview_CR );
  } else {
   session->client.AGE=true;
   interviews->Replace( this, new Interview_CR );
  }
  return true;
 }
};

