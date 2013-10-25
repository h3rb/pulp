#pragma once
#include "macros.h"
#include "moremath.h"
#include "string_functions.h"

// POD-type replacements

#define Zp Zpointer
#define Zb Zbool
#define Zi Zint
#define Zf Zfloat
#define Zd Zdouble
#define Zui Zuint
#define Zus Zushort

// Divide by zero protection and report

#define DIV_BY_ZERO_PROTECTION 1

#if !defined(DIV_BY_ZERO_REPORTING) && ( defined(_DEBUG) || defined(DEBUG) || defined(DEBUG_OUTPUT) )
#define DIV_BY_ZERO_REPORTING 1
#endif

// Unsigned subtraction "wrap" protection and report

#define UNSIGNED_SUBTRACTION_WRAP_PROTECTION 1

#if !defined(UNSIGNED_SUBTRACTION_WRAP_REPORTING) && ( defined(_DEBUG) || defined(DEBUG) || defined(DEBUG_OUTPUT) )
#define UNSIGNED_SUBTRACTION_WRAP_REPORTING 1
#endif

// Unsigned addition "wrap" protection and report

#define UNSIGNED_ADDITION_WRAP_PROTECTION 1

#if !defined(UNSIGNED_ADDITION_WRAP_REPORTING) && ( defined(_DEBUG) || defined(DEBUG) || defined(DEBUG_OUTPUT) )
#define UNSIGNED_ADDITION_WRAP_REPORTING 1
#endif

// Unsigned multiplication "wrap" protection and report

#define UNSIGNED_MULTIPLY_WRAP_PROTECTION 1

#if !defined(UNSIGNED_MULTIPLY_WRAP_REPORTING) && ( defined(_DEBUG) || defined(DEBUG) || defined(DEBUG_OUTPUT) )
#define UNSIGNED_MULTIPLY_WRAP_REPORTING 1
#endif

/// Zbool /////////////////////////////////////////////////////////////////////////////////////////// start

class Zbool {
public:
 bool value;
 Zbool() { value=false; }
 Zbool( bool b ) { this->value=b; }
 operator bool *() { return &value; }
 Zbool *operator()() { return this; }
 Zbool& operator= ( const bool b ) { value=b; return *this; }
 Zbool& operator|= ( const bool b ) { value|=b; return *this; }
 Zbool& operator&= ( const bool b ) { value&=b; return *this; }
 const bool operator-() { return !value; }
 operator bool() { return value; }
};

/// Zbool /////////////////////////////////////////////////////////////////////////////////////////// end

/// Zwas //////////////////////////////////////////////////////////////////////////////////////////// start

class Zwas {
public:
 bool value,was;
 Zwas() { value=was=false; }
 Zwas( bool b ) { this->value=b; }
 operator bool *() { return &value; }
 Zwas *operator()() { return this; }
 Zwas& operator= ( const bool b ) { was=value; value=b; return *this; }
 Zwas& operator|= ( const bool b ) { value|=b; return *this; }
 Zwas& operator&= ( const bool b ) { value&=b; return *this; }
 void Store() {
  was=value;
 }
 const bool operator-() { return !value; }
 operator bool() { return value; }
};

/// Zwas //////////////////////////////////////////////////////////////////////////////////////////// end

// Forward declarations
class Zbyte;
class Zushort;
class Zuint;
class Zint;
class Zdouble;
class Zstring;

/// Zfloat ////////////////////////////////////////////////////////////////////////////////////////// start

class Zfloat {
public:
 float value;
 Zfloat() { value=0.0f; }
 Zfloat( float value ) { value=this->value; }
 float abs() { return absf(value); }
 operator float *() { return &value; }
 Zfloat *operator()() { return this; }
 float operator()( int i ) { return value=(float)i; }
 float operator()( float f ) { return value=f; }
 float operator()( double d ) { return value=(float)d; }
 float operator()( Zbyte &b );
 float operator()( Zuint &i );
 float operator()( Zint &i );
 float operator()( Zfloat &f );
 float operator()( Zdouble &d );
 Zfloat& operator= ( const unsigned char b ) { value=(float) b; return *this; }
 Zfloat& operator= ( const unsigned int i ) { value=(float) i; return *this; }
 Zfloat& operator= ( const int i ) { value=(float) i; return *this; }
 Zfloat& operator= ( const float f ) { value=f; return *this; }
 Zfloat& operator= ( const double d ) { value=(float) d; return *this; }
 Zfloat& operator= ( const Zbyte& b );
 Zfloat& operator= ( const Zuint& i );
 Zfloat& operator= ( const Zint& i );
 Zfloat& operator= ( const Zfloat& f ) { value=f.value; return *this; }
 Zfloat& operator= ( const Zdouble& d );
 Zfloat& operator= ( const Zstring& s );
 Zfloat& operator+= ( const Zfloat& f ) { value+=f.value; return *this; }
 Zfloat& operator-= ( const Zfloat& f ) { value-=f.value; return *this; }
 Zfloat& operator*= ( const Zfloat& f ) { value*=f.value; return *this; }
 Zfloat& operator/= ( const Zfloat& f ) { value/=f.value; return *this; }
 Zfloat& operator+= ( const Zint& i );
 Zfloat& operator-= ( const Zint& i );
 Zfloat& operator*= ( const Zint& i );
 Zfloat& operator/= ( const Zint& i );
 Zfloat& operator+= ( const unsigned char f ) { value+=(float)f; return *this; }
 Zfloat& operator-= ( const unsigned char f ) { value-=(float)f; return *this; }
 Zfloat& operator*= ( const unsigned char f ) { value*=(float)f; return *this; }
 Zfloat& operator/= ( const unsigned char f ) { value/=(float)f; return *this; }
 Zfloat& operator+= ( const unsigned short f ) { value+=(float)f; return *this; }
 Zfloat& operator-= ( const unsigned short f ) { value-=(float)f; return *this; }
 Zfloat& operator*= ( const unsigned short f ) { value*=(float)f; return *this; }
 Zfloat& operator/= ( const unsigned short f ) { value/=(float)f; return *this; }
 Zfloat& operator+= ( const int f ) { value+=(float)f; return *this; }
 Zfloat& operator-= ( const int f ) { value-=(float)f; return *this; }
 Zfloat& operator*= ( const int f ) { value*=(float)f; return *this; }
 Zfloat& operator/= ( const int f ) { value/=(float)f; return *this; }
 Zfloat& operator+= ( const unsigned int f ) { value+=(float)f; return *this; }
 Zfloat& operator-= ( const unsigned int f ) { value-=(float)f; return *this; }
 Zfloat& operator*= ( const unsigned int f ) { value*=(float)f; return *this; }
 Zfloat& operator/= ( const unsigned int f ) { value/=(float)f; return *this; }
 Zfloat& operator+= ( const float f ) { value+=f; return *this; }
 Zfloat& operator-= ( const float f ) { value-=f; return *this; }
 Zfloat& operator*= ( const float f ) { value*=f; return *this; }
 Zfloat& operator/= ( const float f ) { value/=f; return *this; }
 Zfloat& operator+= ( const double f ) { value+=(float)f; return *this; }
 Zfloat& operator-= ( const double f ) { value-=(float)f; return *this; }
 Zfloat& operator*= ( const double f ) { value*=(float)f; return *this; }
 Zfloat& operator/= ( const double f ) { value/=(float)f; return *this; }
 Zfloat& operator++ (int) { value+=1.0f; return *this; }
 Zfloat& operator-- (int) { value-=1.0f; return *this; }
 const float operator-() { return -value; }
 operator float() { return value; }
 bool operator !() { return ( value == 0.0f ); }
// Not used intentionally to create warning:
// operator double() { return (double) value; }
// operator int() { return (int) value; }
// Causes ambiguity, because this is removed, the resulting issue (no better solution, see C2593)
// (mixed type comparisons require explicit casts) is described in the test:
// operator double() { return (double) value; }
// operator int() { return (int) value; }
};

