#include "string_functions.h"
#include "moremath.h"
//#include "macros.h"
#include "Strings.h"
#include "Indexed.h"
#include "ZeroTypes.h"

// Work Strings
char buf[STRING_SIZE];
char buf2[STRING_SIZE];
char buf3[STRING_SIZE];

char *copy_to_string( char *write_to, const char *value ) {
 char *o=write_to;
 const char *p=value;
 while ( *p != '\0' ) {
  *o=*p;
  o++;
  p++;
 }
 return o;
}

void InitWorkStrings() {
 for ( int i=0; i<STRING_SIZE; i++ ) {
  buf[i]=buf2[i]=buf3[i]='\0';
 }
}

const char string_error='\0';

bool make_folder( const char *targetPath ) {
 return false;
}

void trim( string *toworkon ) {
 std::remove(toworkon->begin(), toworkon->end(), ' ');
}

#define _FILLER(c) ( c == ' ' || c == ',' || c == '=' || c == '\n' || c == '\r' )
#define _SEP(c)    ( c == '\'' || c == '"' || c == '\'' )
#define _NESTERS(c) ( c == '{' || c == '[' || c == '(' || c == '\x001' )
#define _NESTERE(c) ( c == '}' || c == ']' || c == ')' || c == '\x00e' )

bool SKEYDEBUG=false;

//#include "SpecialPaths.h"

/*
void OUTPUT(const char * fmt, ...)
{
 va_lis args;
 static char buf [32768];
 va_start( args, fmt );
 vnprintf( buf, 32765, fmt, args );
 va_end( args );
}
 */

#define FORMAT_STRING_SIZE 65536
string FORMAT(char *b, int len, const char *fmt, ...)
{
 static char buf [FORMAT_STRING_SIZE];
 if ( strlen(fmt) > FORMAT_STRING_SIZE/4 ) {
  OUTPUT("FORMAT(): Warning, format string longer than maximum length.\n");
  return string("");
 }
 va_list args;
 va_start (args, fmt);
 snprintf (buf, FORMAT_STRING_SIZE-2, fmt, args);
 va_end (args);
 string s=string(buf);
 const char *cstr=s.c_str();
 for ( int i=0; i<len; i++ ) {
  b[i]=cstr[i];
  if ( cstr[i]=='\0' ) break;
 }
 b[len-1]='\0';
 return s;
}

string FORMAT(const char*fmt, ...) {
 string s;
 static char buf[FORMAT_STRING_SIZE];
 va_list args;
 va_start( args, fmt );
 snprintf(buf, FORMAT_STRING_SIZE-2, fmt, args);
 va_end(args);
 s=string(buf);
 return s;
}

/*
 * Compare strings, case insensitive.
 */
bool contains( const char *astr, const char *bstr )
{
 if ( astr == null ) {
  OUTPUT( "Str_cmp: null astr.\n" );
  return false;
 }
 if ( bstr == null ) {
  OUTPUT( "Str_cmp: null bstr.\n" );
  return false;
 }
 for ( ; *astr || *bstr; astr++, bstr++ ) if ( LOWER(*astr) != LOWER(*bstr) ) return false;
 return true;
}

/*
 * Find at least one of a single character in a string.
 */
bool contains( string s, char c ) { return contains( s.c_str(), c ); }
bool contains( const char *s, char c ) {
 const char *p=s;
 while ( *p != '\0' ) {
  if ( *p==c ) return true;
  p++;
 }
 return false;
}

/*
 * Count the number of a single character in a string.
 */
int count_char( string s, char c ) { return count_char( s.c_str(), c ); }
int count_char( const char *s, char c ) {
 int total=0;
 const char *p=s;
 while ( *p != '\0' ) {
  if ( *p == c ) total++;
  p++;
 }
 return total;
}

/*
 * Determine if a string ends with a certain string, optionally remove padding (\n\rspace)
 */

bool endsWith( const char *searching, const char *find, bool removePadding ) {
 if ( searching == null ) {
  OUTPUT( "endsWith: null searching.\n" );
  return false;
 }
 if ( find == null ) {
  OUTPUT( "endsWith: null find.\n" );
  return false;
 }
 int L1=strlen(searching);
 if ( L1 == 0 ) return false;
 int L2=strlen(find);
 if ( L1<L2 ) return false;
 if ( L2 == 0 ) {
  OUTPUT("endsWith() warns find string was empty, returning false\n");
  return false;
 }
 string unpadded;
 if ( !removePadding ) unpadded=string(searching);
 else {
  unpadded=string(searching);
  trim(&unpadded);
  L1=unpadded.length();
  if ( L1<L2 ) return false;
 }
 const char *tosearch=unpadded.c_str();
 int x=L1-1;
 int y=L2-1;
 while ( y>=0 ) {
  if ( LOWER(tosearch[x]) != LOWER(find[y]) ) {
   return false;
  }
  x--;
  y--;
 }
 return true;
}

/*
 * Similar to endsWith but uses std
 */

bool hasEnding(std::string const &fullString, std::string const &ending) {
 if (fullString.length() >= ending.length()) {
  return (0 == fullString.compare(fullString.length() - ending.length(), ending.length(), ending));
 } else {
  return false;
 }
}

bool hasEnding( const char *searching, const char *find, bool caseSensitive, bool unpad ) {
 string fullString;
 string ending;
 if ( !caseSensitive ) {
  fullString=lower(string(searching));
  ending=lower(string(find));
 } else {
  fullString=string(searching);
  ending=string(find);
 }
 if ( unpad ) {
  trim(&fullString);
 }
 if (fullString.length() >= ending.length()) {
  return (0 == fullString.compare(fullString.length() - ending.length(), ending.length(), ending));
 } else {
  return false;
 }
}

bool hasEnding( string const &searching, const char *find, bool caseSensitive, bool unpad ) {
 string fullString=searching;
 string ending=string(find);
 if ( !caseSensitive ) {
  fullString=lower(fullString);
  ending=lower(ending);
 }
 if ( unpad ) {
  trim(&fullString);
 }
 if (fullString.length() >= ending.length()) {
  return (0 == fullString.compare(fullString.length() - ending.length(), ending.length(), ending));
 } else {
  return false;
 }
}

bool endsWith(string const &fullString, string const &ending) {
 string a=fullString;
 trim(&a);
 if (a.length() >= ending.length()) {
  return (0 == a.compare(a.length() - ending.length(), ending.length(), ending));
 } else {
  return false;
 }
}

bool hasEnding( string const &searching, string const &find, bool caseSensitive, bool unpad ) {
 string fullString=searching;
 string ending=find;
 if ( !caseSensitive ) {
  fullString=lower(fullString);
  ending=lower(ending);
 }
 if ( unpad ) {
  trim(&fullString);
 }
 if (fullString.length() >= ending.length()) {
  return (0 == fullString.compare(fullString.length() - ending.length(), ending.length(), ending));
 } else {
  return false;
 }
}

void replaceOnce(string& in, string const &search, string const &substitute) {
 int found=0;
 string::size_type pos=0;
 while((pos=in.find(search, pos))!=string::npos&&found<1)
 {
  in.erase(pos, search.length());
  in.insert(pos, substitute);
  pos+=substitute.length();
  found++;
 }
}

