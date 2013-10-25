/***********************************************************************************************
 * OpenGL Window and Animation Library (formerly the Open Art Engine)                          *
 ***********************************************************************************************
 * This software is copyrighted software.  Use of this code is given only with permission to   *
 * parties who have been granted such permission by its author, Herbert Elwood Gilliland III   *
 ***********************************************************************************************
 * Copyright (c) 2010 Herbert Elwood Gilliland III ; All rights reserved.                      *
 ***********************************************************************************************/

#pragma once
#include "macros.h"
#include "moremath.h"
#include "string_functions.h"

#include "ListItem.h"

//#include "utlist.h" // DL_SORT, doesn't work right.

// Instead of using a template
#define CLEARLIST(t)   void Clear() { \
   t *n; for ( t *p=(t *) first; p; p=n ) { \
    n=(t *)(p->next); delete p; \
   } \
  }
#define CLEARLISTRESET(t)   void Clear() { \
   t *n; for ( t *p=(t *) first; p; p=n ) { \
    n=(t *)(p->next); delete p; \
   } \
   first=null; last=null; count=0; \
  }
#define ADDLIST(t,r,h)  void Add( t *p ) { h *s= new h(); s->r=p; Append(s); }
#define ADDLISTNAMED(a,t,r,h) void Add( t *p ) { h *s= new h(); s->r=p; s->name=a; Append(s); }
#define FOREACH(t,v)  for ( t *v=(t *) first; v; v=(t *) v->next )
#define FOREACHN(t,v,c) { t *n; for ( t *v=(t *) first; v; v=(t *) n ) { n=(t *)v->next; c } }
#define FOREACHREV(t,v) for ( t *v=(t *) last; v; v=(t *) v->prev )
#define EACH(head,t,v)  for ( t *v=(t *) head; v; v=(t *) v->next )
#define EACHN(head,t,v,c) { t *n; for ( t *v=(t *) head; v; v=n ) { n=(t *) v->next; c } }

#define RENDERLIST(ts,t) class ts : public LinkedList { public: CLEARLISTRESET(t); void Render( GLWindow *surface ) { FOREACH(t,g) g->Render(surface); } void Between() { FOREACH(t,g) g->Between(); } };
#define RENDERLIST2(t) RENDERLIST(ts,t);

#define COLLECTION(t,i) class t : public LinkedList { public: CLEARLISTRESET(i); }

#define LL_SORTER(sort,plural,single,compare) \
 void sort() { \
  if ( count < 2 ) return; \
  plural list; list.first=first; list.last=last; list.count=count; \
  single *q=(single *) list.first; list.Remove(q); Append(q); \
  while(list.first) { \
   single *p=(single *) list.first; list.Remove(p); \
   bool inserted=false; \
   EACH(this->first,single,t) { \
    int result=this->compare(p,t); \
    if ( result <= 0 ) { \
     this->InsertBefore(p,t); inserted=true; break; \
    } \
   } \
   if ( !inserted ) Append(p); \
  } \
 }

class LinkedList : public ListItem {
public:
	Zint count;
	ListItem *first;
	ListItem *last;

	LinkedList(void) : ListItem() { first=last=null; }

 /* Textual storage */
 void fromString( string in ) { fromString(in.c_str()); }
 virtual void fromString( const char *in ) {
  const char *p=in;
  string one=string("");
  while ( *p != '\0' ) {
   p=string_argument( p, &one );
   if ( one.length() > 0 ) AppendFromString(one);
  }
 }
 virtual void AppendFromString( string one ) {}

 /* Binary file storage */
 virtual void BinaryRead( BinaryFile *open ); // default works in most cases
 virtual void BinaryWriteData( BinaryFile *open ) {}
 virtual void BinaryReadData( BinaryFile *open ) {}
 virtual void ReadAppend( BinaryFile *open ) {}
 virtual void BinaryWrite( BinaryFile *open ); // default works in most cases

 virtual string identity() { ///RTTI///
  string classname=string(typeid(*this).name());
  string discard;
  const char *q=string_argument((char *)classname.c_str(),&discard); // discards the words "class or struct"
  return string(q);
 }
 virtual string identity( bool useChar ) { ///RTTI///
  const char *classname=typeid(*this).name();
  string discard;
  const char *q=string_argument(classname,&discard); // discards the words "class or struct"
  return string(q);
 }