// Mixed type interactions
float operator+ ( const Zfloat& a, const Zint& b );
float operator+ ( const Zint& a, const Zfloat& b );
float operator* ( const Zfloat& a, const Zint& b );
float operator* ( const Zint& a, const Zfloat& b );
// Float and itself
float operator+ ( const Zfloat& a, const Zfloat& b );
float operator- ( const Zfloat& a, const Zfloat& b );
float operator* ( const Zfloat& a, const Zfloat& b );
float operator/ ( const Zfloat& a, const Zfloat& b );
// Casted int operations
float operator+ ( const Zfloat& a, int b );
float operator- ( const Zfloat& a, int b );
float operator* ( const Zfloat& a, int b );
float operator/ ( const Zfloat& a, int b );
float operator+ ( int b, const Zfloat& a );
float operator- ( int b, const Zfloat& a );
float operator* ( int b, const Zfloat& a );
float operator/ ( int b, const Zfloat& a );
// Float operations
float operator+ ( const Zfloat& a, float b );
float operator- ( const Zfloat& a, float b );
float operator* ( const Zfloat& a, float b );
float operator/ ( const Zfloat& a, float b );
float operator+ ( float b, const Zfloat& a );
float operator- ( float b, const Zfloat& a );
float operator* ( float b, const Zfloat& a );
float operator/ ( float b, const Zfloat& a );
// Casted double operations (leans toward double precision)
float operator+ ( const Zfloat& a, double b );
float operator- ( const Zfloat& a, double b );
float operator* ( const Zfloat& a, double b );
float operator/ ( const Zfloat& a, double b );
float operator+ ( double b, const Zfloat& a );
float operator- ( double b, const Zfloat& a );
float operator* ( double b, const Zfloat& a );
float operator/ ( double b, const Zfloat& a );
// Boolean operations
bool operator>= ( const Zfloat& a, const Zfloat& b );
bool operator>= ( const Zfloat& a, const Zbyte& b );
bool operator>= ( const Zfloat& a, const Zushort& b );
bool operator>= ( const Zfloat& a, const Zuint& b );
bool operator>= ( const Zfloat& a, const Zint& b );
bool operator>= ( const Zfloat& a, const Zdouble& b );
bool operator>= ( const Zbyte& a, const Zfloat& b );
bool operator>= ( const Zushort& a, const Zfloat& b );
bool operator>= ( const Zuint& a, const Zfloat& b );
bool operator>= ( const Zint& a, const Zfloat& b );
bool operator>= ( const Zdouble& a, const Zfloat& b );
bool operator>= ( const Zfloat& a, int b );
bool operator>= ( const Zfloat& a, float b );
bool operator>= ( const Zfloat& a, double b );
bool operator>= ( int a, const Zfloat& b );
bool operator>= ( float a, const Zfloat& b );
bool operator>= ( double a, const Zfloat& b );
bool operator== ( const Zfloat& a, const Zfloat& b );
bool operator== ( const Zfloat& a, const Zbyte& b );
bool operator== ( const Zfloat& a, const Zushort& b );
bool operator== ( const Zfloat& a, const Zuint& b );
bool operator== ( const Zfloat& a, const Zint& b );
bool operator== ( const Zfloat& a, const Zdouble& b );
bool operator== ( const Zbyte& a, const Zfloat& b );
bool operator== ( const Zushort& a, const Zfloat& b );
bool operator== ( const Zuint& a, const Zfloat& b );
bool operator== ( const Zint& a, const Zfloat& b );
bool operator== ( const Zdouble& a, const Zfloat& b );
bool operator== ( const Zfloat& a, int b );
bool operator== ( const Zfloat& a, float b );
bool operator== ( const Zfloat& a, double b );
bool operator== ( int a, const Zfloat& b );
bool operator== ( float a, const Zfloat& b );
bool operator== ( double a, const Zfloat& b );
bool operator!= ( const Zfloat& a, const Zfloat& b );
bool operator!= ( const Zfloat& a, const Zbyte& b );
bool operator!= ( const Zfloat& a, const Zushort& b );
bool operator!= ( const Zfloat& a, const Zuint& b );
bool operator!= ( const Zfloat& a, const Zint& b );
bool operator!= ( const Zfloat& a, const Zdouble& b );
bool operator!= ( const Zbyte& a, const Zfloat& b );
bool operator!= ( const Zushort& a, const Zfloat& b );
bool operator!= ( const Zuint& a, const Zfloat& b );
bool operator!= ( const Zint& a, const Zfloat& b );
bool operator!= ( const Zdouble& a, const Zfloat& b );
bool operator!= ( const Zfloat& a, int b );
bool operator!= ( const Zfloat& a, float b );
bool operator!= ( const Zfloat& a, double b );
bool operator!= ( int a, const Zfloat& b );
bool operator!= ( float a, const Zfloat& b );
bool operator!= ( double a, const Zfloat& b );
bool operator<= ( const Zfloat& a, const Zfloat& b );
bool operator<= ( const Zfloat& a, const Zbyte& b );
bool operator<= ( const Zfloat& a, const Zushort& b );
bool operator<= ( const Zfloat& a, const Zuint& b );
bool operator<= ( const Zfloat& a, const Zint& b );
bool operator<= ( const Zfloat& a, const Zdouble& b );
bool operator<= ( const Zbyte& a, const Zfloat& b );
bool operator<= ( const Zushort& a, const Zfloat& b );
bool operator<= ( const Zuint& a, const Zfloat& b );
bool operator<= ( const Zint& a, const Zfloat& b );
bool operator<= ( const Zdouble& a, const Zfloat& b );
bool operator<= ( const Zfloat& a, int b );
bool operator<= ( const Zfloat& a, float b );
bool operator<= ( const Zfloat& a, double b );
bool operator<= ( int a, const Zfloat& b );
bool operator<= ( float a, const Zfloat& b );
bool operator<= ( double a, const Zfloat& b );
bool operator> ( const Zfloat& a, const Zfloat& b );
bool operator> ( const Zfloat& a, const Zbyte& b );
bool operator> ( const Zfloat& a, const Zushort& b );
bool operator> ( const Zfloat& a, const Zuint& b );
bool operator> ( const Zfloat& a, const Zint& b );
bool operator> ( const Zfloat& a, const Zdouble& b );
bool operator> ( const Zbyte& a, const Zfloat& b );
bool operator> ( const Zushort& a, const Zfloat& b );
bool operator> ( const Zuint& a, const Zfloat& b );
bool operator> ( const Zint& a, const Zfloat& b );
bool operator> ( const Zdouble& a, const Zfloat& b );
bool operator> ( const Zfloat& a, int b );
bool operator> ( const Zfloat& a, float b );
bool operator> ( const Zfloat& a, double b );
bool operator> ( int a, const Zfloat& b );
bool operator> ( float a, const Zfloat& b );
bool operator> ( double a, const Zfloat& b );
bool operator< ( const Zfloat& a, const Zfloat& b );
bool operator< ( const Zfloat& a, const Zbyte& b );
bool operator< ( const Zfloat& a, const Zushort& b );
bool operator< ( const Zfloat& a, const Zuint& b );
bool operator< ( const Zfloat& a, const Zint& b );
bool operator< ( const Zfloat& a, const Zdouble& b );
bool operator< ( const Zbyte& a, const Zfloat& b );
bool operator< ( const Zushort& a, const Zfloat& b );
bool operator< ( const Zuint& a, const Zfloat& b );
bool operator< ( const Zint& a, const Zfloat& b );
bool operator< ( const Zdouble& a, const Zfloat& b );
bool operator< ( const Zfloat& a, int b );
bool operator< ( const Zfloat& a, float b );
bool operator< ( const Zfloat& a, double b );
bool operator< ( int a, const Zfloat& b );
bool operator< ( float a, const Zfloat& b );
bool operator< ( double a, const Zfloat& b );

/// Zfloat ////////////////////////////////////////////////////////////////////////////////////////// end

/// Zbyte ////////////////////////////////////////////////////////////////////////////////////////// start