void replaceAll(string& in, string const &search, string const &substitute) {
 string::size_type pos=0;
 while((pos=in.find(search, pos))!=string::npos)
 {
  in.erase(pos, search.length());
  in.insert(pos, substitute);
  pos+=substitute.length();
 }
}

string replace_all(const string& in, const string& search, const string& substitute) {
 string::size_type pos=0;
 string out=in;
 while((pos=out.find(search, pos))!=string::npos)
 {
  out.erase(pos, search.length());
  out.insert(pos, substitute);
  pos+=substitute.length();
 }
 return out;
}

string UnStringSpecialCodes( string k ) {
 return replace_all(replace_all(k,string("#*$#-1-#$*#"),string("{")),string("#*$#-2-#$*#"),string("}"));
}

string StringSpecialCodes( string k ) {
 return replace_all(replace_all(k,string("{"),string("#*$#-1-#$*#")),string("}"),string("#*$#-2-#$*#"));
}

int char_is_of( char c, const char *list ) {
 int o,O;
 O=strlen(list);
 for ( o=0; o<O; o++ ) if ( list[o] == c ) return o;
 return -1;
}

char randomChar( const char *list ) {
 int c=upto(strlen(list));
 return list[c];
}

/*
 * Similar to char_is_of
 */
bool char_in(char c, const char *list ) {
 int o,O;
 O=strlen(list);
 for ( o=0; o<O; o++ ) if ( list[o] == c ) return true;
 return false;
}

/*
 * Smash all \r's and tildes for file writes.
 * Uses a temporary static buffer.
 */
char *fix_string( const char *str )
{
 static char strfix[STRING_SIZE];
 int i,o;
 if ( str == null ) return '\0';
 for ( o = i = 0; str[i+o] != '\0'; i++ ) {
  if (str[i+o] == '\r' || str[i+o] == '~') o++;
  strfix[i] = str[i+o];
 }
 strfix[i] = '\0';
 return (char *) strfix;
}

/*
 * Sees if last char is 's' and returns 'is' or 'are'
 * if the word is not like 'dress'
 */
string is_are( const char *text )
{
 while ( *text != '\0' ) text++;
 /* Special cases. */
 if ( !str_infix( text, "kris" ) ) return string("is");
 if ( !str_infix( text, "fungus" ) ) return string("is");
 text--;
 if ( LOWER(*text) == 's' && LOWER(*(--text)) != 's' ) return string("are");
 else return string("is");
}

/*
 * Smashes all occurances of a string from a larger string.
 * Arguments must be seperated by a space.
 */
char *smash_arg( const char *text, const char *name )
{
 const char *arg;
 static char buf[STRING_SIZE];
 static char buf2[STRING_SIZE];
 buf2[0] = '\0';
 arg = one_argument( text, buf );
 while ( buf[0] != '\0' ) {
  if ( str_cmp( buf, name ) ) {
   strcat_s( buf2, buf );
   strcat_s( buf2, " " );
  }
  arg = one_argument( arg, buf );
 }
 return (char *) buf2;
}

/*
 * Grab 'a' 'an's and 'the's and smash the living hell out of them.
 * Good for use with manipulation of prop names.  Only destroys first
 * occurance.
 */
char *smash_article( const char *text )
{
 const char *arg;
 char buf[STRING_SIZE];
 static char buf2[STRING_SIZE];
 one_argument( text, buf );
 if ( !str_cmp( buf, "the" ) || !str_cmp( buf, "an" ) || !str_cmp( buf, "a" ) ) {
  arg = one_argument( text, buf );
  FORMAT( buf2,STRING_SIZE, "%s", arg );
 }
 else strcpy_s( buf2, text );
 return (char *) buf2;
}

/*
 * Pluralize English objective statements properly.
 */
char *pluralize(const char *argument )
{
    static char buf[STRING_SIZE];
    char *v;

    FORMAT( buf,STRING_SIZE, "%s", smash_article(argument) );

    if ( strstr( buf, "some" ) ) return (char *) buf;
    v = strstr( buf, " of " );
    if ( v==null ) v = strstr( buf, " to " );

    if ( v == null )
    {
        if ( LOWER(buf[strlen(buf)-1]) == 'y' )
        {
            if ( LOWER(buf[strlen(buf)-2]) == 'a' ) 
            {
              strcat_s( buf, "s" );
            }
            else {
              buf[strlen(buf)-1] = 'i';
              strcat_s( buf, "es" );
            }
        }
        else
        if ( LOWER(buf[strlen(buf)-1]) == 'f'
          && LOWER(buf[strlen(buf)-2]) != 'f'
          && (LOWER(buf[strlen(buf)-2]) != 'i'
            && LOWER(buf[strlen(buf)-3]) == 'o') )
        {
            buf[strlen(buf)-1] = 'v';
            strcat_s( buf, "es" );
        }
        else
        if ( LOWER(buf[strlen(buf)-1]) == 'h' )
        strcat_s( buf, "es" );
        else
        if ( LOWER(buf[strlen(buf)-1]) == 'x' )
        strcat_s( buf, "es" );
        else
        if ( LOWER(buf[strlen(buf)-1]) == 's' )
        {
            if ( LOWER(buf[strlen(buf)-2]) == 'u'
              && !IS_VOWEL(LOWER(buf[strlen(buf)-3])) )
            {
                buf[strlen(buf)-2] = 'i';
                buf[strlen(buf)-1] = '\0';
            }
            else
            strcat_s( buf, "es" );
        }
        else
        strcat_s( buf, "s" );
    }
    else
    {
        char xbuf[STRING_SIZE];

        FORMAT( xbuf,STRING_SIZE, "%s", v );
        buf[strlen(buf)-strlen(v)] = '\0';

        if ( LOWER(buf[strlen(buf)-1]) == 'y' )
        {
            if ( LOWER(buf[strlen(buf)-2]) == 'a' )
            {
              strcat_s( buf, "s" );
            }
            else {
              buf[strlen(buf)-1] = 'i';
              strcat_s( buf, "es" );
            }
        }
        else
        if ( LOWER(buf[strlen(buf)-1]) == 'f'
          && LOWER(buf[strlen(buf)-2]) != 'f'
          && (LOWER(buf[strlen(buf)-2]) != 'i'
            && LOWER(buf[strlen(buf)-3]) == 'o') )
        {
            buf[strlen(buf)-1] = 'v';
            strcat_s( buf, "es" );
        }
        else
        if ( LOWER(buf[strlen(buf)-1]) == 'h' )
        strcat_s( buf, "es" );
        else
        if ( LOWER(buf[strlen(buf)-1]) == 'x' )
        strcat_s( buf, "es" );
        else
        if ( LOWER(buf[strlen(buf)-1]) == 's' )
        {
            if ( LOWER(buf[strlen(buf)-2]) == 'u'
              && !IS_VOWEL(LOWER(buf[strlen(buf)-3])) )
            {
                buf[strlen(buf)-2] = 'i';
                buf[strlen(buf)-1] = '\0';
            }
            else
            strcat_s( buf, "es" );
        }
        else
        strcat_s( buf, "s" );

        strcat_s( buf, xbuf );
    }

    return (char *) buf;
}


/*
 * Word wrap a string.
 */
