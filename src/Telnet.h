#pragma once

// RFC 854
#define TN_SB   250 // Indicates start of sub-negotiation of indicated option
#define TN_SE   240 // Indicates the end of sub-negotation
#define TN_NOOP 241 // No-Operation
#define TN_DM   242 // Should always be accompanied by TCP Urgent
#define TN_BRK  243 // Network Virtual Terminal (NVT) Break (BRK)
#define TN_IP   244 // Interrupt Process
#define TN_AO   245 // Abort output
#define TN_AYT  246 // Are you there? (AYT)
#define TN_EC   247 // Erase Character
#define TN_EL   248 // Erase Line
#define TN_GA   249 // Telnet Go-Ahead (GA)
#define TN_WILL 251 // WILL (option code)  - assert begin performing / are performing
#define TN_WONT 252 // WONT (option code)  - refusal / stop performing
#define TN_DO   253 // DO (option code)    - expecting other party to perform
#define TN_DONT 254 // DONT (option code) Indicates demand to stop performing
#define TN_IAC  255 // Data Byte 255 (indicates beginning of sublingual)

// The IS code in TERMINAL-TYPE negotiation is removed from the socket (no '0' may be sent
// through the socket, so IS is ignored.)
#define TN_IS 0  // Origin code for "IS", see RFC1091


enum TNWillWontDoDont {
 tn_will=TN_WILL,
 tn_wont=TN_WONT,
 tn_do=TN_DO,
 tn_dont=TN_DONT,
 tn_start=TN_SB,
 tn_end=TN_SE
};

// RFC 855
//  IAC WILL ABC
//     Offer to use option ABC (or favorable acknowledgment of other party's request)
//  IAC DO ABC
//     Request for other party to use option ABC (or favorable acknowledgement)
//  IAC SB ABC <parameters> IAC SE
//     One step of subnegotiation, used by either party.

// Options from http://www.iana.org/assignments/telnet-options/telnet-options.xml
// Other specifics are offered but not included here, see above link for details.
#define TNO_BIN        0  // Transmit-Binary RFC856
#define TNO_ECHO       1  // Echo RFC857
#define TNO_RECON      2  // Recon (DDN "Telnet Reconnection Option") ("Telnet Output Page Size")
#define TNO_SUPGA      3  // Suppress Go-ahead
#define TNO_AMSN       4  // Approx Message Size Negotiation AA-K759B-TK (DEC)
#define TNO_STATUS     5  // Status RFC859
#define TNO_TIMING     6  // Timing Mark RFC860
#define TNO_RCTE       7  // Remote Controlled Trans and Echo RFC726
#define TNO_OLW        8  // Output Line Width (DDN "Telnet Output Line Width Option")
#define TNO_OPS        9  // Output Page Size ( DDN "TElnet Output Page Size Option")
#define TNO_OCRD      10  // Output Carriage Return Disposition RFC652
#define TNO_OHTS      11  // Output Horizontal Tab Stops RFC653
#define TNO_OHTD      12  // Output Horizontal Tab Disposition RFC654
#define TNO_OFD       13  // Output Formfeed Disposition RFC655
#define TNO_OVT       14  // Output Vertical Tabstops RFC656
#define TNO_OVTD      15  // Output Vertical Tab Disposition RFC657
#define TNO_OLD       16  // Output Linefeed Disposition RFC658
#define TNO_EA        17  // Extended ASCII RFC698
#define TNO_LOGOUT    18  // Logout RFC727
#define TNO_BYTE      19  // Byte Macro RFC735
#define TNO_DET       20  // Data Entry Terminal RFC1043 / RFC734
#define TNO_SUPDUP    21  // SUPDUP RFC736 / RFC734
#define TNO_SUPD_O    22  // SUPDUP Output RFC749
#define TNO_LOCATE    23  // Send Location RFC779
#define TNO_TERM      24  // Terminal Type RFC1091
#define TNO_EOR       25  // End-of-Record RFC885
#define TNO_TACACS    26  // TACACS User Identification RFC927
#define TNO_OUTMARK   27  // Output Marking RFC933
#define TNO_TLN       28  // Terminal Location Number RFC946
#define TNO_T32709R   29  // Telnet 3270 Regime RFC1041
#define TNO_X3PAD     30  // X.3 PAD RFC1053
#define TNO_WINSIZE   31  // Negotiate About Window Size RFC1073 //NAWS
#define TNO_SPEED     32  // Terminal Speed RFC1079
#define TNO_REMFLOW   33  // Remote Flow Control RFC1372
#define TNO_LINEMODE  34  // Linemode RFC1184
#define TNO_XDISPLAY  35  // X Display Location RFC1096
#define TNO_ENVOPT    36  // Environmental Option RFC1408
#define TNO_AUTHOPT   37  // Authentication Option RFC2941
#define TNO_ENCRYPT   38  // Encryption Option RFC2946
#define TNO_NEWENVOPT 39  // New Environmental Option RFC1572
#define TNO_TN3270E   40  // RFC2355
#define TNO_XAUTH     41  // Rob Earhart
#define TNO_CHARSET   42  // RFC2066
#define TNO_RSP       43  // Telnet Remote Serial Port (RSP) Robert Barnes
#define TNO_COMPORT   44  // Com Port Control Option RFC2217
#define TNO_SUP_LECHO 45  // Telnet Suppress Local Echo, Wirt Atmar
#define TNO_START_TLS 46  // Telnet Start TLS, Michael Boe
#define TNO_KERMIT    47  // KERMIT RFC2840
#define TNO_URL       48  // SEND-URL, David Croft
/* 50-137 Unassigned IANA */
#define TNO_PRAG_LOGON 49 // TELOPT PRAGMA LOGON Steve McGregory
#define TNO_SSPI_LOGON 50 // TELOPT SSPI LOGON Steve McGregory
#define TNO_PRAG_HBEAT 51 // TELOPT PRAGMA HEARTBEAT Steve McGregory
/* 141-254 Unassigned */
#define TNO_EXTENDED 255  // Extended-Options-List RFC861