class Zbyte {
public:
 unsigned char value;
 Zbyte() { value=0; }
 Zbyte( unsigned char value ) { this->value=value; }
 operator unsigned char *() { return &value; }
 Zbyte *operator()() { return this; }
 unsigned char operator()( unsigned char b ) { return value=b; }
 unsigned char operator()( unsigned int i ) { return value=(unsigned char)i; }
 unsigned char operator()( int i ) { return value=(unsigned char) i; }
 unsigned char operator()( float f ) { return value=(unsigned char) f; }
 unsigned char operator()( double d ) { return value=(unsigned char) d; }
 unsigned char operator()( Zuint &i );
 unsigned char operator()( Zint &i );
 unsigned char operator()( Zfloat &f );
 unsigned char operator()( Zdouble &d );
 Zbyte& operator= ( const unsigned char b ) { value=b; return *this; }
 Zbyte& operator= ( const int i ) { value=(unsigned char)i; return *this; }
 Zbyte& operator= ( const float f ) { value=(unsigned char)f; return *this; }
 Zbyte& operator= ( const double d ) { value=(unsigned char) d; return *this; }
 Zbyte& operator= ( const Zbyte& i ) { value=i.value; return *this; }
 Zbyte& operator= ( const Zuint& i );
 Zbyte& operator= ( const Zint& i );
 Zbyte& operator= ( const Zfloat& f );
 Zbyte& operator= ( const Zdouble& d );
 Zbyte& operator= ( const Zstring& s );
 Zbyte& operator+= ( const Zbyte& i ) { value+=i.value; return *this; }
 Zbyte& operator-= ( const Zbyte& i ) { value-=i.value; return *this; }
 Zbyte& operator*= ( const Zbyte& i ) { value*=i.value; return *this; }
 Zbyte& operator/= ( const Zbyte& i ) { value/=i.value; return *this; }
 Zbyte& operator+= ( const unsigned char i ) { value+=i; return *this; }
 Zbyte& operator-= ( const unsigned char i ) { value-=i; return *this; }
 Zbyte& operator*= ( const unsigned char i ) { value*=i; return *this; }
 Zbyte& operator/= ( const unsigned char i ) { value/=i; return *this; }
 Zbyte& operator+= ( const unsigned short i ) { value+=(unsigned char)i; return *this; }
 Zbyte& operator-= ( const unsigned short i ) { value-=(unsigned char)i; return *this; }
 Zbyte& operator*= ( const unsigned short i ) { value*=(unsigned char)i; return *this; }
 Zbyte& operator/= ( const unsigned short i ) { value/=(unsigned char)i; return *this; }
 Zbyte& operator+= ( const int i ) { value+=(unsigned char)i; return *this; }
 Zbyte& operator-= ( const int i ) { value-=(unsigned char)i; return *this; }
 Zbyte& operator*= ( const int i ) { value*=(unsigned char)i; return *this; }
 Zbyte& operator/= ( const int i ) { value/=(unsigned char)i; return *this; }
 Zbyte& operator+= ( const unsigned int i ) { value+=(unsigned char)i; return *this; }
 Zbyte& operator-= ( const unsigned int i ) { value-=(unsigned char)i; return *this; }
 Zbyte& operator*= ( const unsigned int i ) { value*=(unsigned char)i; return *this; }
 Zbyte& operator/= ( const unsigned int i ) { value/=(unsigned char)i; return *this; }
 Zbyte& operator+= ( const float i ) { value+=(unsigned char)i; return *this; }
 Zbyte& operator-= ( const float i ) { value-=(unsigned char)i; return *this; }
 Zbyte& operator*= ( const float i ) { value*=(unsigned char)i; return *this; }
 Zbyte& operator/= ( const float i ) { value/=(unsigned char)i; return *this; }
 Zbyte& operator+= ( const double i ) { value+=(unsigned char)i; return *this; }
 Zbyte& operator-= ( const double i ) { value-=(unsigned char)i; return *this; }
 Zbyte& operator*= ( const double i ) { value*=(unsigned char)i; return *this; }
 Zbyte& operator/= ( const double i ) { value/=(unsigned char)i; return *this; }
 Zbyte& operator++ (int) { value+=1; return *this; }
 Zbyte& operator-- (int) { value-=1; return *this; }
 operator unsigned char() { return value; }
 bool operator !() { return ( value == 0 ); }
// Not used intentionally to create warning:
// operator float() { return (float)value; }
// operator double() { return (double)value; }
// Causes ambiguity, because this is removed, the resulting issue (no better solution, see C2593)
// (mixed type comparisons require explicit casts) is described in the test:
// operator float() { return (float) value; }
// operator float() { return (double) value; }
};


unsigned char operator+ ( const Zbyte& a, const Zbyte& b );
unsigned char operator- ( const Zbyte& a, const Zbyte& b );
unsigned char operator* ( const Zbyte& a, const Zbyte& b );
unsigned char operator/ ( const Zbyte& a, const Zbyte& b );
// Casted unsigned int operations
unsigned char operator+ ( const Zbyte& a, unsigned char b );
unsigned char operator- ( const Zbyte& a, unsigned char b );
unsigned char operator* ( const Zbyte& a, unsigned char b );
unsigned char operator/ ( const Zbyte& a, unsigned char b );
unsigned char operator+ ( unsigned char b, const Zbyte& a );
unsigned char operator- ( unsigned char b, const Zbyte& a );
unsigned char operator* ( unsigned char b, const Zbyte& a );
unsigned char operator/ ( unsigned char b, const Zbyte& a );
// Casted int operations
unsigned char operator+ ( const Zbyte& a, int b );
unsigned char operator- ( const Zbyte& a, int b );
unsigned char operator* ( const Zbyte& a, int b );
unsigned char operator/ ( const Zbyte& a, int b );
unsigned char operator+ ( int b, const Zbyte& a );
unsigned char operator- ( int b, const Zbyte& a );
unsigned char operator* ( int b, const Zbyte& a );
unsigned char operator/ ( int b, const Zbyte& a );
// Float operations (leans toward float precision)
unsigned char operator+ ( const Zbyte& a, float b );
unsigned char operator- ( const Zbyte& a, float b );
unsigned char operator* ( const Zbyte& a, float b );
unsigned char operator/ ( const Zbyte& a, float b );
unsigned char operator+ ( float b, const Zbyte& a );
unsigned char operator- ( float b, const Zbyte& a );
unsigned char operator* ( float b, const Zbyte& a );
unsigned char operator/ ( float b, const Zbyte& a );
// Casted double operations (leans toward double precision)
unsigned char operator+ ( const Zbyte& a, double b );
unsigned char operator- ( const Zbyte& a, double b );
unsigned char operator* ( const Zbyte& a, double b );
unsigned char operator/ ( const Zbyte& a, double b );
unsigned char operator+ ( double b, const Zbyte& a );
unsigned char operator- ( double b, const Zbyte& a );
unsigned char operator* ( double b, const Zbyte& a );
unsigned char operator/ ( double b, const Zbyte& a );
// Boolean operations
bool operator>= ( const Zbyte& a, const Zbyte& b );
bool operator>= ( const Zbyte& a, int b );
bool operator>= ( const Zbyte& a, float b );
bool operator>= ( const Zbyte& a, double b );
bool operator>= ( int a, const Zbyte& b );
bool operator>= ( float a, const Zbyte& b );
bool operator>= ( double a, const Zbyte& b );
bool operator== ( const Zbyte& a, const Zbyte& b );
bool operator== ( const Zbyte& a, int b );
bool operator== ( const Zbyte& a, float b );
bool operator== ( const Zbyte& a, double b );
bool operator== ( int a, const Zbyte& b );
bool operator== ( float a, const Zbyte& b );
bool operator== ( double a, const Zbyte& b );
bool operator!= ( const Zbyte& a, const Zbyte& b );
bool operator!= ( const Zbyte& a, int b );
bool operator!= ( const Zbyte& a, float b );
bool operator!= ( const Zbyte& a, double b );
bool operator!= ( int a, const Zbyte& b );
bool operator!= ( float a, const Zbyte& b );
bool operator!= ( double a, const Zbyte& b );
bool operator<= ( const Zbyte& a, const Zbyte& b );
bool operator<= ( const Zbyte& a, int b );
bool operator<= ( const Zbyte& a, float b );
bool operator<= ( const Zbyte& a, double b );
bool operator<= ( int a, const Zbyte& b );
bool operator<= ( float a, const Zbyte& b );
bool operator<= ( double a, const Zbyte& b );
bool operator> ( const Zbyte& a, const Zbyte& b );
bool operator> ( const Zbyte& a, int b );
bool operator> ( const Zbyte& a, float b );
bool operator> ( const Zbyte& a, double b );
bool operator> ( int a, const Zbyte& b );
bool operator> ( float a, const Zbyte& b );
bool operator> ( double a, const Zbyte& b );
bool operator< ( const Zbyte& a, const Zbyte& b );
bool operator< ( const Zbyte& a, int b );
bool operator< ( const Zbyte& a, float b );
bool operator< ( const Zbyte& a, double b );
bool operator< ( int a, const Zbyte& b );
bool operator< ( float a, const Zbyte& b );
bool operator< ( double a, const Zbyte& b );


/// Zbyte ///////////////////////////////////////////////////////////////////////////////////////// end

/// Zushort ////////////////////////////////////////////////////////////////////////////////////////// start