char *wordwrap(const char *oldstring /*, bool fSpace */)
{
 static char xbuf[STRING_SIZE];
 char xbuf2[STRING_SIZE];
 char *rdesc;
 int i=0;
 bool cap=true;
 xbuf[0]=xbuf2[0]=0;
 i=0;
 for (rdesc = (char *) oldstring; *rdesc; rdesc++) {
  if (*rdesc=='\n') {
   if (xbuf[i-1] != ' ') {
    xbuf[i]=' ';
    i++;
   }
  }
  else if (*rdesc=='\r') ;
  else if (*rdesc==' ') {
   if (xbuf[i-1] != ' ')
   {
    xbuf[i]=' ';
    i++;
   }
  }
  else if (*rdesc==')') {
   if (xbuf[i-1]==' ' && xbuf[i-2]==' ' && (xbuf[i-3]=='.' || xbuf[i-3]=='?' || xbuf[i-3]=='!')) {
    xbuf[i-2]=*rdesc;
    xbuf[i-1]=' ';
    xbuf[i]=' ';
    i++;
   } else {
    xbuf[i]=*rdesc;
    i++;
   }
  }
  else if (*rdesc=='.' || *rdesc=='?' || *rdesc=='!') {
   if (xbuf[i-1]==' ' && xbuf[i-2]==' ' && (xbuf[i-3]=='.' || xbuf[i-3]=='?' || xbuf[i-3]=='!')) {
    xbuf[i-2]=*rdesc;
    if (*(rdesc+1) != '\"') {
     xbuf[i-1]=' ';
     xbuf[i]=' ';
     i++;
    } else {
     xbuf[i-1]='\"';
     xbuf[i]=' ';
     xbuf[i+1]=' ';
     i+=2;
     rdesc++;
    }
   } else {
    xbuf[i]=*rdesc;
    if (*(rdesc+1) != '\"') {
     xbuf[i+1]=' ';
     xbuf[i+2]=' ';
     i += 3;
    } else {
     xbuf[i+1]='\"';
     xbuf[i+2]=' ';
     xbuf[i+3]=' ';
     i += 4;
     rdesc++;
    }
   }
   cap = true;
  } else {
   xbuf[i]=*rdesc;
   if ( cap ) {
    cap = false;
    xbuf[i] = UPPER( xbuf[i] );
   }
   i++;
  }
 }
 xbuf[i]=0;
 strcpy_s(xbuf2,xbuf);
 rdesc=xbuf2;
 xbuf[0]=0;
 for ( ; ; ) {
  for (i=0; i<77; i++) {
   if (!*(rdesc+i)) break;
  }
  if (i<77) break;
  for (i=(xbuf[0]?76:73) ; i ; i--) if (*(rdesc+i)==' ') break;
  if (i) {
   *(rdesc+i)=0;
   strcat_s(xbuf,rdesc);
   strcat_s(xbuf,"\n\r");
   rdesc += i+1;
   while (*rdesc == ' ') rdesc++;
  } else {
   OUTPUT("No spaces");
   *(rdesc+75)=0;
   strcat_s(xbuf,rdesc);
   strcat_s(xbuf,"-\n\r");
   rdesc += 76;
  }
 }
 while (*(rdesc+i) && (*(rdesc+i)==' '|| *(rdesc+i)=='\n' || *(rdesc+i)=='\r')) i--;
 *(rdesc+i+1)=0;
 strcat_s(xbuf,rdesc);
 if (xbuf[strlen(xbuf)-2] != '\n') strcat_s(xbuf,"\n\r");
 delete oldstring;
 return((char *)(xbuf));
}

/*
 * Formats as though the text was a single paragraph.
 */
string paragraph(const char *oldstring, const char *prefix, int width, bool fEnd )
{
 char xbuf[STRING_SIZE];
 char xbuf2[STRING_SIZE];
 char *rdesc;
 int i=0;
 bool cap=true;
 xbuf[0]=xbuf2[0]=0;
 i = 0;
 for ( rdesc = (char *) oldstring; *rdesc; rdesc++ ) {
  if ( *rdesc == '\n' ) {
   if ( xbuf[i-1] != ' ' ) {
    xbuf[i] = ' ';
    i++;
   }
  }
  else if ( *rdesc == '\r' ) ;
  else if ( *rdesc == ' ' ) {
   if ( xbuf[i-1] != ' ' ) {
    xbuf[i]=' ';
    i++;
   }
  }
  else if ( *rdesc == ')' ) {
   if ( xbuf[i-1] == ' ' && xbuf[i-2] == ' '
     && ( xbuf[i-3] == '.' || xbuf[i-3] == '?' || xbuf[i-3] == '!' ) ) {
    xbuf[i-2]=*rdesc;
    xbuf[i-1]=' ';
    xbuf[i]=' ';
    i++;
   }
   else { xbuf[i]=*rdesc; i++; }
  }
  else if ( *rdesc == '.' || *rdesc == '?' || *rdesc == '!' ) {
   cap = true;
   if ( xbuf[i-1] == ' ' && xbuf[i-2] == ' '
     && ( xbuf[i-3] == '.' || xbuf[i-3] == '?' || xbuf[i-3] == '!' ) ) {
    xbuf[i-2]=*rdesc;
    if ( *(rdesc+1) != '\"' ) {
     xbuf[i-1]=' ';
     xbuf[i]=' ';
     i++;
    } else {
     xbuf[i-1]='\"';
     xbuf[i]=' ';
     xbuf[i+1]=' ';
     i+=2;
     rdesc++;
    }
   } else {
    xbuf[i]=*rdesc;
    if (*(rdesc+1) != '\"') {
     if ( *(rdesc+1) == ' ' ) {
      xbuf[i+1]=' ';
      xbuf[i+2]=' ';
      i += 3;
     } else {
      cap = false;
      xbuf[i] = *rdesc;
      i++;
     }
    } else {
     xbuf[i+1]='\"';
     xbuf[i+2]=' ';
     xbuf[i+3]=' ';
     i += 4;
     rdesc++;
    }
   }
  } else {
   xbuf[i]=*rdesc;
   if ( cap ) {
    cap = false;
    xbuf[i] = UPPER( xbuf[i] );
   }
   i++;
  }
 }
 xbuf[i]=0;
 strcpy_s(xbuf2,xbuf);
 rdesc=xbuf2;
 xbuf[0]=0;
 for ( ; ; ) {
  for ( i = 0; i < width+1; i++ ) if ( !*(rdesc+i) ) break;
  if ( i < width+1 ) break;
  for ( i = xbuf[0] ? width : width-3; i; i-- ) if ( *(rdesc+i) == ' ' ) break;
  if ( i ) {
   *(rdesc+i)=0;
   strcat_s(xbuf,rdesc);
   strcat_s(xbuf,"\n\r");
   strcat_s(xbuf,prefix);
   rdesc += i+1;
   while (*rdesc == ' ') rdesc++;
  } else {
   printf ("No spaces");
   *(rdesc+width-1)=0;
   strcat_s(xbuf,rdesc);
   strcat_s(xbuf,"-\n\r");
   rdesc += width;
  }
 }
 while (*(rdesc+i) && (*(rdesc+i)==' '|| *(rdesc+i)=='\n'|| *(rdesc+i)=='\r')) i--;
 *(rdesc+i+1)=0;
 strcat_s(xbuf,rdesc);
 if ( fEnd && xbuf[strlen(xbuf)-2] != '\n') strcat_s(xbuf,"\n\r");
 if ( xbuf[strlen(xbuf)-1] == ' ' ) xbuf[strlen(xbuf)-1] = '\0';
 if ( xbuf[strlen(xbuf)-1] == ' ' ) xbuf[strlen(xbuf)-1] = '\0';
 string final=string(xbuf);
 return(final);
}

