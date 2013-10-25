#pragma once

#include "ZeroTypes.h"

/*
 * ASCII Pixel class, used by the AImage class.
 */

class APixel {
public:
 char c;
 Zint c;
 Unique set;
 Zp<AColor> bg,fg;
 APixel() {
  c=' ';
 }
};