class Zushort {
public:
 unsigned short value;
 Zushort() { value=0; }
 Zushort( unsigned short value ) { this->value=value; }
 operator unsigned short *() { return &value; }
 Zushort *operator()() { return this; }
 unsigned short operator()( unsigned short z ) { return value=(unsigned short)z; }
 unsigned short operator()( unsigned char b ) { return value=(unsigned short)b; }
 unsigned short operator()( unsigned int i ) { return value=(unsigned short)i; }
 unsigned short operator()( int i ) { return value=(unsigned short) i; }
 unsigned short operator()( float f ) { return value=(unsigned short) f; }
 unsigned short operator()( double d ) { return value=(unsigned short) d; }
 unsigned short operator()( Zuint &i );
 unsigned short operator()( Zint &i );
 unsigned short operator()( Zfloat &f );
 unsigned short operator()( Zdouble &d );
 Zushort& operator= ( const unsigned short z ) { value=z; return *this; }
 Zushort& operator= ( const unsigned char b ) { value=(unsigned short)b; return *this; }
 Zushort& operator= ( const int i ) { value=(unsigned short)i; return *this; }
 Zushort& operator= ( const float f ) { value=(unsigned short)f; return *this; }
 Zushort& operator= ( const double d ) { value=(unsigned short) d; return *this; }
 Zushort& operator= ( const Zushort& i ) { value=i.value; return *this; }
 Zushort& operator= ( const Zbyte& i ) { value=(unsigned short)i.value; return *this; }
 Zushort& operator= ( const Zuint& i );
 Zushort& operator= ( const Zint& i );
 Zushort& operator= ( const Zfloat& f );
 Zushort& operator= ( const Zdouble& d );
 Zushort& operator= ( const Zstring& s );
 Zushort& operator+= ( const unsigned char i ) { value+=(unsigned short)i; return *this; }
 Zushort& operator-= ( const unsigned char i ) { value-=(unsigned short)i; return *this; }
 Zushort& operator*= ( const unsigned char i ) { value*=(unsigned short)i; return *this; }
 Zushort& operator/= ( const unsigned char i ) { value/=(unsigned short)i; return *this; }
 Zushort& operator+= ( const unsigned short i ) { value+=(unsigned short)i; return *this; }
 Zushort& operator-= ( const unsigned short i ) { value-=(unsigned short)i; return *this; }
 Zushort& operator*= ( const unsigned short i ) { value*=(unsigned short)i; return *this; }
 Zushort& operator/= ( const unsigned short i ) { value/=(unsigned short)i; return *this; }
 Zushort& operator+= ( const int i ) { value+=(unsigned short)i; return *this; }
 Zushort& operator-= ( const int i ) { value-=(unsigned short)i; return *this; }
 Zushort& operator*= ( const int i ) { value*=(unsigned short)i; return *this; }
 Zushort& operator/= ( const int i ) { value/=(unsigned short)i; return *this; }
 Zushort& operator+= ( const unsigned int i ) { value+=(unsigned short)i; return *this; }
 Zushort& operator-= ( const unsigned int i ) { value-=(unsigned short)i; return *this; }
 Zushort& operator*= ( const unsigned int i ) { value*=(unsigned short)i; return *this; }
 Zushort& operator/= ( const unsigned int i ) { value/=(unsigned short)i; return *this; }
 Zushort& operator+= ( const float i ) { value+=(unsigned short)i; return *this; }
 Zushort& operator-= ( const float i ) { value-=(unsigned short)i; return *this; }
 Zushort& operator*= ( const float i ) { value*=(unsigned short)i; return *this; }
 Zushort& operator/= ( const float i ) { value/=(unsigned short)i; return *this; }
 Zushort& operator+= ( const double i ) { value+=(unsigned short)i; return *this; }
 Zushort& operator-= ( const double i ) { value-=(unsigned short)i; return *this; }
 Zushort& operator*= ( const double i ) { value*=(unsigned short)i; return *this; }
 Zushort& operator/= ( const double i ) { value/=(unsigned short)i; return *this; }
 Zushort& operator++ (int) { value+=1; return *this; }
 Zushort& operator-- (int) { value-=1; return *this; }
 operator unsigned short() { return value; }
 operator int() { return -(int)value; }
 bool operator !() { return ( value == 0 ); }
// Not used intentionally to create warning:
// operator float() { return (float)value; }
// operator double() { return (double)value; }
// Causes ambiguity, because this is removed, the resulting issue (no better solution, see C2593)
// (mixed type comparisons require explicit casts) is described in the test:
// operator float() { return (float) value; }
// operator float() { return (double) value; }
};


unsigned short operator+ ( const Zushort& a, const Zushort& b );
unsigned short operator- ( const Zushort& a, const Zushort& b );
unsigned short operator* ( const Zushort& a, const Zushort& b );
unsigned short operator/ ( const Zushort& a, const Zushort& b );
// Casted unsigned int operations
unsigned short operator+ ( const Zushort& a, unsigned char b );
unsigned short operator- ( const Zushort& a, unsigned char b );
unsigned short operator* ( const Zushort& a, unsigned char b );
unsigned short operator/ ( const Zushort& a, unsigned char b );
unsigned short operator+ ( unsigned char b, const Zushort& a );
unsigned short operator- ( unsigned char b, const Zushort& a );
unsigned short operator* ( unsigned char b, const Zushort& a );
unsigned short operator/ ( unsigned char b, const Zushort& a );
// Casted int operations
unsigned short operator+ ( const Zushort& a, int b );
unsigned short operator- ( const Zushort& a, int b );
unsigned short operator* ( const Zushort& a, int b );
unsigned short operator/ ( const Zushort& a, int b );
unsigned short operator+ ( int b, const Zushort& a );
unsigned short operator- ( int b, const Zushort& a );
unsigned short operator* ( int b, const Zushort& a );
unsigned short operator/ ( int b, const Zushort& a );
// Float operations (leans toward float precision)
unsigned short operator+ ( const Zushort& a, float b );
unsigned short operator- ( const Zushort& a, float b );
unsigned short operator* ( const Zushort& a, float b );
unsigned short operator/ ( const Zushort& a, float b );
unsigned short operator+ ( float b, const Zushort& a );
unsigned short operator- ( float b, const Zushort& a );
unsigned short operator* ( float b, const Zushort& a );
unsigned short operator/ ( float b, const Zushort& a );
// Casted double operations (leans toward double precision)
unsigned short operator+ ( const Zushort& a, double b );
unsigned short operator- ( const Zushort& a, double b );
unsigned short operator* ( const Zushort& a, double b );
unsigned short operator/ ( const Zushort& a, double b );
unsigned short operator+ ( double b, const Zushort& a );
unsigned short operator- ( double b, const Zushort& a );
unsigned short operator* ( double b, const Zushort& a );
unsigned short operator/ ( double b, const Zushort& a );

/// Zbyte ///////////////////////////////////////////////////////////////////////////////////////// end

/// Zint ////////////////////////////////////////////////////////////////////////////////////////// start