/*
 * Replace a substring with a new substring, return the new version.
 * (make sure to CopyString() when needed)
 */
char *replace_string(const char *orig, const char *old, const char *n )
{
 static char xbuf[STRING_SIZE];
 int i;
 xbuf[0] = '\0';
 strcpy_s(xbuf, orig);
 if ( strstr(orig,old) != null ) {
  i = strlen( orig ) - strlen( strstr(orig, old) );
  xbuf[i]  = '\0';
  strcat_s( xbuf, n);
  strcat_s( xbuf, &orig[i+strlen( old )] );
 }
 return (char *) ( xbuf );
}

void replace_char( char *orig, char old, char n)
{
 while (*orig) if (*orig == old) *orig++ = n;
  else orig++;
}

/*
 * Counts the number of "words" (strings of non-spaces separated by spaces)
 * in a string.     Not the best way (should use one_arg)?
 */
int words(const char *argument )
{
 int total;
 char *s = (char *) argument;
 total = 0;
 while ( *s != '\0' ) 
  if ( *s != ' ' ) {
   total++;
   while ( *s != ' ' && *s != '\0' ) s++;
  } else s++;
 return total;
}

/*
 * Returns a string with one space between each argument.  NOT SAFE
 */
char * string_unpad( const char * argument )
{
 static char buf[STRING_SIZE];
 char *s = (char *) argument;
 char *d = buf;
 while ( *s == ' ' ) s++;
 FORMAT(buf,STRING_SIZE,"%s",s);
 d = buf;
 if ( *d != '\0' ) {
  while ( *d != '\0' ) d++;
  d--;
  while( *d == ' ' ) d--;
  d++;
  *d = '\0';
 }
 return( buf );
}

/*
 * First char is capital, the rest is lowercase or something
 * to that effect.  Similar to ucfirst() from PHP
 */
char * string_proper( char * argument )
{
 char *s;
 s = argument;
 while ( *s != '\0' ) {
  if ( *s != ' ' ) {
   *s = UPPER(*s);
   while ( *s != ' ' && *s != '\0' ) s++;
  } else s++;
 }
 return argument;
}

inline bool is_digit( char c ) {
 return (c =='0' || c == '1' || c == '2' || c == '3' || c == '4' || c =='5' || c =='6' || c=='7' || c == '8' || c == '9' );
}

/*
 * Return true if an argument is completely numeric.
 */
bool is_integer( const char *arg ) {
 const char *o=arg;
 bool foundspace=false;
 if ( *arg == '\0' ) return false;
 if ( *arg == '-' ) arg++;
 for ( ; *arg != '\0'; arg++ ) {
  if ( !is_digit(*arg) ) {
   if ( _FILLER(*arg) ) foundspace=true;
   else return false;
  }
 }
 if ( foundspace ) {
  if ( words(o) == 1 ) return true;
  return false;
 }
 return true;
}

/*
 * Return true if an argument is completely numeric.
 */
bool is_decimal( const char *arg ) {
 const char *o=arg;
 int periods=0;
 bool foundspace=false;
 if ( *arg == '\0' ) return false;
 while ( _FILLER(*arg) ) arg++;
 if ( *arg == '-' ) arg++;
 for ( ; *arg != '\0'; arg++ ) {
  if ( !is_digit(*arg) ) {
   if ( *arg == '.' ) {
    if ( periods >=1 ) return false;
    periods++;
    arg++;
   } else
   if ( _FILLER(*arg) ) foundspace=true;
   else return false;
  }
 }
 if ( foundspace ) {
  if ( words(o) == 1 ) return true;
  return false;
 }
 return true;
}

/*
 * Same as above but uses atoi error handling, decimal only (base-10, no floats).
 * Does not return the value if valid (tiny inefficiency).
 * Source: http://www.gidforums.com/t-17778.html
 */
bool is_int( string k ) {
 const char *in=k.c_str();
 char * last = 0;

// int x1 = atoi(in);
// int x2 =
 strtol(in, &last, 10);
 if ( *last == '\0' ) // was valid or empty
  if ( k.length() > 0 ) return false;
 return true;
}

/*
 * Same as above but uses atoi error handling.  Only base 10 checked.
 * Does not return the value if valid (tiny inefficiency).
 * Source: http://www.gidforums.com/t-17778.html
 */
bool is_hex( string k ) {
 const char *in=k.c_str();
 char *last = null;
 //int x1 = atoi(in);
 //long x2 =
 strtol(in, &last, 16);
 if ( last && *last == '\0' ) // was valid or empty
  if ( k.length() > 0 ) return false;
 return true;
}

/*
 * Same as above but uses atoi error handling, decimal only (base-10, no floats).
 * Does not return the value if valid (tiny inefficiency).
 * Source: http://www.gidforums.com/t-17778.html
 */
bool is_float( string k ) {
 char * last = 0;
// double x1 = atof(k.c_str());
// long x2 =
 strtol(k.c_str(), &last, 10);
 if ( *last == '\0' ) // was valid or empty returns false positive (indicating no error, but does not specify why)
  if ( k.length() > 0 ) return false;
 return true;
}

int from_hex( string hex ) {
 int result;
 sscanf(hex.c_str(), "%x", &result);
 return result;
}

string to_hex( int i ) {
 char buf[80];
 FORMAT(buf,80,"%x", (int) i);
 string out=string(buf);
 if ( out.length() == 1 ) out=string("0")+out; // A==0A
 return out;
}

/* Pick off one argument from a string and return the rest.
 * Understands quotes and {}=[], treats interim commas and equal signs as space.
 * Uses the stack so not recommended for large strings (use string_argument);
 */
const char *one_argument( const char *args, char *arg_first )
{
 const char *argument=args;
 char cEnd = ' ';
 if ( argument == null ) return &string_error;
 // Advance past spaces and interim commas, equal signs, newlines, skip #comments
 while ( _FILLER(*argument) || *argument == '#' ) {
  if ( *argument == '#' ) while ( *argument != '\n' && *argument != '\r' && *argument != '\0' ) argument++;
  else argument++;
 }
 if ( _SEP(*argument) ) {
  cEnd = *argument;
  argument++;
 }
 if ( _NESTERS(*argument) ) { // Handle nested {} or []
  argument++;
  int nests=1;
  while ( *argument != '\0' && _NESTERE(*argument) && nests > 0 ) {
   if ( _NESTERE(*argument) ) {
    nests--;
    argument++;
    if ( nests == 0 ) break;
   } else if ( *argument == '{' || *argument == '[' ) nests++;
   *arg_first=*argument;
   argument++;
   arg_first++;
  }
 } else { // Quotes are the delimiters
  while ( *argument != '\0' ) {
   if ( *argument == '\n' ) {
    argument++; 
    if ( cEnd == ' ' ) break;
   }
   if ( *argument == '\r' ) {
    argument++;
    if ( cEnd == ' ' ) break;
   }
   if ( *argument == ',' && cEnd == ' ' ) break; // end on a comma unless quotes are cEnd
   if ( *argument == '=' && cEnd == ' ' ) break; // end on equal sign unless quotes are cEnd
   if ( *argument == cEnd ) {
    argument++;
    break;
   }
   *arg_first = LOWER(*argument);
   arg_first++;
   argument++;
  }
 }
 *arg_first = '\0';
 // Advance past spaces and interim commas, equal signs, newlines, skip #comments
 while ( _FILLER(*argument) || *argument == '#' ) {
  if ( *argument == '#' ) while ( *argument != '\n' && *argument != '\r' && *argument != '\0' ) argument++;
  else argument++;
 }
 return argument;
}

