#pragma once

#include "LinkedList.h"

class InSession;

class CommandSet : public ListItem {
public:
 Zp<InSession> session;
 virtual void Process( string in, string &out ) {
 }
};
