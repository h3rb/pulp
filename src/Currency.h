#pragma once

#include "LinkedList.h"

class Currency : public ListItem {
public:
 Zstring name;
 Zstring unit;
 Zdouble value;
};

class Currencies : public LinkedList {
public:
 Zdouble exchange; //rate
 CLEARLISTRESET(Currency);
};