/* Pick off one argument from a string and return the rest.
 * Uses std::string thus dynamic and doesn't use the stack.
 * Understands quotes and {}=[](), treats interim commas and equal signs as space.
 */
const char *string_argument( const char *argument, string *arg_first )
{
 char cEnd = ' ';
// char buf[2];
 (*arg_first)=string("");
 if ( argument == null ) return &string_error; // undef behavior? maybe "" is constant
 // Advance past spaces and interim commas, equal signs, newlines, skip #comments
 while ( _FILLER(*argument) || *argument == '#' ) {
  if ( *argument == '#' ) while ( *argument != '\n' && *argument != '\r' && *argument != '\0' ) argument++;
  else argument++;
 }
 // Handle nested {} [] (), or quotes "" '' ``
 if ( _NESTERS(*argument) || _SEP(*argument) ) { // Delimiters
  int nests=1;
  char cStart=*argument;
  argument++;
  switch ( cStart ) {
   case '{': cEnd = '}'; break;
   case '[': cEnd = ']'; break;
   case '(': cEnd = ')'; break;
  case '\'': cEnd = '\''; break;
   case '"': cEnd = '"'; break;
   case '`': cEnd = '`'; break;
  }
  while ( *argument != '\0' && nests > 0 ) {
   if ( *argument == cEnd ) {
    nests--;
    if ( nests == 0 ) break;
   } else if ( *argument == cStart ) nests++;
   (*arg_first)+=(*argument);
   argument++;
  }
  argument++;
 } else { // No delimiters, lower case, stop when you hit = , [ { (
  while ( *argument != '\0' ) {
   if ( char_in( *argument, "\n\r[{(,= " ) ) break;
   (*arg_first)+=LOWER(*argument);//string(buf);
   argument++;
  }
 }
 // Advance past spaces and interim commas, equal signs, newlines, skip #comments
 while ( _FILLER(*argument) || *argument == '#' ) {
  if ( *argument == '#' ) while ( *argument != '\n' && *argument != '\r' && *argument != '\0' ) argument++;
  else argument++;
 }
 return argument;
}

/* Pick off one argument from a string and return the rest.
 * Uses std::string thus dynamic and doesn't use the stack.
 * Understands quotes and {}=[](), treats interim commas and equal signs as space.
 */
const char *string_argument( const char *argument, Zstring *arg_firstz )
{
 string *arg_first=&arg_firstz->value;
 char cEnd = ' ';
// char buf[2];
 (*arg_first)=string("");
 if ( argument == null ) return &string_error; // undef behavior? maybe "" is constant
 // Advance past spaces and interim commas, equal signs, newlines, skip #comments
 while ( _FILLER(*argument) || *argument == '#' ) {
  if ( *argument == '#' ) while ( *argument != '\n' && *argument != '\r' && *argument != '\0' ) argument++;
  else argument++;
 }
 // Handle nested {} [] (), or quotes "" '' ``
 if ( _NESTERS(*argument) || _SEP(*argument) ) { // Delimiters
  int nests=1;
  char cStart=*argument;
  argument++;
  switch ( cStart ) {
   case '{': cEnd = '}'; break;
   case '[': cEnd = ']'; break;
   case '(': cEnd = ')'; break;
  case '\'': cEnd = '\''; break;
   case '"': cEnd = '"'; break;
   case '`': cEnd = '`'; break;
  }
  while ( *argument != '\0' && nests > 0 ) {
   if ( *argument == cEnd ) {
    nests--;
    if ( nests == 0 ) break;
   } else if ( *argument == cStart ) nests++;
   (*arg_first)+=(*argument);
   argument++;
  }
  argument++;
 } else { // No delimiters, lower case, stop when you hit = , [ { (
  while ( *argument != '\0' ) {
   if ( char_in( *argument, "\n\r[{(,= " ) ) break;
   (*arg_first)+=LOWER(*argument);//string(buf);
   argument++;
  }
 }
 // Advance past spaces and interim commas, equal signs, newlines, skip #comments
 while ( _FILLER(*argument) || *argument == '#' ) {
  if ( *argument == '#' ) while ( *argument != '\n' && *argument != '\r' && *argument != '\0' ) argument++;
  else argument++;
 }
 arg_firstz->length=arg_firstz->value.length();
 return argument;
}

/* Pick off one argument from a string and return the rest without lowering case.
 * Uses std::string thus dynamic and doesn't use the stack.
 * Understands quotes and {}=[](), treats interim commas and equal signs as space.
 */
const char *string_argument_case( const char *argument, string *arg_first )
{
 char cEnd = ' ';
// char buf[2];
 (*arg_first)=string("");
 if ( argument == null ) return &string_error; // undef behavior? maybe "" is constant
 // Advance past spaces and interim commas, equal signs, newlines, skip #comments
 while ( _FILLER(*argument) || *argument == '#' ) {
  if ( *argument == '#' ) while ( *argument != '\n' && *argument != '\r' && *argument != '\0' ) argument++;
  else argument++;
 }
 // Handle nested {} [] (), or quotes "" '' ``
 if ( _NESTERS(*argument) || _SEP(*argument) ) { // Delimiters
  int nests=1;
  char cStart=*argument;
  argument++;
  switch ( cStart ) {
   case '{': cEnd = '}'; break;
   case '[': cEnd = ']'; break;
   case '(': cEnd = ')'; break;
  case '\'': cEnd = '\''; break;
   case '"': cEnd = '"'; break;
   case '`': cEnd = '`'; break;
  }
  while ( *argument != '\0' && nests > 0 ) {
   if ( *argument == cEnd ) {
    nests--;
    if ( nests == 0 ) break;
   } else if ( *argument == cStart ) nests++;
   (*arg_first)+=(*argument);
   argument++;
  }
  argument++;
 } else { // No delimiters, lower case, stop when you hit = , [ { (
  while ( *argument != '\0' ) {
   if ( char_in( *argument, "\n\r[{(,= " ) ) break;
   (*arg_first)+=(*argument);//string(buf);
   argument++;
  }
 }
 // Advance past spaces and interim commas, equal signs, newlines, skip #comments
 while ( _FILLER(*argument) || *argument == '#' ) {
  if ( *argument == '#' ) while ( *argument != '\n' && *argument != '\r' && *argument != '\0' ) argument++;
  else argument++;
 }
 return argument;
}


/* Pick off one argument from a string and return the rest.
 * Uses std::string thus dynamic and doesn't use the stack.
 * Understands quotes and {}=[](), treats interim commas and equal signs as space.
 */
