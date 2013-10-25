#include "TCPListener.h"

#include "Server.h"

struct sockaddr_in sa_zero;

TCPListener::TCPListener( int port, Server *server ) {
 this->port=port;
 control=0;
 x=1;
 Init(server);
}

TCPListener::TCPListener( int post, int control, Server *server ) {
 this->port=port;
 this->control=control;
 x=1;
 Init(server);
}

void TCPListener::Init( Server *server ) {
 this->server=server;
 connections.socket=this;
 connections.server=server;
 Init();
}
