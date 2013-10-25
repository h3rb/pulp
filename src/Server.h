#pragma once

#include "TimeKeeper.h"
#include "TCPListener.h"
#include "InSession.h"
#include "MU.h"
#include "Database.h"

class Server {
public:
 InSessions sessions;
 Zp<TCPListener> rwho;
 Zp<TCPListener> main;
 Zp<TCPListener> aux;
 Zbool shutdown;

 Server( int rwhoPort, int mainPort, int auxPort ) {
  if ( rwhoPort > 1024 ) rwho = new TCPListener( rwhoPort, this );
  if ( mainPort > 1024 ) main = new MU( mainPort, this );
  if ( auxPort >  1024 ) aux = new TCPListener( auxPort, this );
  OUTPUT("Server boot time: %s\n", timekeeper.timeString.c_str() );
 }

 void Between() {
  if ( rwho ) rwho->Between();
  if ( main ) main->Between();
  if ( aux )  aux->Between();
 }

 void Shutdown() {
  string dbfile=cfg.find("paths","database");
  OUTPUT("Server:Shutdown() saving `%s`\n", dbfile.c_str() );
  database.Save(dbfile.c_str());
  OUTPUT("Server operated for %f seconds.\n", (double) timekeeper.elapsed );
 }
};