class Zint {
public:
 int value;
 Zint() { value=0; }
 Zint( int value ) { this->value=value; }
 int abs() { return absi(value); }
 operator int *() { return &value; }
 Zint *operator()() { return this; }
 int operator()( int i ) { return value=i; }
 int operator()( float f ) { return value=(int)f; }
 int operator()( double d ) { return value=(int)d; }
 int operator()( Zbyte &i );
 int operator()( Zuint &i );
 int operator()( Zint &i ) { return value=i.value; }
 int operator()( Zfloat &f );
 int operator()( Zdouble &d );
 Zint& operator= ( const int i ) { value=i; return *this; }
 Zint& operator= ( const float f ) { value=(int)f; return *this; }
 Zint& operator= ( const double d ) { value=(int) d; return *this; }
 Zint& operator= ( const Zint& i ) { value=i.value; return *this; }
 Zint& operator= ( const Zbyte& b );
 Zint& operator= ( const Zuint& i );
 Zint& operator= ( const Zfloat& f );
 Zint& operator= ( const Zdouble& d );
 Zint& operator= ( const Zstring& s );
 Zint& operator+= ( const Zint& i ) { value+=i.value; return *this; }
 Zint& operator-= ( const Zint& i ) { value-=i.value; return *this; }
 Zint& operator*= ( const Zint& i ) { value*=i.value; return *this; }
 Zint& operator/= ( const Zint& i ) { value/=i.value; return *this; }
 Zint& operator+= ( const Zfloat& f );
 Zint& operator-= ( const Zfloat& f );
 Zint& operator*= ( const Zfloat& f );
 Zint& operator/= ( const Zfloat& f );
 Zint& operator+= ( const unsigned char i ) { value+=(int)i; return *this; }
 Zint& operator-= ( const unsigned char i ) { value-=(int)i; return *this; }
 Zint& operator*= ( const unsigned char i ) { value*=(int)i; return *this; }
 Zint& operator/= ( const unsigned char i ) { value/=(int)i; return *this; }
 Zint& operator+= ( const unsigned short i ) { value+=(int)i; return *this; }
 Zint& operator-= ( const unsigned short i ) { value-=(int)i; return *this; }
 Zint& operator*= ( const unsigned short i ) { value*=(int)i; return *this; }
 Zint& operator/= ( const unsigned short i ) { value/=(int)i; return *this; }
 Zint& operator+= ( const int i ) { value+=i; return *this; }
 Zint& operator-= ( const int i ) { value-=i; return *this; }
 Zint& operator*= ( const int i ) { value*=i; return *this; }
 Zint& operator/= ( const int i ) { value/=i; return *this; }
 Zint& operator+= ( const unsigned int i ) { value+=(int)i; return *this; }
 Zint& operator-= ( const unsigned int i ) { value-=(int)i; return *this; }
 Zint& operator*= ( const unsigned int i ) { value*=(int)i; return *this; }
 Zint& operator/= ( const unsigned int i ) { value/=(int)i; return *this; }
 Zint& operator+= ( const float i ) { value+=(int)i; return *this; }
 Zint& operator-= ( const float i ) { value-=(int)i; return *this; }
 Zint& operator*= ( const float i ) { value*=(int)i; return *this; }
 Zint& operator/= ( const float i ) { value/=(int)i; return *this; }
 Zint& operator+= ( const double i ) { value+=(int)i; return *this; }
 Zint& operator-= ( const double i ) { value-=(int)i; return *this; }
 Zint& operator*= ( const double i ) { value*=(int)i; return *this; }
 Zint& operator/= ( const double i ) { value/=(int)i; return *this; }
 Zint& operator++ (int) { value+=1; return *this; }
 Zint& operator-- (int) { value-=1; return *this; }
 const int operator-() { return -value; }
 operator unsigned int() { return (unsigned int) value; }
 operator int() { return value; }
 operator float() { return (float) value; }
 operator double() { return (double) value; }
 bool operator !() { return ( value == 0 ); }
// Not used intentionally to create warning:
// operator float() { return (float)value; }
// operator double() { return (double)value; }
// Causes ambiguity, because this is removed, the resulting issue (no better solution, see C2593)
// (mixed type comparisons require explicit casts) is described in the test:
// operator float() { return (float) value; }
// operator float() { return (double) value; }
};


int operator+ ( const Zint& a, const Zint& b );
int operator- ( const Zint& a, const Zint& b );
int operator* ( const Zint& a, const Zint& b );
int operator/ ( const Zint& a, const Zint& b );
// Casted int operations
int operator+ ( const Zint& a, int b );
int operator- ( const Zint& a, int b );
int operator* ( const Zint& a, int b );
int operator/ ( const Zint& a, int b );
int operator% ( const Zint& a, int b );
int operator+ ( int b, const Zint& a );
int operator- ( int b, const Zint& a );
int operator* ( int b, const Zint& a );
int operator/ ( int b, const Zint& a );
int operator% ( int b, const Zint& a );
// Float operations (leans toward float precision)
int operator+ ( const Zint& a, float b );
int operator- ( const Zint& a, float b );
int operator* ( const Zint& a, float b );
int operator/ ( const Zint& a, float b );
int operator+ ( float b, const Zint& a );
int operator- ( float b, const Zint& a );
int operator* ( float b, const Zint& a );
int operator/ ( float b, const Zint& a );
// Casted double operations (leans toward double precision)
int operator+ ( const Zint& a, double b );
int operator- ( const Zint& a, double b );
int operator* ( const Zint& a, double b );
int operator/ ( const Zint& a, double b );
int operator+ ( double b, const Zint& a );
int operator- ( double b, const Zint& a );
int operator* ( double b, const Zint& a );
int operator/ ( double b, const Zint& a );
// Modulo
int operator% ( const Zint &a, const Zint &b );
// Boolean operations
bool operator>= ( const Zint& a, const Zint& b );
bool operator>= ( const Zint& a, unsigned int b );
bool operator>= ( const Zint& a, int b );
bool operator>= ( const Zint& a, float b );
bool operator>= ( const Zint& a, double b );
bool operator>= ( unsigned int a, const Zint& b );
bool operator>= ( int a, const Zint& b );
bool operator>= ( float a, const Zint& b );
bool operator>= ( double a, const Zint& b );
bool operator== ( const Zint& a, const Zbyte& b );
bool operator== ( const Zint& a, const Zushort& b );
bool operator== ( const Zint& a, const Zuint& b );
bool operator== ( const Zint& a, const Zdouble& b );
bool operator== ( const Zbyte& a, const Zint& b );
bool operator== ( const Zushort& a, const Zint& b );
bool operator== ( const Zuint& a, const Zint& b );
bool operator== ( const Zdouble& a, const Zint& b );
bool operator== ( const Zint& a, const Zint& b );
bool operator== ( const Zint& a, unsigned int b );
bool operator== ( const Zint& a, int b );
bool operator== ( const Zint& a, float b );
bool operator== ( const Zint& a, double b );
bool operator== ( unsigned int a, const Zint& b );
bool operator== ( int a, const Zint& b );
bool operator== ( float a, const Zint& b );
bool operator== ( double a, const Zint& b );
bool operator!= ( const Zint& a, const Zint& b );
bool operator!= ( const Zint& a, unsigned int b );
bool operator!= ( const Zint& a, int b );
bool operator!= ( const Zint& a, float b );
bool operator!= ( const Zint& a, double b );
bool operator!= ( unsigned int a, const Zint& b );
bool operator!= ( int a, const Zint& b );
bool operator!= ( float a, const Zint& b );
bool operator!= ( double a, const Zint& b );
bool operator<= ( const Zint& a, const Zint& b );
bool operator<= ( const Zint& a, unsigned int b );
bool operator<= ( const Zint& a, int b );
bool operator<= ( const Zint& a, float b );
bool operator<= ( const Zint& a, double b );
bool operator<= ( unsigned int a, const Zint& b );
bool operator<= ( int a, const Zint& b );
bool operator<= ( float a, const Zint& b );
bool operator<= ( double a, const Zint& b );
bool operator> ( const Zint& a, const Zint& b );
bool operator> ( const Zint& a, unsigned int b );
bool operator> ( const Zint& a, int b );
bool operator> ( const Zint& a, float b );
bool operator> ( const Zint& a, double b );
bool operator> ( unsigned int a, const Zint& b );
bool operator> ( int a, const Zint& b );
bool operator> ( float a, const Zint& b );
bool operator> ( double a, const Zint& b );
bool operator< ( const Zint& a, const Zint& b );
bool operator< ( const Zint& a, unsigned int b );
bool operator< ( const Zint& a, int b );
bool operator< ( const Zint& a, float b );
bool operator< ( const Zint& a, double b );
bool operator< ( unsigned int a, const Zint& b );
bool operator< ( int a, const Zint& b );
bool operator< ( float a, const Zint& b );
bool operator< ( double a, const Zint& b );

/// Zint ////////////////////////////////////////////////////////////////////////////////////////// end

/// Zuint ////////////////////////////////////////////////////////////////////////////////////////// start

