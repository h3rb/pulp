
/***********************************************************************************************
 * OpenGL Window and Animation Library (formerly the Open Art Engine)                          *
 ***********************************************************************************************
 * This software is copyrighted software.  Use of this code is given only with permission to   *
 * parties who have been granted such permission by its author, Herbert Elwood Gilliland III   *
 ***********************************************************************************************
 * Copyright (c) 2010 Herbert Elwood Gilliland III ; All rights reserved.                      *
 ***********************************************************************************************/

#pragma once
#include <stdio.h>
#include <stdarg.h>
#include <iostream>
#include <string>
using namespace std;
#include "macros.h"
#include "string_functions.h"
#include "LinkedList.h"

class String : public ListItem {
public:
 string s;
 int integer;
 float floating;
 char c;
 String() : ListItem() {
  s = string("");
  integer=0;
  floating=0.0f;
  c='\0';
 }
 String( const char *i ) : ListItem() {
  s=string(i);
  Numeric(i);
  c='\0';
 }
 String( string i ) : ListItem() {
  s=i;
  Numeric(i);
  c='\0';
 }
 String( string i, bool UsesSpecialCodes ) : ListItem() {
  s = UnStringSpecialCodes(i);
  Numeric(s);
  c='\0';
 }
 String( String *t ) : ListItem() {
  s=t->s;
  integer=t->integer;
  floating=t->floating;
  c='\0';
 }
 String *Clone() {
  String *s=new String(this);
  return s;
 }
 void Numeric( string str ) { Numeric(str.c_str()); }
 void Numeric( const char * i ) {
  if ( !str_cmp(i,"yes")
    || !str_cmp(i,"true")
    || !str_cmp(i,"t")
    || !str_cmp(i,"y")
    || !str_cmp(i,"1") ) {
   integer=1;
   floating=1.0f;
  }
  else
  if ( !str_cmp(i,"no")
    || !str_cmp(i,"false")
    || !str_cmp(i,"f")
    || !str_cmp(i,"n")
    || !str_cmp(i,"0" ) ) {
   integer=0;
   floating=0.0f;
  } else {
   integer=atoi(i);
   floating=(float)atof(i);
  }
 }
 char *c_str(void); // converts the node to a C-str
 virtual ListItem *Copy() {
  return (ListItem *) new String( this );
 }
 bool contains( char c ) {
  const char *p=s.c_str();
  while (*p != '\0') { if ( *p == c ) return true; p++; }
  return false;
 }
 virtual string toString() {
  string out=string("");
  out+=indention+string("{")+StringSpecialCodes(this->s)+string("}");
  if ( integer != 0 ) {
   char buf[80];
   FORMAT(buf,80," %d",(int) integer);
   out+=string(buf);
  }
  if ( floating != 0.0f ) {
   char buf[80];
   FORMAT(buf,80," %1.9f",(float) floating);
   out+=string(buf);
  }
  return out;
 }
};

class KeyValuePair : public String {
public:
 string value;
 KeyValuePair() : String() {
  s = string("");
  value = string("");
 }
 KeyValuePair( string s ) : String() { fromString(s); }
 KeyValuePair( KeyValuePair *t ) : String() {
  s=t->s;
  integer=t->integer;
  floating=t->floating;
  value=t->value;
 }
 KeyValuePair( const char *k, const char *v ) : String() {
  s = string(k);
  value = string(v);
  Numeric(v);
 }
 KeyValuePair( const char *k, int i ) : String() {
  static char buf[1024];
  integer=i;
  s = string(k);
  FORMAT( buf,1024, "%d", (int) i );
  value=string(buf);
 }
 KeyValuePair( const char *k, float f ) : String() {
  static char buf[1024];
  floating =f;
  s = string(k);
  FORMAT( buf,1024,  "%f", (float) f );
  value=string(buf);
 }
 virtual string toString() {
  return string(str_protect(s))+string(" ")+string(str_protect(s));
 }
 virtual void fromString( string in ) {
  const char *p=in.c_str();
  p=string_argument_case(p,&s);
  p=string_argument_case(p,&value);
 }
 void Set( int i ) {
  static char buf[1024];
  integer=i;
  floating=(float)i;
  FORMAT( buf,1024, "%d", (int) i );
  value=string(buf);
 }
 void Set( float f ) {
  static char buf[1024];
  integer = (int)f;
  floating =f;
  FORMAT( buf,1024,  "%f", (float) f );
  value=string(buf);
 }
 void Set( const char *v ) {
  value=string(v);
  Numeric(v);
 }
 void Set( const char *k, const char *v ) {
  s=string(k);
  value=string(v);
  Numeric(v);
 }
 virtual ListItem *Copy() {
  return new KeyValuePair( this );
 }
};

