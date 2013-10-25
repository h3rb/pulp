#pragma once
#include "string_functions.h"
#include "LinkedList.h"
#include "Strings.h"

class ConfigFile : public ListItem {
public:
 Strings definitions;
 Zstring name,filename;
 ConfigFile() : ListItem() {
  filename=string("");
 }
 ConfigFile( const char *fn ) : ListItem() {
  Load(fn);
 }
 ConfigFile( const char *name, const char *fn ) : ListItem() {
  this->name=string(name);
  Load(fn);
 }
 KeyValuePair *Define( const char *key, const char *value ) {
  KeyValuePair *definition=pair(key);
#if defined(DEBUG)
  if ( definition ) {
   OUTPUT("Reassigning symbol `%s` to `%s`\n", key, value );
   definition->Set(value);
   OUTPUT("integer = %d, float = %1.9f\n", definition->integer, definition->floating );
  } else {
   OUTPUT("Assigning new symbol `%s` = `%s`\n", key, value );
   definition=Define( key, value );
   OUTPUT("integer = %d, float = %1.9f\n", definition->integer, definition->floating );
  }
#else
  if ( definition ) definition->Set(value);
  else
  definitions.Append(definition=new KeyValuePair( key, value ));
#endif
  return definition;
 }
 KeyValuePair *pair( const char *key ) {
  EACH(definitions.first,KeyValuePair,kv) if ( !str_cmp( key, kv->s.c_str() ) ) return kv;
  return null;
 }
 KeyValuePair *pair( const char *key, bool caseSensitive ) {
  EACH(definitions.first,KeyValuePair,kv) if ( !str_cmp_case( key, kv->s.c_str() ) ) return kv;
  return null;
 }
 string any() {
  KeyValuePair *s=(KeyValuePair *)definitions.Any();
  if ( s ) return s->value;
  else return string("");
 }
 string find( const char *key ) {
  KeyValuePair *p=pair(key);
  if ( p ) return p->value;
  else return string("");
 }
 string find( const char *key, bool caseSensitive ) {
  KeyValuePair *p=pair(key,caseSensitive);
  if ( p ) return p->value;
  else return string("");
 }
 void Load( string fn ) { Load(fn.c_str()); }
 void Load( const char *fn ) {
  OUTPUT("ConfigFile::Load(`%s`)\n", fn );
  filename=string(fn);
  string in=file_as_string(fn);
  Strings keys;
  Strings values;
  const char *p=in.c_str();
  string piece=string("");
  while ( *p != '\0' ) {
   p=string_argument_case(p,&piece);
   keys.Add(piece);
   if ( *p != '\0' ) {
    p=string_argument_case(p,&piece);
    values.Add(piece);
   }
  }
  if ( keys.count != values.count ) {
   OUTPUT("ConfigFile::Load(`%s`) warns: %d keys and %d values (inequality).\n",
    filename.c_str(),
    (int) keys.count,
    (int) values.count
   );
  } else
  OUTPUT("ConfigFile::Load(`%s`) loaded %d symbol definitions\n",
   filename.c_str(), (int) keys.count );
  String *v=(String *) values.first;
  EACH(keys.first,String,k) {
   if ( v ) {
    Define( k->s.c_str(), v->s.c_str() );
    v=(String *)v->next;
   }
   else Define( k->s.c_str(), "" );
  }
 }
 void Save() { Save(filename.c_str()); }
 void Save( const char *fn ) {
  OUTPUT("ConfigFile::Save(`%s`)\n", fn );
  string out=string("");
  EACH(definitions.first,KeyValuePair,kv) {
   out+=ProtectString(kv->s)+ProtectString(kv->value);
  }
 }
 string ProtectString( string s ) {
  string out=string("");
  bool hasBrace=contains(s,'{')||contains(s,'}');
  bool hasBracket=contains(s,'[')||contains(s,']');
  bool hasParenthesis=contains(s,'(')||contains(s,')');
  bool hasQuote=contains(s,'"');
  bool hasApostrophe=contains(s,'\'');
  if ( !hasBrace ) {
   out+=string("{")+s+string("}");
  } else if ( !hasBracket ) {
   out+=string("[")+s+string("]");
  } else if ( !hasParenthesis ) {
   out+=string("(")+s+string(")");
  } else if ( !hasQuote ) {
   out+=string("\"")+s+string("\"");
  } else if ( !hasApostrophe ) {
   out+=string("'")+s+string("'");
  } else {
   int Lbraces    =count_char( s, '{' );
   int Rbraces    =count_char( s, '}' );
   if ( Lbraces == Rbraces ) {
    out+=string("{")+s+string("}");
   } else {
    int Lbrackets  =count_char( s, '[' );
    int Rbrackets  =count_char( s, ']' );
    if ( Lbrackets == Rbrackets ) {
     out+=string("[")+s+string("]");
    } else {
     int Lparen     =count_char( s, '(' );
     int Rparen     =count_char( s, ')' );
     if ( Lparen == Rparen ) {
      out+=string("(")+s+string(")");
     } else {
      int quotes     =count_char( s, '"' );
      if ( quotes %2 == 0 ) {
       out+=string("\"")+s+string("\"");
      } else {
       int apostrophes=count_char( s, '\'' );
       if ( apostrophes %2 == 0 ) {
        out+=string("[")+s+string("]");
       } else { // In this case, everything is mismatched, this case is RARE,
                // and the string cannot be contained properly with {}[]()''"".
                // We use the special codes '\x001' and '\x00e' to designate this.
        out+=string("\x001")+s+string("\x00E");
       }
      }
     }
    }
   }
  }
  return out;
 }
};

