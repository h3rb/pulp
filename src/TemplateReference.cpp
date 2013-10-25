#include "TemplateReference.h"

#include "Prototype.h"
#include "Genetics.h"
#include "Blueprint.h"

TemplateReference::TemplateReference( Prototype *p ) : ListItem() { Set(p); }

void TemplateReference::Set( Prototype *p ) {
 reference=ref_Prototype;
 prototype=p;
}

bool TemplateReference::references( Prototype *p ) {
 if ( reference != ref_Prototype ) return false;
 if ( prototype != p ) return false;
 return true;
}

TemplateReference::TemplateReference( Genetics *g ) : ListItem() { Set(g); }

void TemplateReference::Set( Genetics *g ) {
 reference=ref_Genetics;
 genetics=g;
}

bool TemplateReference::references( Genetics *g ) {
 if ( reference != ref_Genetics ) return false;
 if ( genetics != g ) return false;
 return true;
}

TemplateReference::TemplateReference( Blueprint *b ) : ListItem() { Set(b); }

void TemplateReference::Set( Blueprint *b ) {
 reference=ref_Blueprint;
 blueprint=b;
}

bool TemplateReference::references( Blueprint *b ) {
 if ( reference != ref_Blueprint ) return false;
 if ( blueprint != b ) return false;
 return true;
}

TemplateReference *TemplateReferences::Add( Prototype *p ) {
 TemplateReference *tr=new TemplateReference(p);
 Append(tr);
 return tr;
}

TemplateReference *TemplateReferences::Add( Genetics *g ) {
 TemplateReference *tr=new TemplateReference(g);
 Append(tr);
 return tr;
}

TemplateReference *TemplateReferences::Add( Blueprint *b ) {
 TemplateReference *tr=new TemplateReference(b);
 Append(tr);
 return tr;
}

TemplateReference *TemplateReference::find( Prototype *p ) {
 FOREACH(TemplateReference,tr) if ( tr->prototype == p ) return tr;
 return null;
}

TemplateReference *TemplateReference::find( Genetics *g ) {
 FOREACH(TemplateReference,tr) if ( tr->genetics == g ) return tr;
 return null;
}

TemplateReference *TemplateReference::find( Blueprint *b ) {
 FOREACH(TemplateReference,tr) if ( tr->blueprint == b ) return tr;
 return null;
}

void TemplateReferences::Remove( Prototype *p ) {
 TemplateReference *tr=find(p);
 if ( tr ) Remove(tr);
}

void TemplateReferences::Remove( Genetics *g ) {
 TemplateReference *tr=find(g);
 if ( tr ) Remove(tr);
}

void TemplateReferences::Remove( Blueprint *b ) {
 TemplateReference *tr=find(b);
 if ( tr ) Remove(tr);
}
