#pragma once
#define LINUX

#if defined(LINUX)
#define strcat_s strcat
#define strcpy_s strcpy
#define fprintf_s fprintf
#if !defined(NULL)
#define NULL 0
#endif
#define nullptr NULL
#endif


#include <cstdlib>
#include <cstdarg>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cctype>

using namespace std;

#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdarg.h>
#include <errno.h>

#define errno_t int

#include "macros.h"

class Zstring;

extern char buf[STRING_SIZE];
extern char buf2[STRING_SIZE];
extern char buf3[STRING_SIZE];

void InitWorkStrings();

// The only non-string function, put here for reasons similar to ls() functions in Strings.h
// Does not "recursively create"
bool make_folder( const char *targetPath );

extern const char string_error;

#ifndef LOWER
#define LOWER(c) ((c) >= 'A' && (c) <= 'Z' ? (c)+'a'-'A' : (c))
#endif

#define ALPHANUMERIC "abcdefghijklmnopqrstuvwxyz0123456789"
#define ALPHACHAR "abcdefghijklmnopqrstuvwxyz"

// Useful testers, trimmers, etc.
void trim( string *toworkon );

// Stores a log
#define OUTPUT printf
//void OUTPUT(const char *fmt, ... );

// Formats a string
string FORMAT(char *b, int len, const char *fmt, ...);
string FORMAT(const char*fmt, ...);
string FORMAT(string fmt, ...);

// Tests string contents
bool contains( const char *astr, const char *bstr );
bool contains( string s, char c );
bool contains( const char *s, char c );
int count_char( const char *s, char c );
int count_char( string s, char c );
bool endsWith( const char *astr, const char *bstr, bool removePadding );
bool endsWith(string const &fullString, string const &ending);
bool hasEnding(std::string const &fullString, std::string const &ending);
bool hasEnding( const char *searching, const char *find, bool caseSensitive, bool unpad );
bool hasEnding( string const &searching, const char *find, bool caseSensitive, bool unpad );
bool hasEnding( string const &searching, string const &find, bool caseSensitive, bool unpad );

// Classic string functions
char *copy_to_string( char *write_to, const char *value );
int char_is_of( char c, const char *list );
char randomChar( const char *list );
bool char_in(char c, char *list );
char *fix_string( const char *str );
string is_are( const char *text );
char *smash_arg( const char *text, const char *name );
char *smash_article( const char *text );
char *pluralize( const char *argument );
char *wordwrap( const char *oldstring /*, bool fSpace */);
string paragraph( const char *oldstring, const char *prefix, int width, bool fEnd );
char *replace_string( const char *orig, const char *old, const char *n );
void replace_char( char *orig, char old, char n);
int words( const char *argument );
char * string_unpad( const char * argument );
char * string_proper( char * argument );
inline bool is_digit( char c );
bool is_integer( const char *arg );
bool is_decimal( const char *arg );
bool is_int( string k );
bool is_hex( string k );
bool is_float( string k );
int from_hex( string hex );
string to_hex( int i );
int number_argument( const char *argument, char *arg );
const char *one_argument( const char *argument, char *arg_first );
const char *string_argument( const char *argument, string *arg_first );
const char *string_argument( const char *argument, Zstring *arg_firstz );
const char *string_argument_case( const char *argument, string *arg_first );
const char *string_argument_end( const char *argument, string *arg_first, char *sep );
const char *gather_to( const char *argument, const char *substr, string *buf );
const char *gather_to( const char *argument, string *out, char sep );
const char *gather_to( const char *argument, string *out, char sep, char orsep );
const char *first_split( const char *argument, char *arg_first, char sep );
string first_word( string in, string *out );
const char *one_argcase( const char *argument, char *arg_first );
const char *pop_1stline( const char *argument, string *out );
char * strupper( char * s );
char * strlower( char * s );
string lower( string a );
bool is_name( const char *str, const char *namelist );
bool is_prename( const char *str, const char *namelist );
bool valid_characters( const char *fn );
char *ntos( float n, const char *fmt );
void smash_char( const char *str, char c );
bool str_cmp( const char *astr, const char *bstr );
bool str_cmp( string astr, string bstr );
bool str_cmp( string astr, const char *bstr );
bool str_cmp_case( const char *astr, const char *bstr );
bool str_prefix( const char *astr, const char *bstr );
bool str_infix( const char *astr, const char *bstr );
bool string_infix( string astr, string bstr );
bool str_suffix( const char *astr, const char *bstr );
char *capitalize( const char *str );
void capitalize( string *in );
char *LimitTo( const char *s, int col );
int linefeeds( const char *s );
const char *ParseFloat( const char *line, float *target );
const char *ParseInt( const char *line, int *target );
string file_as_string( const char *filename );
bool file_exists( const char *filename );
void string_as_file( const char *content, const char *filename );
void string_append_file( const char *content, const char *filename );
string RomanNumerals( int v );

