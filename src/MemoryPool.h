#pragma once
#include "macros.h"
#include "moremath.h"
#include "ZeroTypes.h"

using namespace std;

class ListItem;
class LinkedList;

#define MP_GRANULARITY 100

struct MemoryPool {
public:
 Zdisposable<matrix2d<LinkedList>> recycling;
 int available( string type );
 void Recycle( ListItem *L );
 MemoryPool();
 ~MemoryPool();
};

class MemoryManager {
public:
 MemoryPool pool;
 Zdisposable<LinkedList> leashed;
 MemoryManager();
 ~MemoryManager();
 ListItem *New( string type );
 void Delete( ListItem *L );
 void Between();
};

extern MemoryManager mm;

extern Zp<MemoryManager> memory;