class Zuint {
public:
 unsigned int value;
 Zuint() { value=0; }
 Zuint( unsigned int value ) { this->value=value; }
 operator unsigned int *() { return &value; }
 Zuint *operator()() { return this; }
 unsigned int operator()( unsigned int i ) { return value=i; }
 unsigned int operator()( int i ) { return value=(unsigned int) i; }
 unsigned int operator()( float f ) { return value=(unsigned int)f; }
 unsigned int operator()( double d ) { return value=(unsigned int)d; }
 unsigned int operator()( Zbyte &i );
 unsigned int operator()( Zuint &i );
 unsigned int operator()( Zint &i );
 unsigned int operator()( Zfloat &f );
 unsigned int operator()( Zdouble &d );
 Zuint& operator= ( const unsigned int i ) { value=i; return *this; }
 Zuint& operator= ( const int i ) { value=i; return *this; }
 Zuint& operator= ( const float f ) { value=(int)f; return *this; }
 Zuint& operator= ( const double d ) { value=(int) d; return *this; }
 Zuint& operator= ( const Zuint& i ) { value=i.value; return *this; }
 Zuint& operator= ( const Zbyte& b );
 Zuint& operator= ( const Zint& i );
 Zuint& operator= ( const Zfloat& f );
 Zuint& operator= ( const Zdouble& d );
 Zuint& operator= ( const Zstring& s );
 Zuint& operator+= ( const Zuint& i ) { value+=i.value; return *this; }
 Zuint& operator-= ( const Zuint& i ) { value-=i.value; return *this; }
 Zuint& operator*= ( const Zuint& i ) { value*=i.value; return *this; }
 Zuint& operator/= ( const Zuint& i ) { value/=i.value; return *this; }
 Zuint& operator+= ( const Zint& i ) { value+=(unsigned int) i.value; return *this; }
 Zuint& operator-= ( const Zint& i ) { value-=(unsigned int) i.value; return *this; }
 Zuint& operator*= ( const Zint& i ) { value*=(unsigned int) i.value; return *this; }
 Zuint& operator/= ( const Zint& i ) { value/=(unsigned int) i.value; return *this; }
 Zuint& operator+= ( const unsigned char i ) { value+=(unsigned int) i; return *this; }
 Zuint& operator-= ( const unsigned char i ) { value-=(unsigned int) i; return *this; }
 Zuint& operator*= ( const unsigned char i ) { value*=(unsigned int) i; return *this; }
 Zuint& operator/= ( const unsigned char i ) { value/=(unsigned int) i; return *this; }
 Zuint& operator+= ( const unsigned short i ) { value+=(unsigned int) i; return *this; }
 Zuint& operator-= ( const unsigned short i ) { value-=(unsigned int) i; return *this; }
 Zuint& operator*= ( const unsigned short i ) { value*=(unsigned int) i; return *this; }
 Zuint& operator/= ( const unsigned short i ) { value/=(unsigned int) i; return *this; }
 Zuint& operator+= ( const int i ) { value+=(unsigned int) i; return *this; }
 Zuint& operator-= ( const int i ) { value-=(unsigned int) i; return *this; }
 Zuint& operator*= ( const int i ) { value*=(unsigned int) i; return *this; }
 Zuint& operator/= ( const int i ) { value/=(unsigned int) i; return *this; }
 Zuint& operator+= ( const unsigned int i ) { value+=i; return *this; }
 Zuint& operator-= ( const unsigned int i ) { value-=i; return *this; }
 Zuint& operator*= ( const unsigned int i ) { value*=i; return *this; }
 Zuint& operator/= ( const unsigned int i ) { value/=i; return *this; }
 Zuint& operator+= ( const float i ) { value+=(unsigned int) i; return *this; }
 Zuint& operator-= ( const float i ) { value-=(unsigned int) i; return *this; }
 Zuint& operator*= ( const float i ) { value*=(unsigned int) i; return *this; }
 Zuint& operator/= ( const float i ) { value/=(unsigned int) i; return *this; }
 Zuint& operator+= ( const double i ) { value+=(unsigned int) i; return *this; }
 Zuint& operator-= ( const double i ) { value-=(unsigned int) i; return *this; }
 Zuint& operator*= ( const double i ) { value*=(unsigned int) i; return *this; }
 Zuint& operator/= ( const double i ) { value/=(unsigned int) i; return *this; }
 Zuint& operator++ (int) { value+=1; return *this; }
 Zuint& operator-- (int) { value-=1; return *this; }
 operator unsigned int() { return value; }
 operator int() { return (int) value; }
 bool operator !() { return ( value == 0 ); }
// Not used intentionally to create warning:
// operator float() { return (float)value; }
// operator double() { return (double)value; }
// Causes ambiguity, because this is removed, the resulting issue (no better solution, see C2593)
// (mixed type comparisons require explicit casts) is described in the test:
// operator float() { return (float) value; }
// operator float() { return (double) value; }
};

bool operator< ( unsigned int a, const Zuint& b );

unsigned int operator+ ( const Zuint& a, const Zuint& b );
unsigned int operator- ( const Zuint& a, const Zuint& b );
unsigned int operator* ( const Zuint& a, const Zuint& b );
unsigned int operator/ ( const Zuint& a, const Zuint& b );
// Casted unsigned int operations
unsigned int operator+ ( const Zuint& a, int b );
unsigned int operator- ( const Zuint& a, int b );
unsigned int operator* ( const Zuint& a, int b );
unsigned int operator/ ( const Zuint& a, int b );
unsigned int operator+ ( int b, const Zuint& a );
unsigned int operator- ( int b, const Zuint& a );
unsigned int operator* ( int b, const Zuint& a );
unsigned int operator/ ( int b, const Zuint& a );
// Casted int operations
unsigned int operator+ ( const Zuint& a, int b );
unsigned int operator- ( const Zuint& a, int b );
unsigned int operator* ( const Zuint& a, int b );
unsigned int operator/ ( const Zuint& a, int b );
unsigned int operator+ ( int b, const Zuint& a );
unsigned int operator- ( int b, const Zuint& a );
unsigned int operator* ( int b, const Zuint& a );
unsigned int operator/ ( int b, const Zuint& a );
// Float operations (leans toward float precision)
unsigned int operator+ ( const Zuint& a, float b );
unsigned int operator- ( const Zuint& a, float b );
unsigned int operator* ( const Zuint& a, float b );
unsigned int operator/ ( const Zuint& a, float b );
unsigned int operator+ ( float b, const Zuint& a );
unsigned int operator- ( float b, const Zuint& a );
unsigned int operator* ( float b, const Zuint& a );
unsigned int operator/ ( float b, const Zuint& a );
// Casted double operations (leans toward double precision)
unsigned int operator+ ( const Zuint& a, double b );
unsigned int operator- ( const Zuint& a, double b );
unsigned int operator* ( const Zuint& a, double b );
unsigned int operator/ ( const Zuint& a, double b );
unsigned int operator+ ( double b, const Zuint& a );
unsigned int operator- ( double b, const Zuint& a );
unsigned int operator* ( double b, const Zuint& a );
unsigned int operator/ ( double b, const Zuint& a );

/// Zuint ////////////////////////////////////////////////////////////////////////////////////////// end

/// Zdouble ////////////////////////////////////////////////////////////////////////////////////////// start