const char *string_argument_end( const char *argument, string *arg_first, char *sep )
{
 char cEnd = ' ';
// char buf[2];
 (*arg_first)=string("");
 if ( argument == null ) return &string_error; // undef behavior? maybe "" is constant
 // Advance past spaces and interim commas, equal signs, newlines, skip #comments
 while ( _FILLER(*argument) || *argument == '#' ) {
  if ( *argument == '#' ) while ( *argument != '\n' && *argument != '\r' && *argument != '\0' ) argument++;
  else argument++;
 }
 // Handle nested {} [] (), or quotes "" '' ``
 if ( char_in(*argument, "{([`'\"") ) { // Delimiters
  int nests=1;
  char cStart=*argument;
  switch ( cStart ) {
   case '{': cEnd = '}'; break;
   case '[': cEnd = ']'; break;
   case '(': cEnd = ')'; break;
  case '\'': cEnd = '\''; break;
   case '"': cEnd = '"'; break;
   case '`': cEnd = '`'; break;
  }
  argument++;
  while ( *argument != '\0' && nests > 0 ) {
   if ( *argument == cEnd ) {
    nests--;
    if ( nests == 0 ) break;
   } else if ( *argument == cStart ) nests++;
   /*buf[0]=*argument;
   buf[1]='\0';*/
   (*arg_first)+=(*argument);//string(buf);
   argument++;
  }
  argument++;
 } else { // No delimiters, lower case, stop when you hit = , [ { (
  while ( *argument != '\0' ) {
   if ( char_in( *argument, "\n\r[{(,= " ) ) { *sep=*argument; } break;
   /*buf[0]=(*argument);
   buf[1]='\0';*/
   (*arg_first)+=LOWER(*argument);//string(buf);
   argument++;
  }
 }
 // Advance past spaces and interim commas, equal signs, newlines, skip #comments
 while ( _FILLER(*argument) || *argument == '#' ) {
  if ( *argument == '#' ) while ( *argument != '\n' && *argument != '\r' && *argument != '\0' ) argument++;
  else argument++;
 }
 return argument;
}

// Like string_argument_case but with strings
string first_word( string in, string *out ) {
 const char *p=in.c_str();
 p=string_argument_case(p,out);
 return string(p);
}

// Gather until next substring match or end of string (returns the point right after the substring)
const char *gather_to( const char *argument, const char *substr, string *buf ) {
 *buf=string("");
 int substrlen=strlen(substr);
 const char *p=argument;
 bool found=false;
 while ( *p != '\0' && !found ) {
  if ( *p==*substr ) {
   const char *oldp=p;
   const char *q=substr;
   bool match=true;
   int i=0;
   while ( match && i<substrlen ) {
    if ( *p!=*q ) match=false;
    p++;
    q++;
    i++;
   }
   if ( match ) {
    found=true;
    return p;
   }
   else {
    p=oldp;
    *buf+=(*p);
    p++;
   }
  } else {
   *buf+=(*p);
   p++;
  }
 }
 return p;
}

// Gather until character is encountered or end of string.
const char *gather_to( const char *argument, string *out, char sep ) {
 (*out)=string("");
 const char *p=argument;
 while ( *p != '\0' && *p != sep ) {
  (*out)+=(*p);
  p++;
 }
 return p;
}

// Gather until one of 2 characters is encountered or end of string.
const char *gather_to( const char *argument, string *out, char sep, char orsep ) {
 (*out)=string("");
 const char *p=argument;
 while ( *p != '\0' && (*p != sep && *p != orsep) ) {
  (*out)+=(*p);
  p++;
 }
 return p;
}

/* Pick off one argument from a string and return the rest.
 * Understands quotes.
 */
const char *first_split( const char *argument, char *arg_first, char sep )
{
 char cEnd;
 if ( argument == null ) return &string_error;
 while ( (*argument == ' ') || *argument == '\n' || *argument == '\r' ) argument++;
 cEnd = sep;
 if ( *argument == '\'' || *argument == '"' || *argument == '\'' ) cEnd = *argument++;
 else if ( *argument == '{' ) { cEnd='}'; argument++; }
 while ( *argument != '\0' ) {
  if ( *argument == '\n' ) { argument++; if ( cEnd == sep ) break; }
  if ( *argument == '\r' ) { argument++; if ( cEnd == sep ) break; }
  if ( *argument == cEnd ) { argument++; break; }
  *arg_first = LOWER(*argument);
  arg_first++;
  argument++;
 }
 *arg_first = '\0';
 while ( (*argument == sep) || *argument == '\n' || *argument == '\r' ) argument++;
 return argument;
}

/* Pick off one argument from a string and return the rest.
 * Understands quotes.
 */
const char *one_argcase( const char *argument, char *arg_first )
{
 char cEnd;
 if ( argument == null ) return &string_error;
 while ( (*argument == ' ') || *argument == '\n' || *argument == '\r' )	argument++;
 cEnd = ' ';
 if ( *argument == '\'' || *argument == '"' || *argument == '\'' ) cEnd = *argument++;
 else if ( *argument == '{' ) { cEnd='}'; argument++; }
 while ( *argument != '\0' ) {
  if ( *argument == '\n' ) { argument++; if ( cEnd == ' ' ) break; }
  if ( *argument == '\r' ) { argument++; if ( cEnd == ' ' ) break; }
  if ( *argument == cEnd ) { argument++; break;	}
  *arg_first = (*argument);
  arg_first++;
  argument++;
 }
 *arg_first = '\0';
 while ( (*argument == ' ') || *argument == '\n' || *argument == '\r' ) argument++;
 return argument;
}

const char *pop_1stline( const char *argument, string *out ) {
 const char *p=argument;
 (*out)=string("");
 while ( *p != '\0' && *p != '\n' ) {
  (*out)+=(*p);
  p++;
 }
 return p;
}

char * strupper( char * s ) {
 char *u;
 for( u = s; *u != '\0'; u++ ) *u = UPPER(*u);
 return s;
}

char * strlower( char * s ) {
 char *u;
 for( u = s; *u != '\0'; u++ ) *u = LOWER(*u);
 return s;
}

string lower( string a ) {
 int len;
 char *writing=new char[len=a.length()];
 const char *r=a.c_str();
 for ( int x=0; x<len; x++ ) writing[x]=r[x];
 string out=string(writing);
 delete writing;
 return out;
}

/*
 * See if a string is one of the words in the namelist
 */
bool is_name( const char *str, const char *namelist )
{
 char name[STRING_SIZE];
 const char *p;
 if ( str == null || namelist == null ) return false;
 if ( strlen(str) <= 3 ) {
  for ( p = (char *) namelist; ; ) {
  	p = one_argument( p, name );
  	if ( name[0] == '\0' ) return false;
   if ( !str_cmp( str, name ) ) return true; /* str_cmp for full matching */
  }
  for ( p = (char *) namelist; ; ) {
  	p = one_argument( p, name );
  	if ( name[0] == '\0' ) return false;
   if ( !str_cmp( str, name ) ) return true; /* str_cmp for full matching */
  }
 } else {
  for ( p = (char *) namelist; ; ) {
   p = one_argument( p, name );
   if ( name[0] == '\0' ) return false;
   if ( !str_infix( str, name ) ) return true;
  } 
  for ( p = (char *) namelist; ; ) {
   p = one_argument( p, name );
  	if ( name[0] == '\0' ) return false;
   if ( !str_infix( str, name ) ) return true;
  }
 }
}

/*
 * See if a string is one of the keywords in a string.
 * Checks as prefixes.
 */
bool is_prename( const char *str, const char *namelist )
{
 static char name[1024];
 if ( str == null || namelist == null ) return false;
 for ( ; ; ) {
  namelist = one_argument( namelist, name );
  if ( name[0] == '\0' ) return false;
  if ( !str_prefix( str, name ) ) return true;
 }
}

