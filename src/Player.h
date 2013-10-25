#pragma once

#include "Time.h"
#include "Strings.h"
#include "Flag.h"
#include "Prop.h"
#include "Material.h"

class Player : public ListItem {
public:
 Unique id;
 Zstring name;
 Zstring password;
 Time created,login,logged;
 Strings values;
 Flags flags;
 Props inventory;
 Materials holdings;
 string toString() {
  string out=string("");
  out+=string("id ")      +string(str_protect(id.toString()));
  out+=string("name ")    +string(str_protect(name.c_str()));
  out+=string("password ")+string(str_protect(password.c_str()));
  out+=string("created ") +string(str_protect(created.toString()));
  out+=string("login ")   +string(str_protect(login.toString()));
  out+=string("logged ")  +string(str_protect(logged.toString()));
  out+=string("values ")  +string(str_protect(values.toString().c_str()));
  out+=string("flags ")   +string(str_protect(flags.toString().c_str()));
  return out;
 }
 void fromString( const char *s ) {
  const char *in=s;
  string one=string("");
  while ( *in != '\0' ) {
   in=string_argument_case(in,&one);
   if ( !str_cmp(one.c_str(), "id" ) ) {
    in=string_argument_case(in,&one);
    id.Set(atoi(one.c_str()));
   } else if ( !str_cmp(one.c_str(),"name") ) {
    name=one;
   } else if ( !str_cmp(one.c_str(),"password") ) {
    in=string_argument_case(in,&one);
    password=one;
   } else if ( !str_cmp(one.c_str(),"created") ) {
    in=string_argument_case(in,&one);
    created.fromString(one.c_str());
   } else if ( !str_cmp(one.c_str(),"login") ) {
    in=string_argument_case(in,&one);
    login.fromString(one.c_str());
   } else if ( !str_cmp(one.c_str(),"logged") ) {
    in=string_argument_case(in,&one);
    logged.fromString(one.c_str());
   } else if ( !str_cmp(one.c_str(),"values") ) {
    in=string_argument_case(in,&one);
    values.fromString(one);
   } else if ( !str_cmp(one.c_str(),"flags") ) {
    in=string_argument_case(in,&one);
    flags.fromString(one);
   }
  }
 }
};

class Players : public LinkedList {
public:
 string toString() {
  string out=string("");
  FOREACH(Player,p) out += string("player {\n")+p->toString()+string("\n}\n");
  return out;
 }
 void Save( const char *filename ) {
  string out=toString();
  string_append_file(out.c_str(),filename);
 }
 Player *find( const char *name ) {
  FOREACH(Player,p) if ( !str_cmp(p->name.c_str(),name) ) return p;
  return null;
 }
 CLEARLISTRESET(Player);
};

extern Players players;
