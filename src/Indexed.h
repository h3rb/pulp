#pragma once
#include "macros.h"
#include "string_functions.h"

#if defined(LINUX)
#define SIZE_T size_t
#endif

// Lightweight vector.

template<class T>
class Indexed {
public:
 T oob;
 T *list;
 size_t length,w,h;
 Indexed() {
  w=h=0;
  length=0;
  list=null;
  ZeroMemory(&oob,(SIZE_T)sizeof(T));
 }
 Indexed( size_t length ) { Size(length); }
 Indexed( size_t w, size_t h ) { Size(w,h); }
 void Swap( Indexed<T> *values ) {
  T *tempList = list;
  size_t tempLength = length;
  size_t tempW = w;
  size_t tempH = h;
  list=values->list;
  length=values->length;
  w=values->w;
  h=values->h;
  values->list=tempList;
  values->length=tempLength;
  values->w=tempW;
  values->h=tempH;
 }
 void Size( size_t w, size_t h ) {
  Size(w*h);
  this->w=w;
  this->h=h;
 }
 void Size( size_t desiredLength, bool keep ) {
  if ( length==desiredLength ) return;
  if ( desiredLength == 0 ) {
   if ( list ) delete[] list;
   list=null;
   length=0;
   return;
  }
  if ( list ) {
   T *newlist;
   NEW(newlist,T[desiredLength]);
   int kept=length < desiredLength ? length : desiredLength;
   for ( int i=0; i<kept; i++ ) newlist[i]=list[i];
   delete[] list;
   list=newlist;
  } else {
   length=desiredLength;
   NEW(list,T[desiredLength]);
  }
 }
 void Size( size_t desiredLength ) {
  if ( length==desiredLength ) return;
  if ( desiredLength == 0 ) {
   if ( list ) delete[] list;
   list=null;
   length=0;
   return;
  }
  if ( list ) {
   delete[] list;
   NEW(list,T[desiredLength]);
  } else {
   NEW(list,T[desiredLength]);
  }
  length=desiredLength;
 }
 T *Element( unsigned int index ) {
  return list[index];
 }
 T *Element( unsigned int x, unsigned int y ) {
  return list[x+y*h];
 }
 T *Element( unsigned int index, bool boundaryCheck ) {
  if ( index >= (unsigned int) length ) return null;
  return list[index];
 }
 T *Element( unsigned int x, unsigned int y, bool boundaryCheck ) {
  int index=x+y*h;
  if ( index > (unsigned int) length ) return null;
  return list[x+y*h];
 }
 T Value( unsigned int index ) {
  return *list[index];
 }
 T Value( unsigned int x, unsigned int y ) { // unbounded
  return list[x+y*h];
 }
 T Value( unsigned int index, bool boundaryCheck ) {
  if ( index >= (unsigned int) length ) return oob;
  return *list[index];
 }
 T Value( unsigned int x, unsigned int y, bool boundaryCheck ) {
  int linear=x+y*h;
  if ( linear > (unsigned int) length ) return oob;
  return list[linear];
 }
 T &Wrap(int index) {
#if defined(DEBUG) || defined(DEBUG_OUTPUT)
  if ( length == 0 ) {
   OUTPUT("Warning: length was 0 when Indexed<T>.Wrap() was called\n");
   return oob;
  }
#endif
  return (*this)[(int)abs(index)%length];
 }
 T &operator[] (unsigned int index) {
#if defined(DEBUG) || defined(DEBUG_OUTPUT)
  if ( index >= (unsigned int) length ) {
   OUTPUT("Warning: %d was out of bounds when requested on type %s\n",
    (int) index, typeid(*this).name());
   return oob;
  }
#endif
  return list[index];
 }
 T &operator() (unsigned int x, unsigned int y) {
  unsigned int linear=(unsigned int)(x+y*h);
#if defined(DEBUG) || defined(DEBUG_OUTPUT)
  if ( linear >= (unsigned int) length ) {
   OUTPUT("Warning: %d (%d,%d) was out of bounds when requested on type %s\n",
    linear, (int)x, (int)y, typeid(*this).name());
   return oob;
  }
#endif
  return list[linear];
 }
 T &operator() (unsigned int index) {
  return list[index];
 }
 ~Indexed() {
  if ( list ) delete[] list;
 }
};