bool valid_characters( const char *fn ) {
 while ( *fn != '\0' ) 
  switch ( *fn++ ) {
   case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': 
   case 'A': case 'B': case 'C': case 'D': case 'E': case 'F': case 'G': case 'H': case 'I': case 'J':
   case 'K': case 'L': case 'M': case 'N': case 'O': case 'P': case 'Q': case 'R': case 'S': case 'T':
   case 'U': case 'V': case 'W': case 'X': case 'Y': case 'Z': 
   case 'a': case 'b': case 'c': case 'd': case 'e': case 'f': case 'g': case 'h': case 'i': case 'j':
   case 'k': case 'l': case 'm': case 'n': case 'o': case 'p': case 'q': case 'r': case 's': case 't':
   case 'u': case 'v': case 'w': case 'x': case 'y': case 'z': 
   case '%': case '_': case '.': case '-': 
   case '\n': case '\0': break;
   default: return false;                
  }   
 return true;
}

// number to string floats
char *ntos( float n, const char *fmt ) {
 static char buf[STRING_SIZE];
 FORMAT(buf,STRING_SIZE,fmt,n);
 return (char *) buf;
}

/*
 * Removes a specified character from a string.
 * Cleans user-entered strings that go into disk files.
 */
void smash_char( char *str, char c )
{
 for ( ; *str != '\0'; str++ )
 if ( *str == c ) *str = '?';
 return;
}

/*
 * Compare strings, case insensitive.
 * Return true if different
 *   (compatibility with historical functions).
 */
bool str_cmp( const char *astr, const char *bstr )
{
 if ( astr == null ) { 
  OUTPUT( "Str_cmp: null astr.\n" );
  return true;
 }
 if ( bstr == null ) { 
  OUTPUT( "Str_cmp: null bstr.\n" );
  return true;
 }
 for ( ; *astr || *bstr; astr++, bstr++ ) if ( LOWER(*astr) != LOWER(*bstr) ) return true;
 return false;
}

bool str_cmp( string astr, string bstr ) {
 return str_cmp( astr.c_str(), bstr.c_str() );
}

bool str_cmp( string astr, const char *bstr ) {
 return str_cmp( astr.c_str(), bstr );
}

/*
 * Compare strings, case sensitive.
 * Return true if different
 *   (compatibility with historical functions).
 */
bool str_cmp_case( const char *astr, const char *bstr )
{
 if ( astr == null ) { 
  OUTPUT( "Str_cmp: null astr.\n" );
  return true;
 }
 if ( bstr == null ) { 
  OUTPUT( "Str_cmp: null bstr.\n" );
  return true;
 }
 for ( ; *astr || *bstr; astr++, bstr++ ) if ( (*astr) != (*bstr) ) return true;
 return false;
}

/*
 * Compare strings, case insensitive, for prefix matching.
 * Return true if astr not a prefix of bstr
 *   (compatibility with historical functions).
 */
bool str_prefix( const char *astr, const char *bstr )
{
 if ( astr == null ) {
  OUTPUT( "Str_prefix: null astr.\n" );
  return true;
 }
 if ( bstr == null ) {
  OUTPUT( "Str_prefix: null bstr.\n" );
  return true;
 }
 for ( ; *astr; astr++, bstr++ ) if ( LOWER(*astr) != LOWER(*bstr) ) return true;
 return false;
}

/*
 * Compare strings, case insensitive, for match anywhere.
 * Returns true if shorter string not part of longer string.
 *   (compatibility with historical functions).
 */
bool str_infix( const char *astr, const char *bstr ) {
 if ( astr == null || *astr == '\0' ) {
  OUTPUT( "Str_infix: null astr (compared against '%s').\n", bstr );
  return true;
 }
 if ( bstr == null || *bstr == '\0' ) {
  OUTPUT( "Str_infix: null bstr (compared against '%s').\n", astr );
  return true;
 }
 char *key;
 char *p,*q;
 // Figure out which string is shorter, and use that as a key (q)
 if ( strlen(astr) > strlen(bstr) ) {
  p= (char *) astr;
  key=q= (char *) bstr;
 }
 else {
  p= (char *) bstr;
  key=q= (char *) astr;
 }
 static char _key[32768];
 _key[0]='\0';
 FORMAT(_key,32768,"%s",key);
 // Make the keyword lowercase;
 q=_key;
 while ( *q != '\0' ) { *q=LOWER(*q); q++; }
 bool found=false;
 q=_key;
 char start=(*q);
 while ( *p!='\0' && !found ) {
  char *was=p;
  if ( LOWER(*p)==start ) {
   q=_key;
   while ( *q != '\0' && *p!='\0' && *q==LOWER(*p) ) { q++; p++; }
   if ( *q == '\0' ) { found=true; break; }
  }
  p=was;
  p++;
 }
 return !found;
 /*
 bool found=false;
 char *p=bstr;
 while ( *p != '\0' ) {
  if ( LOWER(*p) == LOWER(*astr) ) {
   char *b=astr;
   bool matching=true;
   while ( *b != '\0' && *p != '\0' ) {
    if ( LOWER(*b) == LOWER(*p) ) matching&=true;
    b++;
    p++;
   }
   if ( *b == '\0' && matching ) return false;
  }
  p++;
 }
 return true;
 */
}

bool string_infix( string astr, string bstr ) {
 string a=string(astr); std::transform(a.begin(), a.end(), a.begin(),(int(*)(int)) std::tolower);
 string b=string(bstr); std::transform(b.begin(), b.end(), b.begin(),(int(*)(int)) std::tolower);
 if ( b.find(a) != string::npos ) return false;
 return true;
}

/*
 * Compare strings, case insensitive, for suffix matching.
 * Return true if astr not a suffix of bstr
 *   (compatibility with historical functions).
 */
bool str_suffix( const char *astr, const char *bstr )
{
 int sstr1;
 int sstr2;
 if ( !astr || !bstr ) return true;
 sstr1 = strlen(astr);
 sstr2 = strlen(bstr);
 if ( sstr1 <= sstr2 && !str_cmp( astr, bstr + sstr2 - sstr1 ) ) return false;
 else return true;
}

/*
 * Returns an initial-capped string.
 */
char *capitalize( const char *str )
{
 static char strcap[STRING_SIZE];
 int i;
 for ( i = 0; str[i] != '\0'; i++ )
 strcap[i] = str[i];
 strcap[i] = '\0';
 strcap[0] = UPPER(strcap[0]);
 return (char *) strcap;
}

void capitalize( string *in ) {
 *in=string(capitalize(in->c_str()));
}


// Normalizes a string, then limits the total words to col-3, backing up to last ' ' and adding ..
char *LimitTo( const char *s, int col ) {
 static char buf[1024]; // Since we are limiting this, why use STRING_SIZE?
 int i=col-3,j=0;
 if ( strlen(s) <= (unsigned int) (col-3) ) {
  FORMAT(buf,1024,"%s",s);
  return buf;
 }
 while ( s[i] != ' ' ) i--;
 for ( j=0; j<i; j++ ) { buf[j]=s[j]; }
 buf[i]=' ';
 buf[i+1]='.';
 buf[i+2]='.';
 buf[i+3]='\0';
 return buf;
}

