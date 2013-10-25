#pragma once

#include "LinkedList.h"
#include "Template.h"

class Entity : public ListItem {
public:
 Entity() : ListItem() {}
 Entity( Entity *e ) : ListItem() { Clone(e); }
 Entity( Template *t ) : ListItem() { ManufactureFrom(t); }
 virtual void ManufactureFrom( Template *t ) {}
 virtual Entity *TransformInto( Entity *e ) { return new Entity; }
 virtual Entity *TransmogrifyInto( Entity *e ) { return new Entity; }
 virtual Entity *TransformInto( Template *t ) { return new Entity; }
 virtual Entity *TransmogrifyInto( Template *t ) { return new Entity; }
 virtual void Clone( Entity *original ) {}
 virtual Entity *Clone() {
  Entity *clone=new Entity(this);
  clone->Cloned();
  return clone;
 }
 virtual void Loaded() {}
 virtual void Unloaded() {}
 virtual void Cloned() {}
 virtual void Hit() {}
 virtual void Dispense() {}
 virtual void Decay() {}
 virtual void Between() {}
 virtual void Destroyed() {}  // Not when the memory is freed
 virtual void Deallocated() {}  // When the memory was freed
 ~Entity() {
  Deallocated();
 }
};