#include "Strings.h"

// We only need a few options,
// so here they are.
//
// 1) Server-Request Line Mode
// 2) Server-Request Char Mode
// 3) Server-Request NAWS data
// 4) Decode NAWS data
// 5) Server-Request TERM-TYPE
// 6) Decode TERM-TYPE

class Telnet {
public:
 Zbool charmode;
 Strings sent,received;

 Telnet() {
  Defaults(); 
  //InitSignal();
 }

 void Defaults() {
 }

 Zstring terminal,wouldnt;
 Zbool NAWED;  // Listen() identified a NAWS window size assertion
 Zbool TERMED; // Listen() identified a TERMINAL-TYPE assertion
 Zbool WOULDNT; // Listen() identified one or more WONTs
 Zint W,H;     // The stored W and H of the NAWS assertion
 // Filters and stacks A-synchronous telnet communications
 // This implements items 4 and 6.
 string Listen( const char *in, int length ) {
  NAWED=false;
  TERMED=false;
  WOULDNT=false;
  wouldnt=string("");
  string out=string("");
  for ( int i=0; i<length; i++ ) {
   char p=in[i];
   if ( p == (char) TN_IAC ) {
    i++;
    if ( i < length ) {
     p=in[i];
     switch ( (int) p ) {
      case TN_WILL:
        {
         i++; if ( i < length ) {
          p=in[i];
          if ( p == (char) TN_IAC ) {
           i++; if ( i < length ) {
            p=in[i];
            switch ( (int) p ) {
             case TNO_TERM:
               {
                terminal.value=string("");
                i++; if ( i < length ) { // IAC
                 i++; if ( i < length ) { // SB
                  i++; if ( i < length ) { // TERMINAL-TYPE
                   i++; if ( i < length ) { // TN_IS (character 0)
                    p=in[i];
                    while ( i < length && p != TN_IAC ) {
                     i++;
                     if ( i < length ) {
                      p=in[i];
                      if ( p != TN_IAC ) {
                       terminal+=p;
                      } else {
                       i++; // TN_SE
                       TERMED=true;
                      }
                     }
                    }
                   }
                  }
                 }
                }
               }
              break;
             case TNO_WINSIZE:
               {
                char /*w0,*/w1,/*h0,*/h1;
                i++; if ( i < length ) { // IAC
                 i++; if ( i < length ) { // SB
                  i++; if ( i < length ) { // NAWS
                   i++; if ( i < length ) { // w0
                    //w0=in[i]; line not needed but in spec
                    i++; if ( i < length ) { // w1
                     w1=in[i];
                     i++; if ( i < length ) { // h0
                      //h0=in[i]; line not needed but in spec
                      i++; if ( i < length ) { // h1
                       h1=in[i];
                       i++; if ( i < length ) { // IAC
                        i++; if ( i < length ) { // SE
                         W=(int)w1;
                         H=(int)h1;
                         NAWED=true;
                        }
                       }
                      }
                     }
                    }
                   }
                  }
                 }
                }
               }
              break;
            }
           }
          }
         }
        }
       break;
      case TN_DO:
      case TN_DONT:
       break;
      case TN_WONT:
        {
         i++;
         if ( i < length ) {
          wouldnt+=in[i];
         }
        }
       break;
     }
    }
   } else {
    out+=p;
   }
  }
  return out;
 }

 string RequestLineMode() {
  return (string("")
   +((char)TN_IAC)
   +((char)TN_DO)
   +((char)TNO_LINEMODE)
  );
 }

 string RequestCharMode() {
  return (string("")
   +((char)TN_IAC)
   +((char)TN_DONT)
   +((char)TNO_LINEMODE)
  );
 }

 string RequestTerminalInfo() {
  return(string(""));
 }

};
