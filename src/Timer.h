#pragma once

#include "TimeKeeper.h"

class Timer {
public:
 Zdouble fuse;
 virtual void Between() {
  fuse-=timekeeper.frame;
 }
 virtual void OnComplete() {
 }
};
