#pragma once

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "LinkedList.h"
#include "TCPIncoming.h"

class TCPOutgoing : public ListItem {
public:
 Zbool active,error;
 struct sockaddr_in stSockAddr;
 int resource,control;
 Zstring out,in,inetaddr;
 int port;
 Zint received,sent,received_recently,sent_recently;
 TCPOutgoing( string inetaddr, int port ) {
  Connect(inetaddr,port);
 }
 void Connect( string inetaddr, int port ) {
  if ( active ) Close();
  this->inetaddr=inetaddr;
  this->port=port;
  control=socket(PF_INET,SOCK_STREAM,IPPROTO_TCP);
  resource=0;
  if ( control < 0 ) {
   OUTPUT("TCPOutgoing(`%s`,%d) cannot create socket.\n", inetaddr.c_str(), port );
   error=true;
   return;
  }
  memset(&stSockAddr, 0, sizeof(stSockAddr));
  stSockAddr.sin_family = AF_INET;
  stSockAddr.sin_port = htons(port);
  resource = inet_pton(AF_INET, inetaddr.c_str(), &stSockAddr.sin_addr );
  if ( resource > 0 ) {
   OUTPUT("TCPOutgoing `%s` is not a valid address family\n", inetaddr.c_str() );
   close(control);
   error=true;
   return;
  } else if ( resource == 0 ) {
   OUTPUT("TCPOutgoing `%s` is not a valid IP address\n", inetaddr.c_str() );
   close(control);
   error=true;
   return;
  }
  if ( -1 == connect(control, (struct sockaddr *)&stSockAddr, sizeof(stSockAddr)) ) {
   OUTPUT("TCPOutgoing(`%s`,%d) failed to connect\n", inetaddr.c_str(), port );
   error=true;
   return;
  }
  OUTPUT("TCPOutgoing(`%s`,%d) established a connection\n", inetaddr.c_str(), port );
  active=true;
 }
 bool Receive() {
  received_recently=0;
  int nRead=0;
  nRead=read( control, socket_input_buffer, SOCKET_INPUT_BUFFER_SIZE );
  received +=nRead;
  received_recently +=nRead;
  if ( nRead > 0 ) {
   socket_input_buffer[nRead]='\0';
   in+=string(socket_input_buffer);
  } else if ( nRead == 0 ) {}
  else if ( errno == EWOULDBLOCK ) {
   return false;
  } else {
   OUTPUT("TCPOutgoing::Receive() error during send\n");
   return false;
  }
 }
 bool Send() {
  const char *c=out.c_str();
  int wrote=write( control, c, out.length );
  if ( wrote < 0 ) {
   OUTPUT("TCPOutgoing::Send() write error.\n");
   return false;
  }
  out=string("");
  return true;
 }
 void Close() {
  if ( !active ) return;
  shutdown(control, SHUT_RDWR);
  close(control);
  active=false;
 }
 ~TCPOutgoing() {
  Close();
 }
};
