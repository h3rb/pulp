#include "bind_socket.h"

  int bind_socket(int socket_descriptor,
                  struct sockaddr *local_address,
                  int address_length) {
   return bind(socket_descriptor, local_address, address_length);
  }
