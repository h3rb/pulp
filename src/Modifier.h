#pragma once

#include "LinkedList.h"

class Modifier : public ListItem {
public:
 Zstring adjective;
};

class Modifiers : public LinkedList {
public:
 CLEARLISTRESET(Modifier);
};
