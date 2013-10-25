
/***********************************************************************************************
 * OpenGL Window and Animation Library (formerly the Open Art Engine)                          *
 ***********************************************************************************************
 * This software is copyrighted software.  Use of this code is given only with permission to   *
 * parties who have been granted such permission by its author, Herbert Elwood Gilliland III   *
 ***********************************************************************************************
 * Copyright (c) 2010 Herbert Elwood Gilliland III ; All rights reserved.                      *
 ***********************************************************************************************/
#include "Strings.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>

// String

char *String::c_str() {
 return (char *) this->s.c_str();
}

// Strings

void Strings::Load( const char *filename )
{
 Clear();
 FILE *f;
 f=fopen(filename, "r");
 if(f) {
  while(!feof(f))
  {
   char temp[STRING_SIZE];
   int ch=0;
   int i=0;
   while ( (ch=fgetc(f)) != EOF && (char) ch != '\n' && !feof(f) ) temp[i++] =(char) ch;
   temp[i]='\0';
   String *t; NEW(t,String(temp));
   Append(t);
  }
  fclose(f);
 }
 else OUTPUT("File not found: %s\n", filename);
}

void Strings::Save( const char *filename )
{
 Clear();
 FILE *f;
 f=fopen(filename, "w");
 if(f)
 {
  fclose(f);
  std::fstream filestr;
  filestr.open(filename, std::fstream::in | std::fstream::out );
  FOREACH(String,s) filestr<<s->s.c_str()<<endl;
  filestr.close();
 }  
 else OUTPUT("File not writeable: %s\n", filename);
}

bool Strings::inList( string s ) {
 FOREACH(String,sL) if ( s == sL->s ) return true;
 return false;
}

String *Strings::matchPrefix( const char *s ) {
 FOREACH(String,sL) if ( sL->s.length() > 0 && strlen(s) > 0 && !str_prefix(sL->c_str(),s) ) return sL;
 return null;
}

String *Strings::match( const char *s ) {
 FOREACH(String,sL) if ( !str_cmp(sL->c_str(),s) ) return sL;
 return null;
}

String *Strings::find( string s ) {
 FOREACH(String,sL) if ( s == sL->s ) return sL; 
 return null;
}

String *Strings::find( const char *s ) {
 string f=string(s);
 FOREACH(String,sL) if ( f == sL->s ) return sL; 
 return null;
}

String *Strings::findCaseless( const char *s ) {
 string f=string(s);
 FOREACH(String,sL) if ( !str_cmp(s, sL->s.c_str() ) ) return sL; 
 return null;
}

String *Strings::findCaseless( string s ) {
 string f=string(s);
 FOREACH(String,sL) if ( !str_cmp((char *) s.c_str(), (char *) sL->s.c_str() ) ) return sL; 
 return null;
}

 String *Strings::findSubstring( const char *s ) {
  FOREACH(String,sL) if ( !str_prefix(sL->s.c_str(),s) ) return sL; 
  return null;
 }

 String *Strings::findNextSubstring( String *start, const char *s ) {
  String *sL=start;
  while ( sL && string_infix(s,sL->s) ) sL=(String *) sL->next;
  return sL;
 }

 string Strings::concatToNextSubstring( String *start, const char *end ) {
  String *e = this->findNextSubstring(start,end);
  string x=string("");
  String *sL=start;
  while ( sL && sL != e ) { x+=sL->s+string("\n"); sL=(String *) sL->next; }
  return x;
 }

// Returns -1 if not in list
int Strings::IndexOf( String *s ) {
 int i=0;
 FOREACH(String,sL) {
  if ( s == sL ) return i;
  else i++;
 }
 return -1;
}

// Returns duplicated concatenations of Strings
string Strings::Concatenate( char seperator ) {
 string e = string("");
 FOREACH(String,sL) {
  e=e+sL->s;
  e.append( 1, seperator );
 }
 return e;
}

// Returns duplicated concatenations of Strings
string Strings::Concatenate( ) {
 string e = string("");
 FOREACH(String,sL) {
  e=e+sL->s+string("\n");
 }
 return e;
}

void Strings::appendFromString( const char *s, char c ) {
 char temp[STRING_SIZE];
 const char *p= s;
 int i=0;
 while ( *p != '\0' ) {
  if ( *p==c ) {
   temp[i]='\0';
   String *t; NEW(t,String(temp));
   Append(t);
   i=0;
  } else
  temp[i++] =*p;
  p++;
 }
}

void Strings::appendFromString( string s, char c ) {
 appendFromString( (char *) s.c_str(), c );
}

void Strings::show() 
{ 
 FOREACH(String,s) OUTPUT( "%s\n", s->s.c_str() ); 
}

void Strings::show( const char *sep, const char *end ) 
{ 
 FOREACH(String,s) OUTPUT( "%s%s", s->s.c_str(), (s->next ? sep : "") );
 OUTPUT("%s",end);
}

// Splits using string_argument
void Strings::SplitPush( const char *s ) {
 string t;
 const char *p=s;
 while ( *p != '\0' ) {
  string t;
  p=string_argument(p,&t);
  if ( t.length() > 0 ) Push(t);
 }
}

void Strings::SplitPush( const char *s, char seperator ) {
 string t;
 static char buf[2];
 const char *p=s;
 buf[0]=seperator;
 buf[1]='\0';
 while ( *(p=gather_to(p,buf,&t)) != '\0' ) Push(t);
 if ( t.length() > 0 ) Push(t);
}

void Strings::SplitPush( string s, char seperator ) {
 string t;
 static char buf[2];
 const char *p= s.c_str();
 buf[0]=seperator;
 buf[1]='\0';
 while ( (p=gather_to(p,buf,&t)) != '\0' ) Push(t);
}

void Strings::Push( string s ) {
 String *t;
 NEW(t,String(s));
 Append(t);
}

void Strings::Push( const char *s ) {
 String *t;
 NEW(t,String(s));
 Append(t);
}

String *Strings::PushAndGet( const char *s ) {
 String *x; NEW(x,String(string(s)));
 Append(x);
 return x;
}

void Strings::DuplicateAndPush( const char *s ) { // No longer different
 String *t;
 NEW(t,String(s));
 Append( t );
}

// List directory contents
// http://msdn.microsoft.com/en-us/library/aa365200%28VS.85%29.aspx
// When listFiles parameter is false, find only subfolder names.
Strings *ls( const char *targetPath, bool listFiles, bool prependPath, bool filterOSFiles=true ) {
 return new Strings;
}

Strings *ls( const char *targetPath, bool listFiles, bool prependPath, Strings *filters ) {
 return new Strings;
}
