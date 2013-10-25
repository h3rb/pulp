#pragma once
#include <sys/types.h>
#include <sys/socket.h>

int bind_socket(int socket_descriptor,
                struct sockaddr *local_address,
                int address_length);
