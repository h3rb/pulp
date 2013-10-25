#pragma once

#include "TCPIncoming.h"
#include "InputProcessor.h"
#include "Database.h"

class MUAuth : public InputProcessor {
public:
 Zp<TCPIncoming> connection;
 Zbool authenticated;
 Zp<Player> player;
 Zint fails;
 MUAuth( TCPIncoming *in ) : InputProcessor() {
  connection=in;
 }
 string Process( string in ) {
  Zstring out=in;
  Zstring line=out.PopLine();
  string command=line.Pop();
  if ( !str_cmp( command.c_str(), "create" ) ) {
   string name=line.Pop();
   string password=line.Pop();
   player=database.player(name.c_str());
   if ( player ) {
    string o=string("A player already exists by this name - use 'connect ")+name+string(" <password>' if it's yours\n");
    connection->Write( o.c_str() );
   } else {
    player=new Player;
    player->name=name;
    player->password=password;
    players.Append(player.pointer);
   }
  } else if ( !str_cmp( command.c_str(), "quit" ) ) {
   connection->Write("Disconnecting...");
   connection->disconnecting=0.1;
  } else if ( !str_cmp( command.c_str(), "connect" ) ) {
   string name=line.Pop();
   player=database.player(name.c_str());
   if ( !player ) {
    string o=string("No player by that name - create it by typing 'create ")+name+string(" <password>'\n");
    connection->Write( o.c_str() );
   } else {
    string password=line.Pop();
    if ( !str_cmp(password.c_str(),player->password.c_str()) ) {
     string o=string("Authenticated.\n");
     connection->Write( o.c_str() );
    } else {
     player=null;
     string o=string("Invalid password.\n\r");
     connection->Write( o.c_str() );
     fails++;
     if ( fails >= 3 ) connection->disconnect=true;
    }
   }
  } else if ( !str_cmp( command.c_str(), "client" ) ) {
  }
  return out.value;
 }
};
