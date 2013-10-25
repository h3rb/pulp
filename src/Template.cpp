#include "Template.h"

#include "Entity.h"

Entity *Template::Manufacture() {
 return new Entity(this);
}

void Template::GetUniqueId( Templates *list ) {
 this->list=list;
 UniqueReferences used;
 EACH(list->first,Template,t) {
  used.Add(t->id.id.value);
 }
 unsigned int candidate=0;
 while ( candidate < MAX_INT && used.references(candidate) ) candidate++;
 id.Set(candidate);
}
