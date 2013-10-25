#pragma once

#include "LinkedList.h"

#include "Skill.h"

class AcquiredSkill : public ListItem {
public:
};

class AcquiredSkills : public LinkedList {
public:
 CLEARLISTRESET(AcquiredSkill);
};
