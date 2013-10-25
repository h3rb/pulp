#pragma once

#include "LinkedList.h"

/*
 * Single color.
 */

class AColor : public ListItem {
public:
 Zstring name;     // unique name, single word, hyphens when needed, human readible (orange, chartreuse, mac-n-cheese, vermillion-red, burnt-ochre)
 Zstring hex;      // CSS code
 Zstring ansi;     // Nearest ANSI 16-color (actual code)
 Zstring ansi_cc;  // Color code (found with OutputANSI class)
 Zstring pulpcode; // How to render this is long-form pulpcode
 Zstring xterm;    // Nearest xTerm color code (actual code)
 Zdouble r,g,b;
 void Defaults() {
  hex=string("000000");
  ansi=string("\x01B[0m");
 }
 AColor( double r, double g, double b ) : public ListItem {
  Defaults();
  this->r=r;
  this->g=g;
  this->b=b;
 }
 AColor( const char *name, double r, double g, double b ) : public ListItem {
  Defaults();
  this->name=string(name);
  this->r=r;
  this->g=g;
  this->b=b;
 }
 void Set() {
 }
 string Hex() {
  return hex.value;
 }
 string Ansi() {
  return ansi.value;
 }
};

/*
 * Color collection.
 */

class AColors : public LinkedList {
public:
 AColor *find( double r, double g, double b ) {
 }
 AColor *findHex( const char *hex ) {
 }
 AColor *findANSI( const char *ansi ) {
 }
 AColor *findColorCode( const char *code ) {
 }
 AColor *findXTerm( const char *code ) {
 }
 AColor *findPulpcode( const char *pulpcode ) {
 }
 AColor *nearest( double r, double g, double b ) {
 }
 AColor *nearestHex( const char *hex ) {
 }
 AColor *nearestANSI( const char *ansi ) {
 }
 AColor *nearestColorCode( const char *cc ) {
 }
 AColor *nearestXTerm( const char *code ) {
 }
 AColor *nearestPulpcode( const char *code ) {
 }
};

/* Look-up optimization for large numbers of stored color codes. */

class APalette : public ListItem {
public:
 Zstring name;
 Indexed<AColors> hash;
 Zdouble delta;
 APalette( unsigned int hashes ) {
  hash.resize(hashes);
  delta=(double)hashes/1.0;
 }
 void Insert( AColor *a ) {
  double index=(a->r+a->g+a->b)/3.0;
  unsigned int key=(unsigned int)(index/delta);
  hash(key).Append(a);
 }
 void Remove( AColor *a ) {
  double index=(a->r+a->g+a->b)/3.0;
  unsigned int key=(unsigned int)(index/delta);
  hash(key).Remove(a);
 }
};

class APalettes : public LinkedList {
public:
 APalette *find( const char *c ) {
  FOREACH(APalette,a) if ( !str_cmp(a->name.c_str(),c) ) return a;
  return null;
 }
 CLEARLISTRESET(APalette);
};

extern APalettes palettes;