// count the number of newline characters
int linefeeds( const char *s ) {
 int total=0,walked=0;
 while ( s && *s != '\0' ) {
  if ( *s=='\n' ) total++;
  s++;
  walked++;
 }
 if ( walked==0 || *(s-1)!='\n' ) total++;
 return total;
}

const char *ParseFloat( const char *line, float *target ) {
 static char x[1024];
 const char *p=one_argument(line,x);
 *target = (float) atof(x);
 return p;
}

const char *ParseInt( const char *line, int *target ) {
 static char x[1024];
 const char *p=one_argument(line,x);
 *target = atoi(x);
 return p;
}

#include <iostream>
#include <fstream>
string file_as_string( const char *filename ) {
  string line,lines=string("");
  ifstream myfile (filename);
  if (myfile.is_open())
  {
    while ( myfile.good() )
    {
      getline (myfile,line);
      lines+=line;//endl;
      lines+=string("\n");
      //cout << line << endl;
    }
    myfile.close();
  }
  else {
   OUTPUT("file_as_string(`%s`) reports an error opening the file\n",filename);
  }
  return lines;
}

void string_as_file( const char *content, const char *filename ) {
 FILE *pFile=fopen(filename,"w");
 if ( pFile ) {
  fwrite (content,sizeof(char),strlen(content),pFile);
  fclose(pFile);
 } else OUTPUT( "string_as_file: Error!  Cannot write '%s'\n", filename );
}

void string_append_file( const char *content, const char *filename ) {
 FILE *pFile=fopen(filename,"a");
 if ( pFile ) {
  fwrite (content,sizeof(char),strlen(content),pFile);
  fclose(pFile);
 } else OUTPUT( "string_append_file: Error!  Cannot write '%s'\n", filename );
}


//#include <Windows.h>
bool file_exists( const char *filename ) {
#if defined(WIN32)
 DWORD fileAttr = GetFileAttributes(filename);
 if (0xFFFFFFFF == fileAttr) return false;
 return true;
#else
#if defined(LINUX)
 ifstream myfile(filename);
 if (myfile.is_open()) {
  int size;
  myfile.seekg (0, ios::end);
  size = (int) myfile.tellg();
  myfile.close();
  return (size != 0);
 }
 return false;
#endif
#endif
}

// Used when writing to a file.
/* in·den·tion (noun) \in-ˈden(t)-shən\ archaic : indentation;
 a: the action of indenting : the condition of being indented
 b: the blank space produced by indenting
 */
string indention=string("");

void incdent() {
 indention+=string(" ");
}

void decdent() {
 int spaces=indention.length();
 spaces--;
 nodent();
 for ( int i=0; i<spaces; i++ ) incdent();
}

void nodent() {
 indention=string("");
}

// Low-brow alphanumeric hash.
string Hash( int len ) {
 if ( len<1 ) len=1;
 char *buf;
 buf = new char[len+1];
 for ( int i=0; i<len; i++ ) buf[i]=randomChar("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890");
 buf[len]='\0';
 string s=string(buf);
 delete buf;
 return s;
}


bool HashCompare5( string *a, string *b ) {
 const char *A=a->c_str();
 const char *B=b->c_str();
 return ( A[0]==B[0] && A[1]==B[1] && A[2]==B[2] && A[3]==B[3] && A[4]==B[4] );
}

// Pseudo-
string RomanNumerals( int v ) {
 switch ( v ) {
 case 1: return string("I");
 case 2: return string("II");
 case 3: return string("III");
 case 4: return string("IV");
 case 5: return string("V");
 case 6: return string("VI");
 case 7: return string("VII");
 case 8: return string("VIII");
 case 9: return string("IX");
 case 10: return string("X");
 case 11: return string("X1");
 case 12: return string("X2");
 case 13: return string("X3");
 case 14: return string("X4");
 case 15: return string("X5");
 case 16: return string("X6");
 case 17: return string("X7");
 case 18: return string("X8");
 case 19: return string("X9");
 case 20: return string("2X");
 case 21: return string("2Xi");
 case 22: return string("2Xii");
 case 23: return string("2Xiii");
 case 24: return string("2Xiv");
 case 25: return string("2Xv");
 case 26: return string("2Xvi");
 case 27: return string("2Xvii");
 case 28: return string("2Xviii");
 case 29: return string("2X9");
 case 30: return string("3X");
 default:
  {
   char buf[128];
   if ( v%10 == 0 ) FORMAT(buf,128,"%d", (int) v);
   else {
    string numbers=RomanNumerals(v%10);
    numbers=lower(numbers);
    FORMAT(buf,128,"%dX%s", (int)(v/10), numbers.c_str() );
   }
   return string(buf);
  }
 }
}

const char *advance_to( const char *start, char c ) {
 const char *p=start;
 while ( *p != '\0' && *p != c ) p++;
 return p;
}

const char *collect_to( const char *start, char c, string &out ) {
 const char *p=start;
 while ( *p != '\0' && *p != c ) {
  out+=(*p);
  p++;
 }
 return p;
}

const char *collect_to( const char *start, char c, string &out, int errlimit ) {
 const char *p=start;
 int collected=0;
 while ( *p != '\0' && *p != c ) {
  out+=(*p);
  collected++;
  if ( collected >= errlimit ) {
   return start;
  }
  p++;
 }
 return p;
}

string ClientCodeFilter( const char *in ) {
 string out=string("");
 const char *p=in;
 return out;
}


const char *str_protect( string in ) {
 static string out;
 out=string("");
 if ( count_char(in.c_str(),'"') == 0 ) {
  out = string("\"")+ in + string("\"");
  return out.c_str();
 } else
 if ( count_char(in.c_str(),'\'') == 0 ) {
  out = string("'") + in + string("'");
  return out.c_str();
 } else
 if ( count_char(in.c_str(),'{') == 0
   && count_char(in.c_str(),'}') == 0 ) {
  out = string("{") + in + string("}");
  return out.c_str();
 } else
 if ( count_char(in.c_str(),'(') == 0
   && count_char(in.c_str(),')') == 0 ) {
  out = string("(") + in + string(")");
  return out.c_str();
 } else
 if ( count_char(in.c_str(),'[') == 0
   && count_char(in.c_str(),']') == 0 ) {
  out = string("[") + in + string("]");
  return out.c_str();
 } else {
  out = string("\x001") + in + string("\x00e");
  return out.c_str();
 }
}


const char *str_protect( int idx, string in ) {
 static string out[10];
 out[idx]=string("");
 if ( count_char(in.c_str(),'"') == 0 ) {
  out[idx] = string("\"")+ in + string("\"");
  return out[idx].c_str();
 } else
 if ( count_char(in.c_str(),'\'') == 0 ) {
  out[idx] = string("'") + in + string("'");
  return out[idx].c_str();
 } else
 if ( count_char(in.c_str(),'{') == 0
   && count_char(in.c_str(),'}') == 0 ) {
  out[idx] = string("{") + in + string("}");
  return out[idx].c_str();
 } else
 if ( count_char(in.c_str(),'(') == 0
   && count_char(in.c_str(),')') == 0 ) {
  out[idx] = string("(") + in + string(")");
  return out[idx].c_str();
 } else
 if ( count_char(in.c_str(),'[') == 0
   && count_char(in.c_str(),']') == 0 ) {
  out[idx] = string("[") + in + string("]");
  return out[idx].c_str();
 } else {
  out[idx] = string("\x001") + in + string("\x00e");
  return out[idx].c_str();
 }
}