class Zdouble {
public:
 double value;
 Zdouble() { value=0.0; }
 Zdouble( double value ) { this->value=value; }
 double abs() { return absd(value); }
 operator double *() { return &value; }
 Zdouble *operator()() { return this; }
 double operator()( int i ) { return value=(double)i; }
 double operator()( float f ) { return value=(double)f; }
 double operator()( double d ) { return value=d; }
 double operator()( Zbyte &b );
 double operator()( Zuint &i );
 double operator()( Zint &i );
 double operator()( Zfloat &f );
 double operator()( Zdouble &d );
 Zdouble& operator= ( const int i ) { value=(double)i; return *this; }
 Zdouble& operator= ( const float f ) { value=(double)f; return *this; }
 Zdouble& operator= ( const double d ) { value=d; return *this; }
 Zdouble& operator= ( const Zbyte& b );
 Zdouble& operator= ( const Zuint& b );
 Zdouble& operator= ( const Zint& i );
 Zdouble& operator= ( const Zfloat& f );
 Zdouble& operator= ( const Zdouble& d ) { value=d.value; return *this; }
 Zdouble& operator= ( const Zstring& s );
 Zdouble& operator+= ( const Zbyte& b ) { value+=(double)b.value; return *this; }
 Zdouble& operator-= ( const Zbyte& b ) { value-=(double)b.value; return *this; }
 Zdouble& operator*= ( const Zbyte& b ) { value*=(double)b.value; return *this; }
 Zdouble& operator/= ( const Zbyte& b ) { value/=(double)b.value; return *this; }
 Zdouble& operator+= ( const Zint& i ) { value+=(double)i.value; return *this; }
 Zdouble& operator-= ( const Zint& i ) { value-=(double)i.value; return *this; }
 Zdouble& operator*= ( const Zint& i ) { value*=(double)i.value; return *this; }
 Zdouble& operator/= ( const Zint& i ) { value/=(double)i.value; return *this; }
 Zdouble& operator+= ( const Zuint& i ) { value+=(double)i.value; return *this; }
 Zdouble& operator-= ( const Zuint& i ) { value-=(double)i.value; return *this; }
 Zdouble& operator*= ( const Zuint& i ) { value*=(double)i.value; return *this; }
 Zdouble& operator/= ( const Zuint& i ) { value/=(double)i.value; return *this; }
 Zdouble& operator+= ( const Zfloat& f ) { value+=(double)f.value; return *this; }
 Zdouble& operator-= ( const Zfloat& f ) { value-=(double)f.value; return *this; }
 Zdouble& operator*= ( const Zfloat& f ) { value*=(double)f.value; return *this; }
 Zdouble& operator/= ( const Zfloat& f ) { value/=(double)f.value; return *this; }
 Zdouble& operator+= ( const Zdouble& d ) { value+=d.value; return *this; }
 Zdouble& operator-= ( const Zdouble& d ) { value-=d.value; return *this; }
 Zdouble& operator*= ( const Zdouble& d ) { value*=d.value; return *this; }
 Zdouble& operator/= ( const Zdouble& d ) { value/=d.value; return *this; }
 Zdouble& operator+= ( const unsigned char d ) { value+=(double) d; return *this; }
 Zdouble& operator-= ( const unsigned char d ) { value-=(double) d; return *this; }
 Zdouble& operator*= ( const unsigned char d ) { value*=(double) d; return *this; }
 Zdouble& operator/= ( const unsigned char d ) { value/=(double) d; return *this; }
 Zdouble& operator+= ( const unsigned short d ) { value+=(double) d; return *this; }
 Zdouble& operator-= ( const unsigned short d ) { value-=(double) d; return *this; }
 Zdouble& operator*= ( const unsigned short d ) { value*=(double) d; return *this; }
 Zdouble& operator/= ( const unsigned short d ) { value/=(double) d; return *this; }
 Zdouble& operator+= ( const int d ) { value+=(double) d; return *this; }
 Zdouble& operator-= ( const int d ) { value-=(double) d; return *this; }
 Zdouble& operator*= ( const int d ) { value*=(double) d; return *this; }
 Zdouble& operator/= ( const int d ) { value/=(double) d; return *this; }
 Zdouble& operator+= ( const unsigned int d ) { value+=(double) d; return *this; }
 Zdouble& operator-= ( const unsigned int d ) { value-=(double) d; return *this; }
 Zdouble& operator*= ( const unsigned int d ) { value*=(double) d; return *this; }
 Zdouble& operator/= ( const unsigned int d ) { value/=(double) d; return *this; }
 Zdouble& operator+= ( const float d ) { value+=(double) d; return *this; }
 Zdouble& operator-= ( const float d ) { value-=(double) d; return *this; }
 Zdouble& operator*= ( const float d ) { value*=(double) d; return *this; }
 Zdouble& operator/= ( const float d ) { value/=(double) d; return *this; }
 Zdouble& operator+= ( const double d ) { value+=d; return *this; }
 Zdouble& operator-= ( const double d ) { value-=d; return *this; }
 Zdouble& operator*= ( const double d ) { value*=d; return *this; }
 Zdouble& operator/= ( const double d ) { value/=d; return *this; }
 Zdouble& operator++ (int) { value+=1.0; return *this; }
 Zdouble& operator-- (int) { value-=1.0; return *this; }
 const double operator-() { return -value; }
 operator double() { return value; }
 bool operator !() { return ( value == 0.0 ); }
// Not used intentionally to create warning:
// operator float() { return (float) value; }
// operator int() { return (int) value; }
// Causes ambiguity, because this is removed, the resulting issue (no better solution, see C2593)
// (mixed type comparisons require explicit casts) is described in the test:
// operator int() { return (int) value; }
// operator float() { return (float) value; }
};

// Mixed type operations
double operator+ ( const Zdouble& a, const Zfloat& b );
double operator+ ( const Zfloat& a, const Zdouble& b );
double operator+ ( const Zdouble& a, const Zint& b );
double operator+ ( const Zint& a, const Zdouble& b );
double operator* ( const Zdouble& a, const Zfloat& b );
double operator* ( const Zfloat& a, const Zdouble& b );
double operator* ( const Zdouble& a, const Zint& b );
double operator* ( const Zint& a, const Zdouble& b );
// Zdouble and itself
double operator+ ( const Zdouble& a, const Zdouble& b );
double operator- ( const Zdouble& a, const Zdouble& b );
double operator* ( const Zdouble& a, const Zdouble& b );
double operator/ ( const Zdouble& a, const Zdouble& b );
// Casted int operations
double operator+ ( const Zdouble& a, int b );
double operator- ( const Zdouble& a, int b );
double operator* ( const Zdouble& a, int b );
double operator/ ( const Zdouble& a, int b );
double operator+ ( int b, const Zdouble& a );
double operator- ( int b, const Zdouble& a );
double operator* ( int b, const Zdouble& a );
double operator/ ( int b, const Zdouble& a );
// Float operations
double operator+ ( const Zdouble& a, float b );
double operator- ( const Zdouble& a, float b );
double operator* ( const Zdouble& a, float b );
double operator/ ( const Zdouble& a, float b );
double operator+ ( float b, const Zdouble& a );
double operator- ( float b, const Zdouble& a );
double operator* ( float b, const Zdouble& a );
double operator/ ( float b, const Zdouble& a );
// Casted double operations (leans toward double precision)
double operator+ ( const Zdouble& a, double b );
double operator- ( const Zdouble& a, double b );
double operator* ( const Zdouble& a, double b );
double operator/ ( const Zdouble& a, double b );
double operator+ ( double b, const Zdouble& a );
double operator- ( double b, const Zdouble& a );
double operator* ( double b, const Zdouble& a );
double operator/ ( double b, const Zdouble& a );
// Boolean operations
bool operator>= ( const Zdouble& a, const Zdouble& b );
bool operator>= ( const Zdouble& a, int b );
bool operator>= ( const Zdouble& a, float b );
bool operator>= ( const Zdouble& a, double b );
bool operator>= ( int a, const Zdouble& b );
bool operator>= ( float a, const Zdouble& b );
bool operator>= ( double a, const Zdouble& b );
bool operator== ( const Zdouble& a, const Zdouble& b );
bool operator== ( const Zdouble& a, int b );
bool operator== ( const Zdouble& a, float b );
bool operator== ( const Zdouble& a, double b );
bool operator== ( int a, const Zdouble& b );
bool operator== ( float a, const Zdouble& b );
bool operator== ( double a, const Zdouble& b );
bool operator!= ( const Zdouble& a, const Zdouble& b );
bool operator!= ( const Zdouble& a, int b );
bool operator!= ( const Zdouble& a, float b );
bool operator!= ( const Zdouble& a, double b );
bool operator!= ( int a, const Zdouble& b );
bool operator!= ( float a, const Zdouble& b );
bool operator!= ( double a, const Zdouble& b );
bool operator<= ( const Zdouble& a, const Zdouble& b );
bool operator<= ( const Zdouble& a, int b );
bool operator<= ( const Zdouble& a, float b );
bool operator<= ( const Zdouble& a, double b );
bool operator<= ( int a, const Zdouble& b );
bool operator<= ( float a, const Zdouble& b );
bool operator<= ( double a, const Zdouble& b );
bool operator> ( const Zdouble& a, const Zdouble& b );
bool operator> ( const Zdouble& a, int b );
bool operator> ( const Zdouble& a, float b );
bool operator> ( const Zdouble& a, double b );
bool operator> ( int a, const Zdouble& b );
bool operator> ( float a, const Zdouble& b );
bool operator> ( double a, const Zdouble& b );
bool operator< ( const Zdouble& a, const Zdouble& b );
bool operator< ( const Zdouble& a, int b );
bool operator< ( const Zdouble& a, float b );
bool operator< ( const Zdouble& a, double b );
bool operator< ( int a, const Zdouble& b );
bool operator< ( float a, const Zdouble& b );
bool operator< ( double a, const Zdouble& b );


/// Zfloat ////////////////////////////////////////////////////////////////////////////////////////// end

/// Zstring ///////////////////////////////////////////////////////////////////////////////////////// start