 bool ListIteminList( ListItem *item ) {
  FOREACH(ListItem,i) if ( i==item ) return true;
  return false;
 }
 virtual int Compare( ListItem *a, ListItem *b ) {
   if ( a>b ) return 1;
   if ( a<b ) return -1;
   return 0;
 }

 virtual int Compare( ListItem *a, ListItem *b, void *value ) {
   if ( a>b ) return 1;
   if ( a<b ) return -1;
   return 0;
 }

 virtual void PrecomputeSort() {}
 void Sort();
 void Sort( void *relative );
// void MergeSort() {
//  if ( count < 2 ) return;
//  DL_SORT(first,Compare);
// }

 // Sorts just the top N in the list
 void TopSort( int N ) {
 }

 void Up(ListItem *L, bool wrap);
 void Down(ListItem *L, bool wrap);
 virtual void Append(ListItem *L);
 void _Append(ListItem *L);
 void Prepend(ListItem *L);
 ListItem *Element(int i);
 virtual ListItem *Any() {
  if ( (int)count==0 ) return null;
  if ( (int)count==1 ) return first;
  return Element(upto((int)count*1234)%(int)count);
 }
 virtual ListItem *Any( int seed );
 int IndexOf( ListItem *L ) { int i=0; FOREACH(ListItem,item) { if ( item == L ) break; i++; } return i; }
 void InsertBefore(ListItem *insert,ListItem *before);
 void InsertAfter(ListItem *insert, ListItem *after);
 void InsertAt(ListItem *insert, int i);
 void _Remove(ListItem *L);
 void Remove(ListItem *L) { _Remove(L); }
 void RemoveAll(void);
 void Delete(ListItem *L);
 void AppendAndDispose( LinkedList *toAppend ) {
  Concat(toAppend);
  delete toAppend;
 }
 //void DeleteAll(void);//never, use CLEARLIST(class) macro

 void RandomizeOrder();
 void RandomizeOrder(int seed);
 void ReverseOrder() {
  LinkedList temporary;
  EACHN(first,ListItem,L,{
   Remove(L);
   temporary.Prepend(L);
  });
  this->first=temporary.first;
  this->last=temporary.last;
  this->count=temporary.count;
  temporary.first=temporary.last=NULL;
  temporary.count=0;
 }

 void Concat( LinkedList *L ) {
  if ( L->count <= 0 ) return;
  if ( count == 0 ) {
   count=L->count;
   first=L->first;
   last=L->last;
  } else {
   count+=L->count;
   last->next=L->first;
   last=L->last;
  }
  L->first=null;
  L->last=null;
  L->count=0;
 }

 virtual void Clear() {
//#if defined(DEBUG)
  if ( first ) EACHN(first,ListItem,L,{
   Remove(L);
   delete L;
  });
  count=0;
  last=first=null;
//#endif
 }
 virtual ~LinkedList() { 
  Clear();
 }
};

class Handles : public LinkedList {
public:
};

#if defined(NEVER)
// See HANDLE and related macro options in LinkedList.h
template <class T,class H> class Handles : public LinkedList {
public:
 Handles() : LinkedList() {}
 void Add( T *item ) {
  H *o=new H;
  H->p=item;
  Append((ListItem *) o);
 }
 H *find( string s ) { return find((char*)s.c_str()); }
 virtual T *find( char *s ) {
 }
 virtual CLEARLISTRESET(H);
 virtual ~Handles() { Clear(); }
};
#endif

/// Template ///

/// You can use TLinkedList only when you don't want hand-holding with BinaryFile, ///
///    and no default Any(seed) ///

template<class V>
class TLinkedList : public ListItem {
public:
	Zint count;
	V *first;
	V *last;

	TLinkedList(void) : ListItem() { first=last=null; }

 virtual string identity() { ///RTTI///
  string classname=typeid(*this).name();
  string discard;
  char *q=string_argument((char *)classname.c_str(),&discard); // discards the words "class or struct"
  return string(q);
 }
 virtual string identity( bool useChar ) { ///RTTI///
  static string classname=typeid(*this).name();
  string discard;
  static char *q=string_argument((char *)classname.c_str(),&discard); // discards the words "class or struct"
  return (q);
 }

