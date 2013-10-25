#pragma once

#include "LinkedList.h"

class Material : public ListItem {
public:
 Zstring name;
 Zstring description;
 Zdouble weight;
 Zdouble density;
 Material() : ListItem() {}
 Material( string one ) : ListItem() { fromString(one); }
 string toString() {
  string _name=string(str_protect(name));
  string _description=string(str_protect(description));
  return
   string("name ")+_name
  +string("\ndescription\n")+_description
  +FORMAT(buf,512,"\nweight %1.9f density %1.9f",
   (double) weight,
   (double) density
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
  } else if ( !str_cmp( key, "weight" ) ) {
   out=string_argument_case( out, &value );
   weight=atof(value.c_str());
  } else if ( !str_cmp( key, "density" ) ) {
   out=string_argument_case( out, &value );
   density=atof(value.c_str());
  }
  return out;
 }
};

class Materials : public LinkedList {
public:
 string toString() {
  string out=string("");
  FOREACH(Material,m) {
   out += string("material {\n")+m->toString()+string("\n}\n");
  }
  return out;
 }
 void Save( const char *filename ) {
  string out=toString();
  string_append_file(out.c_str(),filename);
 }
 void AppendFromString( string one ) { Append(new Material(one)); }
 Material *findByName( string name ) { return findByName(name.c_str()); }
 Material *findByName( const char *name ) {
  FOREACH(Material,m) if ( !str_cmp( name, "name" ) ) return m;
  return null;
 }
 CLEARLISTRESET(Material);
};

extern Materials materials;

class MaterialRarity : public ListItem {
public:
 Zp<Material> material;
 Zdouble abundance;
 MaterialRarity() : ListItem() {}
 MaterialRarity( string one ) : ListItem() { fromString(one); }
 string toString() {
  if ( !material ) return string("");
  string _material=string(str_protect(material->name));
  return
   string("material ")+_material
  +FORMAT(buf,512,"abundance %1.9f", (double) abundance )
  ;
 }
 const char *ParseKey( const char *p, string key ) {
  string value;
  const char *out=p;
  if ( !str_cmp( key, "material" ) ) {
   out=string_argument_case( out, &value );
   material=materials.findByName(value);
  } else if ( !str_cmp( key, "abundance" ) ) {
   out=string_argument( out, &value );
   abundance=atof(value.c_str());
  }
  return out;
 }
};

class MaterialRarities : public LinkedList {
public:
 void AppendFromString( string one ) { Append(new MaterialRarity(one)); }
 CLEARLISTRESET(MaterialRarity);
};

class MaterialQuantity : public ListItem {
public:
 Zp<Material> material;
 Zdouble quantity;
 MaterialQuantity() : ListItem() {}
 MaterialQuantity( string one ) : ListItem() { fromString(one); }
 string toString() {
  if ( !material ) return string("");
  string _material=string(str_protect(material->name));
  return
   string("material ")+_material
  +FORMAT(buf,512,"quantity %1.9f", (double) quantity )
  ;
 }
 const char *ParseKey( const char *p, string key ) {
  string value;
  const char *out=p;
  if ( !str_cmp( key, "material" ) ) {
   out=string_argument_case( out, &value );
   material=materials.findByName(value);
  } else if ( !str_cmp( key, "quantity" ) ) {
   out=string_argument( out, &value );
   quantity=atof(value.c_str());
  }
  return out;
 }
};

class MaterialQuantities : public LinkedList {
public:
 void AppendFromString( string one ) { Append(new MaterialQuantity(one)); }
 CLEARLISTRESET(MaterialQuantity);
};