class ConfigFiles : public LinkedList {
public:
 Zp<ConfigFile> config;
 Zp<KeyValuePair> kv;
 Zbool found;
 void Load( ConfigFile *list ) {
  EACH(list->definitions.first,KeyValuePair,kv)
   Append(new ConfigFile(kv->s.c_str(),kv->value.c_str()));
 }
 void Load( const char *filename ) {
  Append(new ConfigFile(filename));
 }
 void Load( const char *name, const char *filename ) {
  Append(new ConfigFile(name,filename));
 }
 string find( const char *name, const char *key ) {
  string out=string("");
  found=false;
  FOREACH(ConfigFile,c) if ( !str_cmp(name,c->name.c_str()) ) {
   KeyValuePair *kvp=c->pair(key);
   if ( kvp ) {
    kv=kvp;
    config=c;
    out=kvp->value;
    found=true;
    break;
   }
  }
  if ( !found ) {
   ConfigFile *f=file(name);
   if ( !f ) OUTPUT("ConfigFiles::find(`%s`,`%s`) could not find `%s`\n", name, key, name );
   else {
    KeyValuePair *kvp=f->pair(key);
    if ( !kvp )
    OUTPUT("ConfigFiles::find(`%s`,`%s`) could not find `%s`\n", name, key, key );
   }
  }
  return out;
 }
 string any( const char *name ) {
  ConfigFile *f=file(name);
  if ( f ) return f->any();
  return string("");
 }
 string find( const char *key ) {
  string out=string("");
  FOREACH(ConfigFile,c) {
   KeyValuePair *kvp=c->pair(key);
   if ( kvp ) {
    config=c;
    kv=kvp;
    out=kvp->value;
    break;
   }
  }
  return out;
 }
 ConfigFile *file( const char *name ) {
  FOREACH(ConfigFile,f) if ( !str_cmp( f->name.c_str(), name ) ) return f;
  return null;
 }
 KeyValuePair *pair( const char *key ) {
  FOREACH(ConfigFile,f) {
   KeyValuePair *kvp=f->pair(key);
   if ( kvp ) return kvp;
  }
  return null;
 }
 KeyValuePair *pair( const char *name, const char *key ) {
  ConfigFile *f=file(name);
  if ( !f ) return null;
  return f->pair(key);
 }
 float floating( const char *key ) {
  KeyValuePair *kvp=pair(key);
  found=true;
  if ( kvp ) return kvp->floating;
  found=false;
  return 0.0f;
 }
 float floating( const char *name, const char *key ) {
  KeyValuePair *kvp=pair(name,key);
  found=true;
  if ( kvp ) return kvp->floating;
  found=false;
  return 0.0f;
 }
 int integer( const char *name, const char *key ) {
  KeyValuePair *kvp=pair(name,key);
  found=true;
  if ( kvp ) return kvp->integer;
  found=false;
  return 0;
 }
 int integer( const char *key ) {
  KeyValuePair *kvp=pair(key);
  found=true;
  if ( kvp ) return kvp->integer;
  found=false;
  return 0;
 }
 bool boolean( const char *key ) {
  KeyValuePair *kvp=pair(key);
  found=true;
  if ( kvp ) return kv->integer > 0;
  return false;
 }
 bool boolean( const char *name, const char *key ) {
  KeyValuePair *kvp=pair(name,key);
  found=true;
  if ( kvp ) return kv->integer > 0;
  return false;
 }
 CLEARLISTRESET(ConfigFile);
};

extern ConfigFiles cfg;
