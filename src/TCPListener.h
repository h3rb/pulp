#pragma once

#include "bind_socket.h"
#include "TCPIncoming.h"

#define QUEUE_SIZE 5

//#define USE_DONTLINGER 1

extern struct sockaddr_in sa_zero;

class Server;

class TCPListener {
public:
 Zp<Server> server;
 TCPIncomings connections;
 Zbool active,error;
 int port;
 Zint control;
 fd_set in;
 fd_set out;
 fd_set exchange;
 struct timeval null_time;
 struct sockaddr_in sa;
#if defined(USE_DONTLINGER)
 struct linger ld;
#endif
 int x;
 TCPListener( int port, Server *server );
 TCPListener( int port, int control, Server *server );
 void Init( Server *server );
 void Init() {
  if ( active ) return;
  if ( control == 0 ) {
   if( ( control.value=socket( AF_INET, SOCK_STREAM, 0 ) ) < 0 ) {
    OUTPUT("TCPListener::Init() socket() failed\n");
    return;
   }
  }
  if ( setsockopt( (int) control, SOL_SOCKET, SO_REUSEADDR, (char *) &x, sizeof(x) ) < 0 ) {
   OUTPUT("TCPListener::Init() setsockopt() failed\n");
   close( (int) control );
   return;
  }
#if defined(USE_DONTLINGER)
  ld.l_onoff = 1;
  ld.l_linger= 1000;
  if ( setsockopt( (int) control, SOL_SOCKET, SO_DONTLINGER, (char *) &ld, sizeof(ld) ) < 0 ) {
   OUTPUT("TCPListener::Init() setsockopt() linger failed\n");
   close((int) control);
   return;
  }
#endif
  sa = sa_zero;
  sa.sin_family = AF_INET;
  sa.sin_port   = htons( port );
  if ( bind_socket( (int) control, (struct sockaddr *) &sa, sizeof(sa) ) < 0 ) {
   OUTPUT("TCPListener::Init() bind() failed\n");
   close( (int) control );
   return;
  }
  if ( listen( (int) control, QUEUE_SIZE ) < 0 ) {
   OUTPUT("TCPListener::Init() listen() failed\n");
   close( (int) control );
   return;
  }
  OUTPUT("TCP Socket Listening on port %d, control = %d\n", port, (int) control );
  active=true;
 }
 void Poll() {
  int channels;
  FD_ZERO( &in );
  FD_ZERO( &out );
  FD_ZERO( &exchange );
  FD_SET( control.value, &in );
  channels=control.value;
  EACH(connections.first,TCPIncoming,c) {
   channels=UMAX(channels,(int)c->connection);
   FD_SET( (int) c->connection, &in );
   FD_SET( (int) c->connection, &out );
   FD_SET( (int) c->connection, &exchange );
  }
  if ( select( channels+1, &in, &out, &exchange, &null_time ) < 0 ) {
   OUTPUT( "TCPIncomings::Poll() error at select\n" );
   error=true;
   return;
//   exit(1); // should we have a graceful recovery?
  }
  // New connections
  if ( FD_ISSET( (int) control, &in ) ) {
   TCPIncoming *connecting=connections.Attach(control);
   if ( connecting ) OnConnect(connecting);
  }
 }
 virtual void OnConnect( TCPIncoming *n ) {}
 void Clean() {
  EACHN(connections.first,TCPIncoming,c,{
   if ( c->disconnect
     || FD_ISSET( (int) c->connection, &exchange ) ) {
    FD_CLR( (int) c->connection, &in );
    FD_CLR( (int) c->connection, &out );
    connections.Close(c);
   }
  });
 }
 void Send() {
  connections.Send();
 }
 void Receive() {
  connections.Receive();
 }
 void Between() {
  if ( error ) return;
  Poll();
  Clean();
  Receive();
  Send();
  EACH(connections.first,TCPIncoming,c) {
   c->ProcessInput();
   c->ProcessOutput();
   if ( !OnBetween(c) ) {
    // signal a forced drop (user quit).
   }
  }
 }
 virtual bool OnBetween( TCPIncoming *c ) { return true; }
 void Close() {
  if ( !active ) return;
  close( (int) control );
  active=false;
 }
 ~TCPListener() {
  Close();
 }
};
