#pragma once

#include "Modifier.h"
#include "Statistic.h"

class ModifiedStatistic : public ListItem {
public:
 Statistic statistic;
 Modifiers modifiers;
};

class ModifiedStatistics : public LinkedList {
public:
 CLEARLISTRESET(ModifiedStatistic);
};
