#pragma once

#define NEW(v,t) try { v= new t; } catch (bad_alloc& ba) { OUTPUT("NEW: bad_alloc caught: %s\n", ba.what()); }