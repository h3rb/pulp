#pragma once

#include <sys/types.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <sys/unistd.h>
#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <zlib.h>
#include <signal.h>
#include <fcntl.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/telnet.h>

#include "Strings.h"
#include "Telnet.h"
#include "InputProcessor.h"
#include "OutputProcessor.h"
#include "TimeKeeper.h"

#define TERM_EOL "\n\r"

#if !defined(FNDELAY)
#define FNDELAY O_NDELAY
#endif

#define SOCKET_INPUT_BUFFER_SIZE 32768
extern char socket_input_buffer[SOCKET_INPUT_BUFFER_SIZE+1];

class Server;
class TCPListener;

class TCPIncoming : public ListItem {
public:
 Telnet telnet;
 Zp<TCPListener> socket;
 Zp<Server> server;
 Zbool active,error,disconnect;
 Zdouble disconnecting;
 Zint connection;
 uint32_t address;
 struct sockaddr_in ip;
 struct hostent *from;
 struct timeval connected_time,last_received_time;
 Zstring hostname,ipaddress;
 Zstring out,in;
 Zint received,received_recently;
 InputProcessors inputs;
 OutputProcessors outputs;
 TCPIncoming() {
  Init();
 }
/*
 void SetSession( InSession *session ) {
  this->session=session;
  inputs.session=session;
  outputs.session=session;
 }
 */
 void ProcessInput() {
  inputs.Process(in);
  in=string("");
 }
 void ProcessOutput() {
  outputs.Process(out);
  if ( disconnecting > 0.0 ) {
   disconnecting-=timekeeper.frame;
   if ( disconnecting < 0.0 ) disconnect=true;
  }
 }
 void Init() {
  from=NULL;
  address=0;
 }
 void Identify( const char *leading );
 void Write( const char *output ) {
  out+=string(output);
 }
 void Write( string output ) {
  out+=output;
 }
 void Writeln( const char *output ) {
  out+=string(output)+string(TERM_EOL);
 }
 void Writeln( string output ) {
  out+=output+string(TERM_EOL);
 }
 bool Send();
 bool Receive();
 void Close() {
  active=false;
  Identify("Terminating connection:");
  close( (int) connection );
  CloseOnServer();
 }
 void CloseOnServer();
 ~TCPIncoming() {
  if ( active ) Close();
//  if ( from ) delete from;  // disposed by the context?  what happens to this? free()?
 }
};

class TCPIncomings : public LinkedList {
public:
 Zp<TCPListener> socket;
 Zp<Server> server;
 Strings banned,quiet;
 size_t sock_size;
 TCPIncomings() {
  sock_size=sizeof(sockaddr_in);
 }
 void AttachServerSocket( TCPIncoming *c );
 TCPIncoming *Attach( int control ) {
  if ( control == 0 ) return null;
  TCPIncoming *c = new TCPIncoming;
  AttachServerSocket(c);
  if ( ( c->connection = accept( control, (struct sockaddr *) &c->ip, &sock_size ) ) < 0 ) {
   OUTPUT("TCPIncomings::Attach(%d) reports accept failure\n", control );
   delete c;
   return null;
  }
  if ( fcntl( c->connection, F_SETFL, FNDELAY ) == -1 ) {
   OUTPUT("TCPIncomings::Attach(%d) reports fcntl error\n", control );
   delete c;
   return null;
  }
  c->active=true;
  if ( getpeername( c->connection, (struct sockaddr *) &c->ip, &sock_size ) < 0 ) {
   c->hostname=string("unknown");
  } else {
   int addr=ntohl( c->ip.sin_addr.s_addr );
   c->address=addr;
   sprintf( buf, "%d.%d.%d.%d",
            ( addr >> 24 ) & 0xFF, ( addr >> 16 ) & 0xFF,
            ( addr >>  8 ) & 0xFF, ( addr       ) & 0xFF
            );
   c->ipaddress=string(buf);
   c->from = gethostbyaddr( (char *) &c->ip.sin_addr, sizeof(c->ip.sin_addr), AF_INET );
   c->hostname=string( c->from ? c->from->h_name : (char *) c->ipaddress );
  }
  if ( banned.inList( c->hostname.c_str() )
    || banned.inList( c->ipaddress ) ) {
   c->Write( "Banned.\n\r" );
   delete c;
  }
  gettimeofday(&c->connected_time,NULL);
  gettimeofday(&c->last_received_time,NULL);
  c->Identify("Connection established:");
  Append(c);
  return c;
 }
 void Close( TCPIncoming *c ) {
  Remove(c);
  delete c;
 }
 void Send();
 void Receive();
 void Write( char const *content ) {
  FOREACH(TCPIncoming,c) c->Write(content);
 }
 CLEARLISTRESET(TCPIncoming);
};
