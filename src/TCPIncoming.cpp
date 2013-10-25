#include "TCPIncoming.h"

#include "Telnet.h"

char socket_input_buffer[SOCKET_INPUT_BUFFER_SIZE+1];

#include "Server.h"

void TCPIncoming::Identify( const char * leading ) {
 OUTPUT("%s TCP %s (%s) on port %d\n",
  leading,
  ipaddress.c_str(),
  hostname.c_str(),
  socket ? (int) socket->port : -1
 );
}

void TCPIncoming::CloseOnServer() {
 server->sessions.Dropped(this);
}

void TCPIncomings::AttachServerSocket( TCPIncoming *t ) {
 t->server=server;
 t->socket=socket;
}

bool TCPIncoming::Send() {
 const char *o=out.c_str();
 int wrote=write( (int) connection, o, out.length );
 if ( wrote < 0 ) {
  OUTPUT("TCPIncoming::Send() write error\n");
  return false;
 }
 out=string("");
 return true;
}

void TCPIncomings::Send() {
 FOREACHN(TCPIncoming,c,{
  if ( c->out.length > 0
   && FD_ISSET( (int) c->connection, &socket->out ) ) {
   if ( !c->Send() ) {
    Remove(c);
    delete c;
   }
  }
 });
}

bool TCPIncoming::Receive() {
 received_recently=0;
 if ( FD_ISSET( (int) connection, &socket->in ) ) {
  int nRead=0;
  nRead = read( (int) connection, socket_input_buffer, SOCKET_INPUT_BUFFER_SIZE );
  received += nRead;
  received_recently += nRead;
  if ( nRead > 0 ) {
   socket_input_buffer[nRead]='\0';
   in+=telnet.Listen(socket_input_buffer,nRead);
  } else if ( nRead == 0 ) {
  } else if ( errno == EWOULDBLOCK ) {
   return false;
  } else {
   OUTPUT("TCPIncoming::Receive() error during read\n");
   return false;
  }
 }
#if defined(DEBUG)
 if ( received_recently > 0 ) {
  OUTPUT("TCPIncoming(%d) read %d bytes\n",(int)connection,(int)received_recently);
 }
#endif
 return true;
}

void TCPIncomings::Receive() {
 FOREACHN(TCPIncoming,c,{
  if ( FD_ISSET( (int) c->connection, &socket->in ) ) {
   if ( !c->Receive() ) {
    FD_CLR( (int) c->connection, &socket->out );
    Remove(c);
    delete c;
   }
  }
 });
}
