#pragma once

class ClientProfile : public ListItem {
public:
 Zbool AGE;               // Support AGE offscreen graphics emulation mode
 Zbool carriage_return;   // Support "return to line start" code (\r) to animate prompts
 Zbool vt_inverse;        // Support for VT-xxx / ANSI inverse text
 Zbool ANSI_clrscr;       // Support for ANSI clear screen code
 Zbool ANSI_bgcolors;     // Support for ANSI background color codes
 Zbool ANSI_color;        // Support for ANSI color
 Zbool ANSI_repositionf;  // Support for ANSI repositioning
 Zbool ANSI_repositionH;  // Support for ANSI repositioning
 Zbool XTerm_color;       // Support for XTerm 256-color codes
 Zbool useMSSP;           // Support for MSSP color and link tags
 Zbool ANSI_arrows;       // Support for ANSI-style arrow keys and F-keys
 Zbool Lclient;           // Support for lmud's proprietary client codes
 Zint colorblindedness;
 Zbool colorblind;        // Support for "colorblind" color accessibility mode
 Zint width;              // Width of screen output
 Zint height;             // Height of screen output
 string toString() {
  return
   FORMAT(buf,512,"%s%s%s%s%s%s%s%s%s%s%s%s%s height {%d} width {%d}",
    AGE ? "age " : "",
    carriage_return ? "cr " : "",
    vt_inverse ? "inverse " : "",
    ANSI_clrscr ? "clrscr " : "",
    ANSI_bgcolors ? "bgcolors " : "",
    ANSI_color ? "colors " : "",
    ANSI_repositionf ? "reposf " : "",
    ANSI_repositionH ? "reposH " : "",
    XTerm_color ? "xtermcolor " : "",
    useMSSP ? "useMSSP " : "",
    ANSI_arrows ? "arrows " : "",
    Lclient ? "lclient " : "",
    colorblind ? "colorblind " : "",
    (int) height,
    (int) width
   )
   + ( colorblind
     ? FORMAT(buf2,512," colorblindedness {%d}",(int)colorblindedness)
     : ""
     )
  ;
 }
};