 virtual int Compare( ListItem *a, ListItem *b ) {
   if ( a>b ) return 1;
   if ( a<b ) return -1;
   return 0;
 }

 virtual int Compare( ListItem *a, ListItem *b, void *value ) {
   if ( a>b ) return 1;
   if ( a<b ) return -1;
   return 0;
 }

 void Sort() {
  if ( count < 2 ) return;
  LinkedList list;
  list.first=first;
  list.last=last;
  list.count=count;
  ListItem *q=list.first;
  list.Remove(q);
  last=first=null;
  count=0;
  Append(q);
  while(list.first) {
   ListItem *p=list.first;
   list.Remove(p);
   bool inserted=false;
   EACH(this->first,ListItem,t) {
    int result=this->Compare(p,t);
    if ( result <= 0 ) {
     this->InsertBefore(p,t);
     inserted=true;
     break;
    }
   }
   if ( !inserted ) Append(p);
  }
 }
// void MergeSort() {
//  if ( count < 2 ) return;
//  DL_SORT(first,Compare);
// }

 // Sorts just the top N in the list
 void TopSort( int N ) {
 }

 void Up(V *L, bool wrap) {} // not yet implemented
 void Down(V *L, bool wrap) {} // not yet implemented
 virtual void Append(V *L) {
  _Append(L);
 }
 void _Append(V *L) {
  count++;
  if ( last ) { 
   last->next=L;
   L->prev=last; 
   L->next=null;
   last=L; 
   return; 
  }
  L->next=L->prev=null;
  first=last=L;
 }
 void Prepend(V *L) {
  count++;
  if ( first ) {
   first->prev=L;
   L->next=first;
   L->prev=null;
   first=L;
   return;
  }
  L->next=L->prev=null;
  first=last=L;
 }
 V *Element(int i) {
  V *l;
  int c=0;
  for ( l=first; l; l=l->next ) {
   if ( c==i ) return l;
   c++;
  }
  return null;
 }
 virtual V *Any() {
  if ( count==0 ) return null;
  return Element(upto(count*1234)%count);
 }
 int IndexOf( V *L ) { int i=0; FOREACH(V,item) { if ( item == L ) break; i++; } return i; }
 void InsertBefore(V *insert,V *before) {
  if ( !before ) { Prepend(insert); return; }
  insert->prev=before->prev;
  if ( insert->prev ) insert->prev->next=insert;
  insert->next=before;
  before->prev=insert;
  if ( before == first ) first=insert;
  count++;
 }
 void InsertAfter(V *insert, V *after) {
  if ( !after ) { Prepend(insert); return; }
  insert->next=after->next;
  if ( insert->next ) insert->next->prev=insert;
  after->next=insert;
  insert->prev=after;
  if ( after == last ) last=insert;
  count++;
 }
 void InsertAt(V *insert, int i) {
  V *p=Element(i);
  InsertBefore(insert,p);
 }
 void Remove(V *L)  {
  if ( first==L ) {
   if ( first==last ) {
    first=last=null; 
    L->next=L->prev=null;
    count=0;
    return;
   }
   first=first->next;
   if ( first ) first->prev=null;
   L->next=L->prev=null;
   count--;
   return;
  }
  if ( last==L ) {
   last=last->prev;
   if ( last ) last->next=null;
   L->next=L->prev=null;
   count--;
   return;
  }
  V *p,*n;
  p=L->prev;
  n=L->next;
  p->next=n;
  n->prev=p;
  L->next=L->prev=null;
  count--;
  return;
 }
 void RemoveAll(void) {
  first=last=null;
  count=0;
 }
 void Delete(V *L) {
  Remove(L);
  delete L;
 }
 void AppendAndDispose( TLinkedList *toAppend ) {
  Concat(toAppend);
  delete toAppend;
 }
 //void DeleteAll(void);//never, use CLEARLIST(class) macro

