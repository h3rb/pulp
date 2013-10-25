#include "pulp.h"
#include "Server.h"
#include "ConfigFile.h"
#include "CommandLine.h"
#include "TimeKeeper.h"

#include <iostream>
#include <signal.h>

// Main signal handler:
// Only responds to SIGBRK and only then signals internally

Zp<Server> server;
Zbool signalled_abort;

void signal_handler( int sig ) {
 switch ( sig ) {
  case SIGINT:
    OUTPUT("Ctrl-C received / SIGINT - exitting gracefully.\n" );
    if ( server ) server->shutdown=true;
    signalled_abort=true;
   break;
  default: break;
 }
}

void LoadConfig() {
 OUTPUT("Loading initial config file `%s`...\n", cmdline.pathsfile.c_str() );
 cfg.Load("paths",cmdline.pathsfile.c_str());
 string mud=cfg.find("paths","mud");
 cfg.Load("mud",mud.c_str());
}

int main ( int argc, char **argv ) {
 cmdline.Decipher(argc,argv);
 LoadConfig();
 OUTPUT("Initializing server.\n");
 // This has to be here so broken connections don't end the application.
 signal( SIGPIPE, SIG_IGN );
 if ( signal( SIGINT, signal_handler ) == SIG_ERR ) {
  OUTPUT("Unable to capture SIGINT - Ctrl-C will cause hard shutdown\n");
 }
 int main_port=cfg.integer("paths","main"); if ( !cfg.found ) main_port=3333;
 int rwho_port=cfg.integer("paths","rwho"); if ( !cfg.found ) rwho_port=0;
 int aux_port =cfg.integer("paths","aux" ); if ( !cfg.found ) aux_port=0;
 if ( signalled_abort ) return 0;
 server = new Server( rwho_port, main_port, aux_port );
 while ( !server->shutdown ) {
  timekeeper.Between();
  server->Between();
 }
 OUTPUT("Shutting down.\n");
 server->Shutdown();
 return 0;
}
