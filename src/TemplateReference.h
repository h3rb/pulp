#pragma once

#include "LinkedList.h"

/*
 * A template reference.
 */

/* Forward declarations */
class Prototype;
class Genetics;
class Blueprint;

enum TemplateReferenceType {
 ref_Unset=-1,
 ref_Prototype=0,
 ref_Genetics=1,
 ref_Blueprint=2
};

class TemplateReference : public ListItem {
public:
 TemplateReferenceType reference;
 Zp<Prototype> prototype;
 Zp<Genetics> genetics;
 Zp<Blueprint> blueprint;
 TemplateReference() : ListItem() {
  reference=ref_Unset;
 }
 TemplateReference( Prototype *p );
 TemplateReference( Genetics *g );
 TemplateReference( Blueprint *b );
 void Set( Prototype *p );
 void Set( Genetics *g );
 void Set( Blueprint *b );
 bool references( Prototype *p );
 bool references( Genetics *g );
 bool references( Blueprint *b );
};

class TemplateReferences : public LinkedList {
public:
 TemplateReference *Add( Prototype *p );
 TemplateReference *Add( Genetics *g );
 TemplateReference *Add( Blueprint *b );
 TemplateReference *find( Prototype *p );
 TemplateReference *find( Genetics *g );
 TemplateReference *find( Blueprint *b );
 void Remove( Prototype *p );
 void Remove( Genetics *g );
 void Remove( Blueprint *b );
 CLEARLISTRESET(TemplateReference);
};