 void Concat( TLinkedList *L ) {
  if ( L->count <= 0 ) return;
  if ( count == 0 ) {
   count=L->count;
   first=L->first;
   last=L->last;
  } else {
   count+=L->count;
   last->next=L->first;
   last=L->last;
  }
  L->first=null;
  L->last=null;
  L->count=0;
 }

 virtual void Clear() {
   V *n;
   for ( V *p=(V *) first; p; p=n ) {
    n=(V *)(p->next);
    delete p;
   }
   first=last=null;
   count=0;
 }

 virtual ~TLinkedList() { 
  Clear();
 }
};


/// HANDLES ///

// Internal unnamed handles
#define HANDLING(single,handle,singlekey) \
 class handle:public ListItem{public: \
  Zp<single> p; \
  handle():ListItem() { } \
  void fromString(char *st) { \
   p.Delete(); \
   p=new single; \
   p->fromString(st); \
  } \
  virtual string toString() { \
   if(p) return p->toString(); \
   else return string(""); \
  } \
 };

#define HANDLINGS(single,handle,handles,singlekey) \
 class handles:public LinkedList{public: \
  virtual handle*Add(single*q) { \
   handle*n=new handle; \
   n->p=q; \
   Append(n); \
   return n; \
  } \
  void Delete(single*r){ FOREACH(handle,n) if(n->p==r){ Remove(n);delete n;return;} } \
  CLEARLISTRESET(handle); \
 };

// Mega-handle without names
#define HANDLED(single,handle,handles,handleshandle,handleshandles) \
 class handles; class handleshandle; class handleshandles; \
 class handle:public ListItem{ public:\
  Zp<single> p; \
  Zp<handles> parent; \
  virtual void fromString(char *st) { p->fromString(st); } \
  virtual void fromString(string k) { p->fromString((char*)k.c_str()); } \
  virtual string toString() { return p->toString(); } \
 }; \
 class handles:public LinkedList{ public:\
  virtual handle*Add(single*q) {\
   handle*n=new handle; \
   n->p=q; \
   n->parent=this; \
   Append(n); \
   return n; \
  } \
  single *find(single *q) { FOREACH(handle,s) if ( s->p==q ) return s->p; return null; } \
  handle *find(single *q,bool returnHandle) { FOREACH(handle,s) if ( s->p==q ) return s; return null; } \
  void Delete(single*r){ FOREACH(handle,n) if(n->p==r){Remove(n);delete n;return;} } \
  CLEARLISTRESET(handle); \
  ~handles(){Clear();} \
 }; \
 class handleshandle:public ListItem{ public:\
  Zp<handles> p; \
  Zp<handleshandles> parent; \
 }; \
 class handleshandles:public LinkedList{ public: \
  handleshandle*Add(handles*q){ \
   handleshandle*n=new handleshandle; \
   n->p=q; \
   n->parent=this; \
   Append(n); \
   return n; \
  } \
  handles *find(handles *q) { FOREACH(handleshandle,s) if ( s->p==q ) return s->p; return null; } \
  void Delete(handles *r) { FOREACH(handleshandle,s)if(s->p==r){Remove(s);delete s;return;} } \
  CLEARLISTRESET(handleshandle); \
  ~handleshandles(){Clear();} \
 };

// Class Name, Class Handle Class Name, Plural Handle Class Name, Plural Plural Handles Class Name
#define HANDLES(single,handle,handles,singlekey) HANDLING(single,handle,singlekey) HANDLINGS(single,handle,handles,singlekey);

// Defines classes under a named handle
#define NAMED(single,handle,handles)  class handles; \
 class handle:public ListItem{ public: \
  Zstring name; \
  Zp<single> p; \
  Zp<handles> parent; \
 }; \
 class handles:public LinkedList{ public: \
 virtual handle*Add(single*q,string m) { \
  handle*n=new handle; \
  n->name=m; \
  n->p=q; \
  n->parent=this; \
  Append(n); \
  return n; \
 } \
 handle*find(string k){ \
  FOREACH(handle,n) if(!str_cmp((char*)n->name.c_str(),(char*)k.c_str())) return n; \
  return null; \
 } \
 void Delete(single*r){ \
  FOREACH(handle,n) if(n->p==r){Remove(n);delete n;return;} \
 } \
 CLEARLISTRESET(handle); \
 ~handles(){Clear();} \
 };
