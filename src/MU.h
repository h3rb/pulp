#pragma once

/*
 * The MU is the "main" game port.  It is a child of TCPListener because
 * it attaches the main system for handling incoming socket requests
 * that ultimately lead to telnet or game client roundtrips.
 *
 * The RWHO and AUX interfaces provide a different type of connectivity,
 * so they are implemented separately.
 */

//#include "MUSession.h"
#include "MUAuth.h"
#include "ConfigFile.h"
#include "Database.h"

extern ConfigFiles cfg;

class MU : public TCPListener {
public:
 InSessions sessions;
 MU( int port, Server *server ) : TCPListener( port, server ) {
  Load();
 }
 MU( int port, int control, Server *server ) : TCPListener( port, control, server ) {
  Load();
 }
 void Load() {
  string greets=cfg.find("paths","greetings");
  cfg.Load("greetings",greets.c_str());
  string dbfile=cfg.find("paths","database");
  OUTPUT("MU:Load() loading `%s`\n", dbfile.c_str() );
  database.Load(dbfile.c_str());
 }
 void OnConnect( TCPIncoming *connected ) {
  connected->inputs.Append(new MUAuth(connected));
  connected->out+=cfg.any("greetings");
 }
 bool OnBetween( TCPIncoming *connection ) {
  return true;
 }
};