// Slick macro-based string IO
// (variant, predictable KV interpreter for distilling to and extracting from strings, lacks logical functionality)

// Used for text output formatting; used by the macros below
void replaceOnce(string &in, string const &search, string const &substitute);
void replaceAll(string &in, const string& search, const string &substitute);
string replace_all(const string& in, const string& search, const string &substitute);
string UnStringSpecialCodes( string k );
string StringSpecialCodes( string k );
extern string indention;
void incdent(void);
void decdent(void);
void nodent(void);
string Hash( int len );
bool HashCompare5( string *a, string *b );

const char *advance_to( const char *start, char c );
const char *collect_to( const char *start, char c, string &out );
const char *collect_to( const char *start, char c, string &out, int errlimit );
string ClientCodeFilter( const char *in );

const char *str_protect( string in );
const char *str_protect( int idx, string in );

// The stuff below is unused and deprecated and not gauranteed to work.
// This was one approach to expediting file string parsing.
// Used for text input parsing.
extern bool SKEYDEBUG;
#define SKEYSTARTLOOP    string key; const char *p= st; while(*p!='\0') { p=string_argument_case(p,&key); if ( key.length() < 1 ) continue; if ( SKEYDEBUG ) {OUTPUT("-Key: ");OUTPUT("###",key,'`');OUTPUT("\n");}
#define VSKEYSTART       virtual void fromString( const char *st ) { SKEYSTARTLOOP;
#define SKEYSTART        void fromString( const char *st ) { SKEYSTARTLOOP;
#define SKEYSTARTC(c)    void c::fromString( const char *st ) { SKEYSTARTLOOP;
#define SKEYSTARTNEW(f)  void f( const char *st ) { SKEYSTARTLOOP;
#define SKEYSTARTLU(t)   void fromString t {
#define SKEYPAIR         p=string_argument_case(p,&key); if ( SKEYDEBUG ) {OUTPUT( "=Value: ");OUTPUT("###",key,'`');OUTPUT("\n");}
#define SKEYLIST(t)      SKEYPAIR; Append(new t(key));
#define SKEY(werd,code)  if ( !str_cmp(key.c_str(),werd) ) { code; } else // remove trailing semicolon from call SKEY("this",{that;}) <- no semi on purpose else bugs occur
#define SPARAM(v,t,f)      SKEYPAIR; v=(t) f(key.c_str());
#define SPARAMB(v)         SKEYPAIR; v=( !str_cmp(key.c_str(),"yes") || !str_cmp(key.c_str(),"on") || !str_cmp(key.c_str(),"1") || !str_cmp(key.c_str(),"true") );
#define SPARAMS(v)         SKEYPAIR; v=key;
#define SPARAMString(v)    SKEYPAIR; v=UnStringSpecialCodes(key);
#define SPARAMC(v,b)       SKEYPAIR; FORMAT(v,b,"%s",key.c_str());
#define SPARAMChar(v)      SKEYPAIR; v=*((char *)key.c_str());
#define SPARAMType(v)      SKEYPAIR; v.fromString(key.c_str());
#define SPARAMPtr(t,v)     SKEYPAIR; v=new t; v->fromString(key.c_str());
#define SPARAMPtrP(t,u,v)  SKEYPAIR; v=new t u; v->fromString(key.c_str());
#define SPARAMNode(t)      SKEYPAIR; t* X=new t; Append(X); X->fromString(key.c_str());
#define SPARAMNodeD(t,d)   SKEYPAIR; t* X=new t; X->fromString(key.c_str()); if ( d ) Append(X); else delete X;
#define SPARAMImage(v)     SKEYPAIR; v=library.find(key.c_str());
#define SPARAMH(v)         SKEYPAIR; HashCopy(v,(char *)key.c_str());
#define SPARAMVertex(v)    SKEYPAIR; { const char *j=key.c_str(); string k; j=string_argument(j,&k); v.x=(GLfloat)atof((char*)k.c_str()); j=string_argument(j,&k); v.y=(GLfloat)atof((char*)k.c_str()); j=string_argument(j,&k); v.z=(GLfloat)atof((char*)k.c_str()); }
#define SPARAMVertexd(v)   SKEYPAIR; { const char *j=key.c_str(); string k; j=string_argument(j,&k); v.x=(double)atof((char*)k.c_str()); j=string_argument(j,&k); v.y=(double)atof((char*)k.c_str()); j=string_argument(j,&k); v.z=(double)atof((char*)k.c_str()); }
#define SPARAMColor(v)     SKEYPAIR; v.fromString(key.c_str());
#define SPARAMNodePolym(t,f) SKEYPAIR; t* X=f(key); SKEYPAIR; X->fromString(key.c_str()); Append(X);
#define SKEYEND(go)      { if (key.length()>0) {OUTPUT( "%s: Skipping unknown option ",go);OUTPUT("###",key,'`');OUTPUT("\n");} } } }
#define SKEYENDING(go)   { if (key.length()>0) {OUTPUT( "%s: Skipping unknown option ",go);OUTPUT("###",key,'`');OUTPUT("\n");} } }
#define SKEYENDER        }
// Used for text output rendering.
#define SOUTSTART         string toString() { string out=string(""); incdent();
#define SOUTSTARTNL       string toString() { string out=string("\n"); incdent();
#define SOUTSTARTB        string toString() { string out=string(""); char buf[4096]; incdent();
#define SOUTSTARTBNL      string toString() { string out=string("\n"); char buf[4096]; incdent();
#define SOUTSTARTBuf(x)   string toString() { string out=string(""); char buf[x]; incdent();
#define SOUTSTARTBufNL(x) string toString() { string out=string("\n"); char buf[x]; incdent();
#define VSOUTSTART         virtual string toString() { string out=string(""); incdent();
#define VSOUTSTARTNL       virtual string toString() { string out=string("\n"); incdent();
#define VSOUTSTARTB        virtual string toString() { string out=string(""); char buf[4096]; incdent();
#define VSOUTSTARTBNL      virtual string toString() { string out=string("\n"); char buf[4096]; incdent();
#define VSOUTSTARTBuf(x)   virtual string toString() { string out=string(""); char buf[x]; incdent();
#define VSOUTSTARTBufNL(x) virtual string toString() { string out=string("\n"); char buf[x]; incdent();
#define SOUT(k,t)         out+=indention+string(k)+string(" {")+t->toString()+string("}\n");
#define SOUTT(k,t)        out+=indention+string(k)+string(" {")+t.toString()+string("}\n");
#define SOUTBE(d,t,b)     out+=indention+string(d)+t->toString()+string(b);
#define SOUTEBE(d,e,b)    out+=indention+string(d)+e+string(b);
#define SOUTbuf           out+=indention+string(buf);
#define SOUTS(k,v)        out+=indention+string(k)+string(" {")+StringSpecialCodes(v)+string("}\n");
#define SOUTB(k,v)        if ( v ) out+=indention+string(k)+string("\n");
#define SOUTInt(k,v)      { char buf2[80]; FORMAT(buf2,80,"%d",(int)v); out+=indention+string(k)+string(buf2)+string("\n"); }
#define SOUTFloat(k,v)    { char buf2[80]; FORMAT(buf2,80,"%1.9f",(float)v); out+=indention+string(k)+string(buf2)+string("\n"); }
#define SOUTV(k,t,v,f)    { char buf2[80]; FORMAT(buf2,80,f,(t)v); out+=indention+string(k)+string(" ")+string(buf2)+string("\n"); }
#define SOUTVx(k,v,f,x)   { char buf2[x]; FORMAT(buf2,x,f,v); out+=indention+string(k)+string(buf2)+string("\n"); }
#define SOUTEND           decdent(); return out; }