class Zstring {
public:
 string value;
 unsigned int length;
 const char *p;
 Zstring() {
  value=string("");
  length=0;
  p=null;
 }
 Zstring( const char *value ) {
  this->value=string(value);
  rewind();
 }
 Zstring( const string &value ) {
  this->value=value;
  rewind();
 }
 const char *first( const Zstring& in ) {
  const char *p=string_argument(in.value.c_str(),&value);
  rewind();
  return p;
 }
 const char *first( const string& in ) {
  const char *p=string_argument(in.c_str(),&value);
  rewind();
  return p;
 }
 const char *first( const char *in ) {
  const char *p=string_argument(in,&value);
  rewind();
  return p;
 }
 const char *word( int number, char *out=buf ) {
  rewind();
  for ( int i=0; i<number; i++ ) next(out);
  return out;
 }
 char *next( char *out=buf ) {
  p=one_argument(p,out);
  return out;
 }
 void rewind() {
  p=value.c_str();
  length=this->value.length();
 }
 bool is_number() { return is_integer(value.c_str()) || is_decimal(value.c_str()); }
 bool Empty() {
  Zstring temp=*this;
  temp/=" ";
  return ( length == 0 || temp.length == 0 );
 }
 string Pop() {
  string out=string("");
  value=first_word(value,&out);
  rewind();
  return out;
 }
 string Pop( int number ) {
  string out=string("");
  string one=string("");
  for ( int i=0; i<number; i++ ) {
   value=first_word(value,&one);
   out+=string(" ")+one;
  }
  rewind();
  return out;
 }
 string PopLine() {
  string out=string("");
  value=string(gather_to(value.c_str(),&out,'\n'));
  rewind();
  return out;
 }
 string PopUntil( char sep ) {
  string out=string("");
  value=string(gather_to(value.c_str(),&out,sep));
  rewind();
  return out;
 }
 string PopUntil( char sep, char orsep ) {
  string out=string("");
  value=string(gather_to(value.c_str(),&out,sep,orsep));
  rewind();
  return out;
 }
 string PopUntil( const char *key ) {
  string out=string("");
  string one=string("");
  while( value.length() > 0 && !str_cmp(one.c_str(),key) ) {
   value=string(string_argument_case(value.c_str(),&one));
   out+=string(" ")+one;
  }
  rewind();
  return out;
 }
 void Clear() { value=string(""); length=0; }
 string *operator &() { return &value; } // some debate here
 const char *c_str() { return value.c_str(); }
 operator const char *() { return value.c_str(); }
 operator char *() { return (char *) value.c_str(); }
 operator string() { return value; }
 operator string*() { return &value; }
 void operator= (const char *s ) {
  value=string(s);
  rewind();
 }
 void Set(string s) {
  value=s;
  rewind();
 }
 void operator= (string s) {
  value=s;
  rewind();
 }
 Zstring& operator/= ( string b ) {
  replaceAll(value,b,string(""));
  rewind();
  return *this;
 }
 Zstring& operator/= ( Zstring& b ) {
  replaceAll(value,b,string(""));
  rewind();
  return *this;
 }
 operator int() {
  if (is_decimal(value.c_str())) return (int)(atof(value.c_str()));  // rounding?
  else return (int)atoi(value.c_str());
 }
 operator float() { return (float) atof(value.c_str()); }
 operator double() { Zstring result(value); result/="$"; result/=","; return atof(result.value.c_str()); }
 operator unsigned int() { return length; }
 Zstring& operator --(int) { if ( length > 0 ) { value=value.substr(0,value.size()-1); rewind(); } return *this; }
 Zstring& operator --() { if ( length > 0 ) { value=value.substr(1,value.size()); rewind(); } return *this; }
 Zstring& operator +=( char c ) { char buf[2]; buf[0]=c; buf[1]='\0'; value=value+string(buf); rewind(); return *this; }
 Zstring& operator +=( const char *b ) { value=value+string(b); rewind(); return *this; }
 Zstring& operator +=( const string& b ) { value+=b; rewind(); return *this; }
 Zstring& operator +=( const Zstring& b ) { value+=b.value; rewind(); return *this; }
 Zstring& operator -=( const Zstring& b ) { replaceOnce(value,b.value,string("")); rewind(); return *this; }
 Zstring& operator -=( const char *b ) { replaceOnce(value,string(b),string("")); rewind(); return *this; }
 Zstring& operator -=( const string& b ) { replaceOnce(value,b,string("")); rewind(); return *this; }
 bool operator !() { return ( Empty() ); }
 bool operator () ( const char *partial ) { return !str_prefix(value.c_str(),partial); }
 bool operator () ( const string& partial ) { return !str_prefix(value.c_str(),partial.c_str()); }
 bool operator () ( const char *partial, bool anywhere ) { return !str_infix(value.c_str(),partial); }
 bool operator () ( const string& partial, bool anywhere ) { return !str_infix(value.c_str(),partial.c_str()); }
};

bool operator==( const Zstring& a, const Zstring& b );
bool operator==( const Zstring& a, const char *b );
bool operator==( const char *b , const Zstring& a );
bool operator==( string a, const Zstring &b );
bool operator==( const Zstring &a, string b  );
string operator+ ( const Zstring& a, const Zstring& b );
string operator+ ( const Zstring& a, const string& b );
string operator+ ( const string& b, const Zstring& a );
string operator+ ( const Zstring& a, char c );
string operator- ( const Zstring& a, const Zstring& b );
string operator- ( const Zstring& a, const string& b );
string operator- ( const string& b, const Zstring& a );
string operator- ( const Zstring& a, const char *b );
string operator- ( const char *b, const Zstring& a );
string operator/ ( const Zstring& a, const Zstring& b );
string operator/ ( const Zstring& a, const string& b );
string operator/ ( const string& b, const Zstring& a );
string operator/ ( const Zstring& a, const char *b );
string operator/ ( const char *b, const Zstring& a );
string operator* ( const Zstring& a, unsigned int i );

/// Zstring ///////////////////////////////////////////////////////////////////////////////////////// end

/// Zpointer //////////////////////////////////////////////////////////////////////////////////////// start

template<class T>
class Zpointer {
public:
 T *pointer;
 Zpointer() { pointer=null; }
 Zpointer( T *value ) { this->pointer=value; }
 ~Zpointer() {
  return;
 }
 Zpointer( Zpointer<T>& p ) { this->pointer=p.value; }
 void Delete() {
  if ( pointer ) {
   delete pointer;
   pointer=null;
  }
 }
 operator T*() { return pointer; }
 T operator* ( Zpointer<T>& t ) { return *pointer; }
// T **operator& ( Zpointer<T>& t ) { return &pointer; }
 Zpointer<T>& operator()( T *value ) { pointer=value; return *this; }
 Zpointer<T>& operator()( Zpointer<T>& t ) { pointer=t.pointer; return *this; }
 Zpointer<T>& operator= ( T *value ) { pointer=value; return *this; }
 Zpointer<T>& operator= ( Zpointer<T>& t ) { pointer=t.pointer; return *this; }
 T *operator->() {
#if defined(DEBUG) || defined(DEBUG_OUTPUT)
  if ( !pointer ) {
   OUTPUT("Zpointer:->() referenced when null.\n");
  }
#endif
  return pointer;
 }
};

typedef Zpointer<void>   Pvoid;
typedef Zpointer<int>    Pint;
typedef Zpointer<float>  Pfloat;
typedef Zpointer<double> Pdouble;

// Notes from the underground
/*
class Zvoid : public Zpointer<void> {
public:
  Zvoid() { .. }
  Zvoid(void* value) : Zpointer<void>(value) { .. }
  Zvoid(Zvoid& p) : Zpointer<void>(p) { .. } 
  using Zpointer<void>::operator =;
};
 */

// On debugging pointers:  Zpointer could be attached to a historical pointer system
// that keeps track of all assignments, accesses, etc.

// This would reproduce the work of "$12000" programs

/// Zpointer //////////////////////////////////////////////////////////////////////////////////////// end

/// Zdisposable ///////////////////////////////////////////////////////////////////////////////////// start

template<class T>
class Zdisposable {
public:
 T *pointer;
 Zdisposable() {
  pointer=null;
 }
 void Instantiate() {
  if ( !pointer ) pointer=new T;
 }
 void Deinstantiate() {
  if ( pointer ) {
   delete pointer;
   pointer=null;
  }
 }
 void Recycle() {
  if ( pointer ) delete pointer;
  pointer=new T;
 }
 void Recycle( T *replacement ) {
  if ( pointer ) delete pointer;
  pointer=replacement;
 }
 operator T*() { return pointer; }
 T operator* ( Zdisposable<T>& t ) { return *pointer; }
 T operator& ( Zdisposable<T>& t ) { return &pointer; }
// T **operator& ( Zpointer<T>& t ) { return &pointer; }
 T *operator->() {
  if ( !pointer ) {
   Instantiate();
  }
  return pointer;
 }
 ~Zdisposable() {
  if ( pointer ) delete pointer;
 }
};

/// Zdisposable ///////////////////////////////////////////////////////////////////////////////////// end

void ZeroTypesTest();
