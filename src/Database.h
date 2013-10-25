#pragma once

#include "ListItem.h"
#include "Globals.h"

/*
enum DataTypes {
 _material=0,
 _prototype=1,
 _genetics=2,
 _blueprint=3,
 _geology=4,
 _prop=5,
 _actor=6,
 _scene=7,
 _geography=8,
 _nation=9,
 _empire=10,
 _planet=11,
 _system=12,
 _galaxy=13,
 _dimension=14,
 _player=15
};
 */

class Database : public ListItem {
public:
 Zstring current_file;
 void Load( const char *filename ) {
  OUTPUT("Loading database:\n");
  this->current_file=string(filename);
  string file=file_as_string(filename);
  fromString(file);
  OUTPUT("Database load complete.\n");
 }
 void Save( const char *filename ) {
  OUTPUT("Saving database.\n");
  string empty=string("");
  string_as_file(empty.c_str(),filename);
  materials.Save(filename);
  prototypes.Save(filename);
  species.Save(filename);
  blueprints.Save(filename);
  props.Save(filename);
  actors.Save(filename);
  geologies.Save(filename);
  geographies.Save(filename);
  scenes.Save(filename);
  cultures.Save(filename);
  nations.Save(filename);
  empires.Save(filename);
  planets.Save(filename);
  systems.Save(filename);
  galaxies.Save(filename);
  dimensions.Save(filename);
  players.Save(filename);
  OUTPUT("Database saved.\n");
 }
 Player *player( const char *name ) {
  return players.find(name);
 }
 const char *ParseKey( const char *p, string key ) {
  const char *out=p;
  string value=string("");
  if ( !str_cmp( key, "material" ) ) {
   out=string_argument_case( out, &value );
   materials.AppendFromString(value);
  } else if ( !str_cmp( key, "prototype" ) ) {
   out=string_argument_case( out, &value );
   prototypes.AppendFromString(value);
  } else if ( !str_cmp( key, "genetics" ) ) {
   out=string_argument_case( out, &value );
   species.AppendFromString(value);
  } else if ( !str_cmp( key, "blueprint" ) ) {
   out=string_argument_case( out, &value );
   blueprints.AppendFromString(value);
  } else if ( !str_cmp( key, "geology" ) ) {
   out=string_argument_case( out, &value );
   geologies.AppendFromString(value);
  } else if ( !str_cmp( key, "prop" ) ) {
   out=string_argument_case( out, &value );
   props.AppendFromString(value);
  } else if ( !str_cmp( key, "actor" ) ) {
   out=string_argument_case( out, &value );
   actors.AppendFromString(value);
  } else if ( !str_cmp( key, "scene" ) ) {
   out=string_argument_case( out, &value );
   scenes.AppendFromString(value);
  } else if ( !str_cmp( key, "geography") ) {
   out=string_argument_case( out, &value );
   geographies.AppendFromString(value);
  } else if ( !str_cmp( key, "nation" ) ) {
   out=string_argument_case( out, &value );
   nations.AppendFromString(value);
  } else if ( !str_cmp( key, "empire" ) ) {
   out=string_argument_case( out, &value );
   empires.AppendFromString(value);
  } else if ( !str_cmp( key, "planet" ) ) {
   out=string_argument_case( out, &value );
   planets.AppendFromString(value);
  } else if ( !str_cmp( key, "system" ) ) {
   out=string_argument_case( out, &value );
   systems.AppendFromString(value);
  } else if ( !str_cmp( key, "galaxy" ) ) {
   out=string_argument_case( out, &value );
   galaxies.AppendFromString(value);
  } else if ( !str_cmp( key, "dimension" ) ) {
   out=string_argument_case( out, &value );
   dimensions.AppendFromString(value);
  } else if ( !str_cmp( key, "player" ) ) {
   out=string_argument_case( out, &value );
   players.AppendFromString(value);
  } else {
   OUTPUT("Database:Load(`%s`) ignored an invalid key:\n%s\n",
    current_file.c_str(), key.c_str() );
  }
  return out;
 }
};

extern Database database;