// String IO crib sheet
/*
Input: Stores incoming keys in "string key;", next position (remainder) char *p

SKEYSTARTLOOP       Search Key Start Loop - used internally by other SKEYSTART* variants below, simplest instantiation of fromString method
VSKEYSTART          Virtual Search Key Start - inits the SKEY* variants for input processing, 
SKEYSTART           Search Key Start - simplest form of creating fromString
SKEYSTARTC(c)       Search Key Start (C version) - parameter: c; class name.   Used in .cpp file when the function is deferred in object
SKEYSTARTNEW(f)     Search Key Start "New" - lets you name the function with f parameter
SKEYSTARTLU(t)      Search Skey Start "Look Up" - lets you provide custom parameters, t is the parameters, must start with char *st, must be manually followed by SKEYSTARTLOOP; after you have isolated the string as char *st ex: SKEYSTARTLU( (char *st, bool tInit, Numbers *reference) ) do prep; SKEYSTARTLOOP ... SKEYEND...
SKEYPAIR            Search Key Pair - used internally to these macros by all SPARAM macros, or can be used externally to advance and collect a "key"
SKEYLIST(t)         Search Key List - Used in LinkedList to provide when elements can be allocated with a single string parameter like Append( new t( string ) ) 
SKEY(werd,{code;})  Search Key - lets you pair up a string key with some code, DO NOT PLACE ; AFTER CALLING THIS MACRO, ie: "bill" with code; or use SPARAM encapsulated in {,} like SKEY("bill",{SPARAM(var,type,func);}) etc
SPARAM(v,t,f)       Pair a simple type (t) with a variable (v) by calling function f on the const char *, used with atoi,atof and specialty functions that convert strings to their numeric or enumerated equivalents,ie: SPARAM(x,int,atoi);
SPARAMB(v)          Get boolean values into variable v, where "yes", "on", 1 or "true"
SPARAMS(v)          Load a string without special codes (see StringSpecialCodes function above)
SPARAMString(v)     Load a string with special codes interpreted, use with corresponding output macro SOUTS(k,v)
SPARAMC(v,b)        Fill a static char buffer v[of size b] with the content in the string key;
SPARAMChar(v)       Store the first character of the string key in v
SPARAMType(v)       Call fromString on a type like v.fromString() using the string key
SPARAMPtr(t,v)      Call fromString on a pointer after allocating it
SPARAMPtrP(t,(u),v) Call fromString on a pointer after allocating it using parameters in (u)
SPARAMNode(t)       Allocate and append a new node of type t to a LinkedList (*this) and call fromString(key) on it
SPARAMNodeD(t,d)    Allocate and append a new node of type t to a LinkedList and call fromString(key) on it, then test with expression d and discard in that case.
SPARAMImage(v)      Interpret the string key as a call to library.find();
SPARAMH(v)          Copy the contents of the string key into a Hash() of size 5
SPARAMVertex(v)     Deprecated, use SPARAMType,Ptr - loads a Vertex v using the "simple" style of 3 floats
SPARAMVertexd(v)    Deprecated, use SPARAMType,Ptr - loads a Vertexd v using the "simple" style of 3 doubles
SPARAMColor(v)      Specialty for loading a Crayon v as 4 floats or 4 ints or a color name or a CSS code like #AAFF99 / #AF9
SPARAMNodePolym(t,f)  -- Pass a function name which, based on a string key, returns a newly created, casted polymorphic derived from class t
SKEYEND("go")       go contains a debugger notation if SKEYDEBUG is enabled
SKEYENDING("go")    go contains a debugger notation if SKEYDEBUG is enabled, but lacks the SKEYENDER (final }) leaving room for custom post processing
SKEYENDER           simply the ending } used in conjunction with SKEYENDING if you are doing post-processing

>> Examples are found in the source, search by macro.

Output:
 incdent() increases indention amount
 decdent() decreases indention amount

SOUTSTART           String Out Start - starts the output function increasing indent and allocating string out
SOUTSTARTNL         String Out Start NewLine - starts the output function increasing indent and allocating string out as \n
SOUTSTARTB          String Out Start Buffer - above and allocates a static 'buf' as a char[4096] for use with FORMAT
SOUTSTARTBNL        String Out Start Buffer New-Line - above with a newline and allocates a static buf[4096] for use with FORMAT
SOUTSTARTBuf(x)     String Out Start Buffer Size X - lets you set the size of the static buf - warning on stack overflows!
SOUTSTARTBufNL(x)   String Out Start Buffer Size X New-Line - starts the output with a newline and lets you set the size of the static buffer
VSOUTSTART          Virtual version of above
VSOUTSTARTNL        Virtual version of above
VSOUTSTARTB         Virtual version of above
VSOUTSTARTBNL       Virtual version of above
VSOUTSTARTBuf(x)    Virtual version of above
VSOUTSTARTBufNL(x   Virtual version of above
SOUT(k,t)           Adds an indented string key (should match SKEY version) and associated pointer (t->toString() is called)
SOUTPolym(k,t)      Adds an indented string key (should match SKEY version) and associated pointer (t->toString() is called) wrapped in an identity wrapper ie:  base { derived { data } }
SOUTT(k,t)          String Output Type - Same as above but t.toString() is called
SOUTBE(d,t,b)       String Output Begin End - lets you define bookends around the resulting t.toString() 
SOUTEBE(d,e,b)      String Output Expression Begin End - lets you define the expression e instead of t.toString()
SOUTbuf             String Output buf - called after FORMAT() to append contents of buf, indented
SOUTS(k,v)          String Output String - outputs a k/v pair and calls the StringSpecialCodes() encoder function on v
SOUTB(k,v)          String Output Key if Bool - if v is true then add key k to output
SOUTInt(k,v)        uses a small buffer to write a line containing the k and v like "key 0" where v is an int %d
SOUTFloat(k,v)      uses a small buffer to write a line containing the k and v like "key 0.000f" where v is a float %1.9f
SOUTV(k,t,v,f)      lets you output a simple type t like "key value" where value can be formatted using f for FORMAT
SOUTVx(k,v,f,x)     x=buf size, output a simple type like "key value" where value can be formatted using f for FORMAT
SOUTEND             Ends the function, decreasing the indentation level

>> Examples are found in the source, search by macro.
*/