class Strings : public LinkedList {
public:
 Strings() : LinkedList() {}
 Strings( const char *filename ) : LinkedList() {
  Load(filename);
 } /* Returns a list of lines */
 bool prefix( string keyword ) {
  FOREACH(String,s) if ( !str_prefix(s->s.c_str(),keyword.c_str()) ) return true;
  return false;
 }
 bool matches( string keyword ) {
  FOREACH(String,s) if ( !str_cmp(s->s,keyword) ) return true;
  return false;
 }
 void fromSimpleString( const string& in ) {
  string piece=string("");
  const char *p=in.c_str();
  while ( *p != '\0' ) {
   p=string_argument(p,&piece);
   if ( piece.length() > 0 ) this->Add(piece);
  }
 }
 void fromSimpleString( const char *in ) {
  string piece=string("");
  const char *p=in;
  while ( *p != '\0' ) {
   p=string_argument(p,&piece);
   if ( piece.length() > 0 ) this->Add(piece);
  }
 }
 void fromSimpleStringCase( const string& in ) {
  string piece=string("");
  const char *p=in.c_str();
  while ( *p != '\0' ) {
   p=string_argument_case(p,&piece);
   if ( piece.length() > 0 ) this->Add(piece);
  }
 }
 void fromSimpleStringCase( const char *in ) {
  string piece=string("");
  const char *p=in;
  while ( *p != '\0' ) {
   p=string_argument_case(p,&piece);
   if ( piece.length() > 0 ) this->Add(piece);
  }
 }
 string toSimpleString() {
  string out=string("");
  FOREACH(String,s) {
   out+=string(str_protect(s->s.c_str()));
  }
  return out;
 }
 string toString() {
  string out=string("");
  incdent();
  FOREACH(String,s) {
   string classname=typeid(*s).name();
   string discard;
   const char *q=string_argument(classname.c_str(),&discard); // discards the words "class or struct"
   if ( !str_cmp(q,"String") ) out+=indention+string("string {\n")+s->toString()+string("}\n");
   else
   if ( !str_cmp(q,"KeyValuePair") ) {
    KeyValuePair *kv=(KeyValuePair *)s;
    out+=indention+string("kv {\n")+kv->toString()+string("}\n");
   }
  }
  decdent();
  return out;
 }
 virtual const char *ParseKey( const char *p, string key ) {
  string value;
  const char *out=p;
  if ( !str_cmp( key, "string" ) ) {
   out=string_argument_case(out,&value);
   this->Add(value);
  } else if ( !str_cmp( key, "kv" ) ) {
   out=string_argument_case(out,&value);
   this->Append(new KeyValuePair(value));
  }
  return out;
 }
 void Add( Strings *strings ) {
  EACH(strings->first,String,s) Append(s->Clone());
 }
 void Add( const char *s ) {
  String *S=new String(s);
//  S->integer=count;
  Append(S);
 }
 void Add( string s ) {
  String *S=new String(s);
//  S->integer=count;
  Append(S);
 }
 void Add( const char *s, char c ) {
  Append(new String(s));
  String *L=(String *) last;
  L->c=c;
 }
 void Add( char c, const char *s ) {
  Append(new String(s));
  String *L=(String *) last;
  L->c=c;
 }
 void Add( string s, char c ) {
  Append(new String(s));
  String *L=(String *) last;
  L->c=c;
 }
 void Add( char c, string s ) {
  Append(new String(s));
  String *L=(String *) last;
  L->c=c;
 }
 void Add( const char *s, int i ) {
  Append(new String(s));
  String *L=(String *) last;
  L->integer=i;
 }
 void Add( string s, int i ) {
  Append(new String(s));
  String *L=(String *) last;
  L->integer=i;
 }
 KeyValuePair *addKeyValue( const char *s, const char *v ) {
  KeyValuePair *k=new KeyValuePair( s, v );
  Append(k);
  return k;
 }
 KeyValuePair *addKeyValue( const char *s, int v ) {
  KeyValuePair *k=new KeyValuePair( s, v );
  Append(k);
  return k;
 }
 KeyValuePair *addKeyValue( const char *s, float v ) {
  KeyValuePair *k=new KeyValuePair( s, v );
  Append(k);
  return k;
 }
 void Load( const char *filename );  /* Returns a list of lines */
 void Save( const char *filename );
 bool inList( string s );
 String *matchPrefix( const char *s );
 String *match( const char *s );
 String *find( string s );
 String *find( const char *s );
 String *find( const char c ) {
  FOREACH(String,s) if ( s->c==c ) return s;
  return null;
 }
 String *find( int i ) {
  FOREACH(String,s) if ( s->integer==i ) return s;
  return null;
 }
 const char *AnyChar() {
  String *ele=(String *)Any();
  if ( !ele ) {
  OUTPUT("Strings:AnyChar() found no random element (is the list empty?)\n");
  }
  return ele->c_str();
 }
 const char *AnyChar( int seed ) {
  String *ele=(String *)Any(seed);
  if ( !ele ) {
  OUTPUT("Strings:AnyChar(%d) found no random element (is the list empty?)\n", (int) seed);
  }
  return ele->c_str();
 }
 const char *Chars( int i ) {
  FOREACH(String,s) if ( s->integer==i ) return s->s.c_str();
  OUTPUT("Strings:Chars(%d) reports no such element in list, returning empty string\n", (int) i);
  return &string_error;
 }
 string strings( int i ) {
  FOREACH(String,s) if ( s->integer==i ) return s->s;
  return string("");
 }
 String *findCaseless( string s );
 String *findCaseless( const char *s );
 String *findSubstring( const char *s );
 String *findNextSubstring( String *start, const char *s );
 string concatToNextSubstring( String *start, const char *end );
 int IndexOf( String *s );
 string Concatenate(void); // Returns duplicated concatenations of Strings
 string Concatenate( char seperator ); // Returns duplicated concatenations of Strings
 void appendFromString( const char *s, char c );
 void appendFromString( string s, char c );
 void show(void);
 void show( const char *sep, const char *end );
 void SplitPush( const char *s );
 void SplitPush( string s, char seperator );
 void SplitPush( const char *s, char seperator );
 void Push( string s );
 void Push( const char *s );
 String *PushAndGet( const char *s );
 void DuplicateAndPush( const char * s );
 void Copy( Strings *ss ) {
  EACH(ss->first,String,s) Append( s->Copy() );
 }
 void ClearThenCopy( Strings *ss ) {
  Clear();
  Copy(ss);
 }
 void printf( const char * fmt, ...) {
  char buf [32768];
  va_list args;
  va_start (args, fmt);
  vsnprintf(buf, 32766, fmt, args);
  va_end (args);
  Push(buf);
 }
 virtual int Compare( ListItem *a, ListItem *b ) { // alpha sort: 'a' is less than 'b'
  String *A=(String *)a;
  String *B=(String *)b;
  const char *p,*q;
  p=A->c_str(); while ( *p != '\0' && !IS_ALPHA(*p) ) p++;
  q=B->c_str(); while ( *q != '\0' && !IS_ALPHA(*q) ) q++;
  while ( *p!= '\0' && *q!='\0' ) {
   if ( (int) LOWER(*p) > (int) LOWER(*q) ) return 1;
   if ( (int) LOWER(*p) < (int) LOWER(*q) ) return -1;
   p++; while ( *p != '\0' && !IS_ALPHA(*p) ) p++;
   q++; while ( *q != '\0' && !IS_ALPHA(*q) ) q++;
  }
  if ( *p != '\0' ) return 1;
  if ( *q != '\0' ) return -1;
  return 0;
 }
 bool NotMatchesKeyValues( Strings *pairs ) {
  FOREACH(KeyValuePair,k) {
   KeyValuePair *kv=(KeyValuePair *) pairs->find(k->s);
   if ( kv->value != k->value ) return true;
  }
  return false;
 }
 virtual CLEARLISTRESET(String);
 ~Strings(void) { Clear(); }
};

class StringsHandle : public Handle<Strings> {
public:
};

class Stringses : public LinkedList {
public:
 CLEARLISTRESET(StringsHandle);
 ~Stringses() { Clear(); }
};

// Text File Handler
class TextFile {
public:
 FILE *fp;
 TextFile( const char *name, bool write ) {
  fp=fopen(name, ( write ? "w" : "r" ) );
 }
 ~TextFile() { if ( fp ) fclose(fp); }
 void Printf( const char *fmt, ... ) {
  va_list args;
  va_start (args, fmt);
  fprintf_s (fp, fmt, args);
  va_end (args);
 }
 void print( const char *s ) {
  fprintf(fp, "%s", s );
 }
 void print( string s ) {
  fprintf(fp, "%s", s.c_str() );
 }
};

Strings *ls( const char *targetPath, bool listFiles, bool prependPath, bool filterOSFiles );
Strings *ls( const char *targetPath, bool listFiles, bool prependPath, Strings *filters );
