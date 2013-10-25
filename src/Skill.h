#pragma once

#include "ModifiedStatistic.h"

class Skill : public ListItem {
public:
 Zstring name;
 Zstring description;
 Strings keywords;
 Zdouble delta,initial,maximum;
 string toString() {
  string _keywords=keywords.toSimpleString();
  string _name=string(str_protect(name));
  string _description=string(str_protect(description));
  return
   string("name ")+_name
  +string("description ")+_description
  +string("keywords {")+_keywords+string("} ")
  +FORMAT(buf,512,"delta %1.9f initial %1.9f maximum %1.9f",
    (double) delta,
    (double) initial,
    (double) maximum
   );
 }
 const char *ParseKey( const char *p, string key ) {
  string value;
  const char *out=p;
  if ( !str_cmp( key, "name" ) ) {
   out=string_argument_case( out, &value );
   name=value;
  } else if ( !str_cmp( key, "description" ) ) {
   out=string_argument_case( out, &value );
   description=value;
  } else if ( !str_cmp( key, "keywords" ) ) {
   out=string_argument( out, &value );
   keywords.fromSimpleStringCase( value );
  } else if ( !str_cmp( key, "delta" ) ) {
   out=string_argument( out, &value );
   delta=atof(value.c_str());
  } else if ( !str_cmp( key, "initial" ) ) {
   out=string_argument( out, &value );
   initial=atof(value.c_str());
  } else if ( !str_cmp( key, "maximum" ) ) {
   out=string_argument( out, &value );
   maximum=atof(value.c_str());
  }
  return out;
 }
};

class Skills : public LinkedList {
public:
 CLEARLISTRESET(Skill);
};

extern Skills skills;

class AcquiredSkill : public ListItem {
public:
};

class AcquiredSkills : public LinkedList {
public:
 CLEARLISTRESET(AcquiredSkill);
};
