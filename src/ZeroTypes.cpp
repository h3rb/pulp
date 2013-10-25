#include "ZeroTypes.h"

/// Forward declared type assocations

/// Zfloat operator= overloads for forward declared types

Zfloat& Zfloat::operator= ( const Zbyte& b   ) { value=(float)b.value; return *this; }
Zfloat& Zfloat::operator= ( const Zuint& i   ) { value=(float)i.value; return *this; }
Zfloat& Zfloat::operator= ( const Zint& i    ) { value=(float)i.value; return *this; }
Zfloat& Zfloat::operator= ( const Zdouble& d ) { value=(float)d.value; return *this; }
Zfloat& Zfloat::operator= ( const Zstring& s ) { value=(float)atof(s.value.c_str()); return *this; }
float Zfloat::operator()( Zbyte &b )   { return value=(float)b.value; }
float Zfloat::operator()( Zuint &i )   { return value=(float)i.value; }
float Zfloat::operator()( Zint &i )    { return value=(float)i.value; }
float Zfloat::operator()( Zdouble &d ) { return value=(float)d.value; }
Zfloat& Zfloat::operator+= ( const Zint& i ) { value+=(float)i.value; return *this; }
Zfloat& Zfloat::operator-= ( const Zint& i ) { value-=(float)i.value; return *this; }
Zfloat& Zfloat::operator*= ( const Zint& i ) { value*=(float)i.value; return *this; }
Zfloat& Zfloat::operator/= ( const Zint& i ) {
#if defined(DIV_BY_ZERO_PROTECTION)
 if ( (float) i.value == 0.0f ) {  
#if defined(DIV_BY_ZERO_REPORTING)
  OUTPUT("Zfloat: divide by zero in /= operation!\n");
#endif
  value=0.0f;
  return *this;
 }
#endif
 value/=(float)i.value;
 return *this;
}

/// Zbyte operator= overloads for forward declared types

Zbyte& Zbyte::operator= ( const Zuint& i )   { value=(unsigned char)i.value; return *this; }
Zbyte& Zbyte::operator= ( const Zint& i )    { value=(unsigned char)i.value; return *this; }
Zbyte& Zbyte::operator= ( const Zfloat& f )  { value=(unsigned char)f.value; return *this; }
Zbyte& Zbyte::operator= ( const Zdouble& d ) { value=(unsigned char)d.value; return *this; }
Zbyte& Zbyte::operator= ( const Zstring& s ) { value=(unsigned char)atof(s.value.c_str()); return *this; }
unsigned char Zbyte::operator()( Zuint &i )   { return value=(unsigned char)i.value; }
unsigned char Zbyte::operator()( Zint &i )    { return value=(unsigned char)i.value; }
unsigned char Zbyte::operator()( Zfloat &f )  { return value=(unsigned char)f.value; }
unsigned char Zbyte::operator()( Zdouble &d ) { return value=(unsigned char)d.value; }

/// Zushort operator= overloads for forward declared types

Zushort& Zushort::operator= ( const Zuint& i )   { value=(unsigned short)i.value; return *this; }
Zushort& Zushort::operator= ( const Zint& i )    { value=(unsigned short)i.value; return *this; }
Zushort& Zushort::operator= ( const Zfloat& f )  { value=(unsigned short)f.value; return *this; }
Zushort& Zushort::operator= ( const Zdouble& d ) { value=(unsigned short)d.value; return *this; }
Zushort& Zushort::operator= ( const Zstring& s ) { value=(unsigned short)atof(s.value.c_str()); return *this; }
unsigned short Zushort::operator()( Zuint &i )   { return value=(unsigned short)i.value; }
unsigned short Zushort::operator()( Zint &i )    { return value=(unsigned short)i.value; }
unsigned short Zushort::operator()( Zfloat &f )  { return value=(unsigned short)f.value; }
unsigned short Zushort::operator()( Zdouble &d ) { return value=(unsigned short)d.value; }

/// Zuint operator= overloads for forward declared types

Zuint& Zuint::operator= ( const Zbyte& b )   { value=(unsigned int)b.value; return *this; }
Zuint& Zuint::operator= ( const Zint& i )    { value=(unsigned int)i.value; return *this; }
Zuint& Zuint::operator= ( const Zfloat& f )  { value=(unsigned int)f.value; return *this; }
Zuint& Zuint::operator= ( const Zdouble& d ) { value=(unsigned int)d.value; return *this; }
Zuint& Zuint::operator= ( const Zstring& s ) { value=(unsigned int)atof(s.value.c_str()); return *this; }
unsigned int Zuint::operator()( Zbyte &b )   { return value=(unsigned int)b.value; }
unsigned int Zuint::operator()( Zint &i )    { return value=(unsigned int)i.value; }
unsigned int Zuint::operator()( Zfloat &f )  { return value=(unsigned int)f.value; }
unsigned int Zuint::operator()( Zdouble &d ) { return value=(unsigned int)d.value; }

/// Zint operator= overloads for forward declared types

Zint& Zint::operator= ( const Zbyte& b )   { value=(int)b.value; return *this; }
Zint& Zint::operator= ( const Zuint& i )   { value=(int)i.value; return *this; }
Zint& Zint::operator= ( const Zfloat& f )  { value=(int)f.value; return *this; }
Zint& Zint::operator= ( const Zdouble& d ) { value=(int)d.value; return *this; }
Zint& Zint::operator= ( const Zstring& s ) { value=(int)atof(s.value.c_str()); return *this; }
int Zint::operator()( Zbyte &b )   { return (value=(int)b.value); }
int Zint::operator()( Zuint &i )   { return (value=(int)i.value); }
int Zint::operator()( Zfloat &f )  { return (value=(int)f.value); }
int Zint::operator()( Zdouble &d ) { return (value=(int)d.value); }
Zint& Zint::operator+= ( const Zfloat& f ) { value+=(int)f.value; return *this; }
Zint& Zint::operator-= ( const Zfloat& f ) { value-=(int)f.value; return *this; }
Zint& Zint::operator*= ( const Zfloat& f ) { value*=(int)f.value; return *this; }
Zint& Zint::operator/= ( const Zfloat& f ) {
#if defined(DIV_BY_ZERO_PROTECTION)
 if ( (int) f.value == 0.0f ) {  
#if defined(DIV_BY_ZERO_REPORTING)
  OUTPUT("Zfloat: divide by zero in /= operation!\n");
#endif
  value=0;
  return *this;
 }
#endif
 value/=(int)f.value;
 return *this;
}

/// Zdouble operator= overloads for forward declared types

Zdouble& Zdouble::operator= ( const Zbyte& b )   { value=(double)b.value; return *this; }
Zdouble& Zdouble::operator= ( const Zuint& i )   { value=(double)i.value; return *this; }
Zdouble& Zdouble::operator= ( const Zint& i )    { value=(double)i.value; return *this; }
Zdouble& Zdouble::operator= ( const Zfloat& f )  { value=(double)f.value; return *this; }
Zdouble& Zdouble::operator= ( const Zstring& s ) { value=(double)atof(s.value.c_str()); return *this; }
double Zdouble::operator()( Zbyte &b )  { return value=(double)b.value; }
double Zdouble::operator()( Zuint &i )  { return value=(double)i.value; }
double Zdouble::operator()( Zint &i )   { return value=(double)i.value; }
double Zdouble::operator()( Zfloat &f ) { return value=(double)f.value; }

/// Zfloat ////////////////////////////////////////////////////////////////////////////////////////// start

// Mixed type operations
float operator+ ( const Zfloat& a, const Zint& b ) { return (float) b.value + a.value; }
float operator+ ( const Zint& a, const Zfloat& b ) { return (float) a.value + b.value; }
float operator* ( const Zfloat& a, const Zint& b ) { return (float) b.value * a.value; }
float operator* ( const Zint& a, const Zfloat& b ) { return (float) a.value * b.value; }

// Zfloat and itself
float operator+ ( const Zfloat& a, const Zfloat& b ) { return a.value+b.value; }
float operator- ( const Zfloat& a, const Zfloat& b ) { return a.value-b.value; }
float operator* ( const Zfloat& a, const Zfloat& b ) { return a.value*b.value; }
float operator/ ( const Zfloat& a, const Zfloat& b ) {
#if defined(DIV_BY_ZERO_PROTECTION)
 if ( b.value == 0.0f ) {
#if defined(DIV_BY_ZERO_REPORTING)
  OUTPUT("Zfloat: divide by zero in / operation!\n");
#endif
  return 0.0f;
 }
#endif
 return a.value/b.value;
}

/// Zfloat and int

// Casted int operations
float operator+ ( const Zfloat& a, int b ) { return a.value+(float)b; }
float operator- ( const Zfloat& a, int b ) { return a.value-(float)b; }
float operator* ( const Zfloat& a, int b ) { return a.value*(float)b; }
float operator/ ( const Zfloat& a, int b ) {
#if defined(DIV_BY_ZERO_PROTECTION)
 if ( b == 0 ) {
#if defined(DIV_BY_ZERO_REPORTING)
  OUTPUT("Zfloat: divide by zero in / operation!\n");
#endif
  return 0.0f;
 }
#endif
 return a.value/(float)b;
}
// Casted int operations reversed
float operator+ ( int b, const Zfloat& a ) { return a.value+(float)b; }
float operator- ( int b, const Zfloat& a ) { return (float)b-a.value; }
float operator* ( int b, const Zfloat& a ) { return a.value*(float)b; }
float operator/ ( int b, const Zfloat& a ) {
#if defined(DIV_BY_ZERO_PROTECTION)
 if ( a.value == 0.0f ) {
#if defined(DIV_BY_ZERO_REPORTING)
  OUTPUT("Zfloat: divide by zero in / operation!\n");
#endif
  return 0.0f;
 }
#endif
 return (float)b/a.value;
}

/// Zfloat and float

// Float operations
float operator+ ( float b, const Zfloat& a ) { return a.value+b; }
float operator- ( float b, const Zfloat& a ) { return b-a.value; }
float operator* ( float b, const Zfloat& a ) { return a.value*b; }
float operator/ ( float b, const Zfloat& a ) {
#if defined(DIV_BY_ZERO_PROTECTION)
 if ( a.value == 0.0f ) {
#if defined(DIV_BY_ZERO_REPORTING)
  OUTPUT("Zfloat: divide by zero in / operation!\n");
#endif
  return 0.0f;
 }
#endif
 return b/a.value;
}
// Float operations reversed
float operator+ ( const Zfloat& a, float b ) { return a.value+b; }
float operator- ( const Zfloat& a, float b ) { return a.value-b; }
float operator* ( const Zfloat& a, float b ) { return a.value*b; }
float operator/ ( const Zfloat& a, float b ) {
#if defined(DIV_BY_ZERO_PROTECTION)
 if ( b == 0.0f ) {
#if defined(DIV_BY_ZERO_REPORTING)
  OUTPUT("Zfloat: divide by zero in / operation!\n");
#endif
  return 0.0f;
 }
#endif
 return a.value/b;
}

/// Zfloat and double

// Casted double operations (leans toward double precision)
float operator+ ( double b, const Zfloat& a ) { return (float)((double)a.value+b); }
float operator- ( double b, const Zfloat& a ) { return (float)(b-(double)a.value); }
float operator* ( double b, const Zfloat& a ) { return (float)((double)a.value*b); }
float operator/ ( double b, const Zfloat& a ) {
#if defined(DIV_BY_ZERO_PROTECTION)
 if ( a.value == 0.0f) {
#if defined(DIV_BY_ZERO_REPORTING)
  OUTPUT("Zfloat: divide by zero in / operation!\n");
#endif
  return 0.0f;
 }
#endif
 return (float)(b/(double)a.value);
}
// Casted double operations reversed (leans toward double precision)
float operator+ ( const Zfloat& a, double b ) { return (float)((double)a.value+b); }
float operator- ( const Zfloat& a, double b ) { return (float)((double)a.value-b); }
float operator* ( const Zfloat& a, double b ) { return (float)((double)a.value*b); }
float operator/ ( const Zfloat& a, double b ) {
#if defined(DIV_BY_ZERO_PROTECTION)
 if ( b == 0.0 ) {
#if defined(DIV_BY_ZERO_REPORTING)
  OUTPUT("Zfloat: divide by zero in / operation!\n");
#endif
  return 0.0f;
 }
#endif
 return (float)((double)a.value/b);
}

// Zfloat boolean operations
bool operator>= ( const Zfloat& a, const Zfloat& b ) { return ( a.value >= b.value );    }
bool operator>= ( const Zfloat& a, const Zushort& b ) { return ((unsigned short) a.value >= b.value ); }
bool operator>= ( const Zfloat& a, const Zuint& b )   { return ((unsigned int) a.value >= b.value ); }
bool operator>= ( const Zfloat& a, const Zint& b )    { return ((int) a.value >= b.value ); }
bool operator>= ( const Zfloat& a, const Zdouble& b ) { return ((double) a.value >= b.value ); }
bool operator>= ( const Zbyte& a, const Zfloat& b )   { return (a.value >= (unsigned char) b.value ); }
bool operator>= ( const Zushort& a, const Zfloat& b ) { return (a.value >= (unsigned short) b.value ); }
bool operator>= ( const Zuint& a, const Zfloat& b )   { return (a.value >= (unsigned int) b.value ); }
bool operator>= ( const Zint& a, const Zfloat& b )    { return (a.value >= (int) b.value ); }
bool operator>= ( const Zdouble& a, const Zfloat& b ) { return (a.value >= (double) b.value ); }
bool operator>= ( const Zfloat& a, int b )           { return ( (int) a.value >= b );    }
bool operator>= ( const Zfloat& a, float b )         { return ( a.value >= b );          }
bool operator>= ( const Zfloat& a, double b )        { return ( (double) a.value >= b ); }
bool operator>= ( int a, const Zfloat& b )           { return ( a >= (int) b.value );    }
bool operator>= ( float a, const Zfloat& b )         { return ( a >= b.value );          }
bool operator>= ( double a, const Zfloat& b )        { return ( a >= (double) b.value ); }
bool operator== ( const Zfloat& a, const Zbyte& b )   { return ((unsigned char) a.value == b.value ); }
bool operator== ( const Zfloat& a, const Zushort& b ) { return ((unsigned short) a.value == b.value ); }
bool operator== ( const Zfloat& a, const Zuint& b )   { return ((unsigned int) a.value == b.value ); }
bool operator== ( const Zfloat& a, const Zint& b )    { return ((int) a.value == b.value ); }
bool operator== ( const Zfloat& a, const Zdouble& b ) { return ((double) a.value == b.value ); }
bool operator== ( const Zbyte& a, const Zfloat& b )   { return (a.value == (unsigned char) b.value ); }
bool operator== ( const Zushort& a, const Zfloat& b ) { return (a.value == (unsigned short) b.value ); }
bool operator== ( const Zuint& a, const Zfloat& b )   { return (a.value == (unsigned int) b.value ); }
bool operator== ( const Zint& a, const Zfloat& b )    { return (a.value == (int) b.value ); }
bool operator== ( const Zdouble& a, const Zfloat& b ) { return (a.value == (double) b.value ); }
bool operator== ( const Zfloat& a, const Zfloat& b ) { return ( a.value == b.value );    }
bool operator== ( const Zfloat& a, int b )           { return ( (int) a.value == b );    }
bool operator== ( const Zfloat& a, float b )         { return ( a.value == b );          }
bool operator== ( const Zfloat& a, double b )        { return ( (double) a.value == b ); }
bool operator== ( int a, const Zfloat& b )           { return ( a == (int) b.value );    }
bool operator== ( float a, const Zfloat& b )         { return ( a == b.value );          }
bool operator== ( double a, const Zfloat& b )        { return ( a == (double) b.value ); }
bool operator!= ( const Zfloat& a, const Zfloat& b ) { return ( a.value != b.value );    }
bool operator!= ( const Zfloat& a, const Zushort& b ) { return ((unsigned short) a.value != b.value ); }
bool operator!= ( const Zfloat& a, const Zuint& b )   { return ((unsigned int) a.value != b.value ); }
bool operator!= ( const Zfloat& a, const Zint& b )    { return ((int) a.value != b.value ); }
bool operator!= ( const Zfloat& a, const Zdouble& b ) { return ((double) a.value != b.value ); }
bool operator!= ( const Zbyte& a, const Zfloat& b )   { return (a.value != (unsigned char) b.value ); }
bool operator!= ( const Zushort& a, const Zfloat& b ) { return (a.value != (unsigned short) b.value ); }
bool operator!= ( const Zuint& a, const Zfloat& b )   { return (a.value != (unsigned int) b.value ); }
bool operator!= ( const Zint& a, const Zfloat& b )    { return (a.value != (int) b.value ); }
bool operator!= ( const Zdouble& a, const Zfloat& b ) { return (a.value != (double) b.value ); }
bool operator!= ( const Zfloat& a, int b )           { return ( (int) a.value != b );    }
bool operator!= ( const Zfloat& a, float b )         { return ( a.value != b );          }
bool operator!= ( const Zfloat& a, double b )        { return ( (double) a.value != b ); }
bool operator!= ( int a, const Zfloat& b )           { return ( a != (int) b.value );    }
bool operator!= ( float a, const Zfloat& b )         { return ( a != b.value );          }
bool operator!= ( double a, const Zfloat& b )        { return ( a != (double) b.value ); }
bool operator<= ( const Zfloat& a, const Zfloat& b ) { return ( a.value <= b.value );    }
bool operator<= ( const Zfloat& a, const Zushort& b ) { return ((unsigned short) a.value <= b.value ); }
bool operator<= ( const Zfloat& a, const Zuint& b )   { return ((unsigned int) a.value <= b.value ); }
bool operator<= ( const Zfloat& a, const Zint& b )    { return ((int) a.value <= b.value ); }
bool operator<= ( const Zfloat& a, const Zdouble& b ) { return ((double) a.value <= b.value ); }
bool operator<= ( const Zbyte& a, const Zfloat& b )   { return (a.value <= (unsigned char) b.value ); }
bool operator<= ( const Zushort& a, const Zfloat& b ) { return (a.value <= (unsigned short) b.value ); }
bool operator<= ( const Zuint& a, const Zfloat& b )   { return (a.value <= (unsigned int) b.value ); }
bool operator<= ( const Zint& a, const Zfloat& b )    { return (a.value <= (int) b.value ); }
bool operator<= ( const Zdouble& a, const Zfloat& b ) { return (a.value <= (double) b.value ); }
bool operator<= ( const Zfloat& a, int b )           { return ( (int) a.value <= b );    }
bool operator<= ( const Zfloat& a, float b )         { return ( a.value <= b );          }
bool operator<= ( const Zfloat& a, double b )        { return ( (double) a.value <= b ); }
bool operator<= ( int a, const Zfloat& b )           { return ( a <= (int) b.value );    }
bool operator<= ( float a, const Zfloat& b )         { return ( a <= b.value );          }
bool operator<= ( double a, const Zfloat& b )        { return ( a <= (double) b.value ); }
bool operator> ( const Zfloat& a, const Zfloat& b )  { return ( a.value > b.value );    }
bool operator> ( const Zfloat& a, const Zushort& b ) { return ((unsigned short) a.value > b.value ); }
bool operator> ( const Zfloat& a, const Zuint& b )   { return ((unsigned int) a.value > b.value ); }
bool operator> ( const Zfloat& a, const Zint& b )    { return ((int) a.value > b.value ); }
bool operator> ( const Zfloat& a, const Zdouble& b ) { return ((double) a.value > b.value ); }
bool operator> ( const Zbyte& a, const Zfloat& b )   { return (a.value > (unsigned char) b.value ); }
bool operator> ( const Zushort& a, const Zfloat& b ) { return (a.value > (unsigned short) b.value ); }
bool operator> ( const Zuint& a, const Zfloat& b )   { return (a.value > (unsigned int) b.value ); }
bool operator> ( const Zint& a, const Zfloat& b )    { return (a.value > (int) b.value ); }
bool operator> ( const Zdouble& a, const Zfloat& b ) { return (a.value > (double) b.value ); }
bool operator> ( const Zfloat& a, int b )            { return ( (int) a.value > b );    }
bool operator> ( const Zfloat& a, float b )          { return ( a.value > b );          }
bool operator> ( const Zfloat& a, double b )         { return ( (double) a.value > b ); }
bool operator> ( int a, const Zfloat& b )            { return ( a > (int) b.value );    }
bool operator> ( float a, const Zfloat& b )          { return ( a > b.value );          }
bool operator> ( double a, const Zfloat& b )         { return ( a > (double) b.value ); }
bool operator< ( const Zfloat& a, const Zfloat& b )  { return ( a.value < b.value );    }
bool operator< ( const Zfloat& a, const Zushort& b ) { return ((unsigned short) a.value < b.value ); }
bool operator< ( const Zfloat& a, const Zuint& b )   { return ((unsigned int) a.value < b.value ); }
bool operator< ( const Zfloat& a, const Zint& b )    { return ((int) a.value < b.value ); }
bool operator< ( const Zfloat& a, const Zdouble& b ) { return ((double) a.value < b.value ); }
bool operator< ( const Zbyte& a, const Zfloat& b )   { return (a.value < (unsigned char) b.value ); }
bool operator< ( const Zushort& a, const Zfloat& b ) { return (a.value < (unsigned short) b.value ); }
bool operator< ( const Zuint& a, const Zfloat& b )   { return (a.value < (unsigned int) b.value ); }
bool operator< ( const Zint& a, const Zfloat& b )    { return (a.value < (int) b.value ); }
bool operator< ( const Zdouble& a, const Zfloat& b ) { return (a.value < (double) b.value ); }
bool operator< ( const Zfloat& a, int b )            { return ( (int) a.value < b );    }
bool operator< ( const Zfloat& a, float b )          { return ( a.value < b );          }
bool operator< ( const Zfloat& a, double b )         { return ( (double) a.value < b ); }
bool operator< ( int a, const Zfloat& b )            { return ( a < (int) b.value );    }
bool operator< ( float a, const Zfloat& b )          { return ( a < b.value );          }
bool operator< ( double a, const Zfloat& b )         { return ( a < (double) b.value ); }

/// Zfloat ////////////////////////////////////////////////////////////////////////////////////////// end

/// Zbyte ////////////////////////////////////////////////////////////////////////////////////////// start

unsigned char operator+ ( const Zbyte& a, const Zbyte& b ) {
 return a.value+b.value;
}
unsigned char operator- ( const Zbyte& a, const Zbyte& b ) {
 return a.value-b.value;
}
unsigned char operator* ( const Zbyte& a, const Zbyte& b ) {
 return a.value*b.value;
}
unsigned char operator/ ( const Zbyte& a, const Zbyte& b ) {
#if defined(DIV_BY_ZERO_PROTECTION)
 if ( b.value == 0 ) {
#if defined(DIV_BY_ZERO_REPORTING)
  OUTPUT("Zbyte: divide by zero in / operation!\n");
#endif
  return 0;
 }
#endif
 return a.value/b.value;
}

/// Zbyte and uint

// Casted int operations
unsigned char operator+ ( const Zbyte& a, unsigned char b ) {
 return a.value+b;
}
unsigned char operator- ( const Zbyte& a, unsigned char b ) {
 return a.value-b;
}
unsigned char operator* ( const Zbyte& a, unsigned char b ) {
 return a.value*b;
}
unsigned char operator/ ( const Zbyte& a, unsigned char b ) {
#if defined(DIV_BY_ZERO_PROTECTION)
 if ( b == 0 ) {
#if defined(DIV_BY_ZERO_REPORTING)
  OUTPUT("Zbyte: divide by zero in / operation!\n");
#endif
  return 0;
 }
#endif
 return a.value/b;
}
// Casted int operations reversed
unsigned char operator+ ( unsigned char b, const Zbyte& a ) {
 return a.value+b;
}
unsigned char operator- ( unsigned char b, const Zbyte& a ) {
 return b-a.value;
}
unsigned char operator* ( unsigned char b, const Zbyte& a ) {
 return a.value*b;
}
unsigned char operator/ ( unsigned char b, const Zbyte& a ) {
#if defined(DIV_BY_ZERO_PROTECTION)
 if ( a.value == 0 ) {
#if defined(DIV_BY_ZERO_REPORTING)
  OUTPUT("Zbyte: divide by zero in / operation!\n");
#endif
  return 0;
 }
#endif
 return b/a.value;
}

/// Zuint and int

// Casted int operations
unsigned char operator+ ( const Zbyte& a, int b ) {
 return a.value+(unsigned char) b;
}
unsigned char operator- ( const Zbyte& a, int b ) {
 return a.value-(unsigned char) b;
}
unsigned char operator* ( const Zbyte& a, int b ) {
 return a.value*(unsigned char) b;
}
unsigned char operator/ ( const Zbyte& a, int b ) {
#if defined(DIV_BY_ZERO_PROTECTION)
 if ( b == 0 ) {
#if defined(DIV_BY_ZERO_REPORTING)
  OUTPUT("Zbyte: divide by zero in / operation!\n");
#endif
  return 0;
 }
#endif
 return a.value/(unsigned char) b;
}
// Casted int operations reversed
unsigned char operator+ ( int b, const Zbyte& a ) {
 return a.value+(unsigned char) b;
}
unsigned char operator- ( int b, const Zbyte& a ) {
 return (unsigned char) b-a.value;
}
unsigned char operator* ( int b, const Zbyte& a ) {
 return a.value*(unsigned char) b;
}
unsigned char operator/ ( int b, const Zbyte& a ) {
#if defined(DIV_BY_ZERO_PROTECTION)
 if ( a.value == 0 ) {
#if defined(DIV_BY_ZERO_REPORTING)
  OUTPUT("Zbyte: divide by zero in / operation!\n");
#endif
  return 0;
 }
#endif
 return (unsigned char) b/a.value;
}

/// Zbyte and float

// Float operations (leans toward float precision)
unsigned char operator+ ( float b, const Zbyte& a ) {
 return (unsigned char)((float)a.value+b);
}
unsigned char operator- ( float b, const Zbyte& a ) {
 return (unsigned char)(b-(float)a.value);
}
unsigned char operator* ( float b, const Zbyte& a ) {
 return (unsigned char)((float)a.value*b);
}
unsigned char operator/ ( float b, const Zbyte& a ) {
#if defined(DIV_BY_ZERO_PROTECTION)
 if ( a.value == 0 ) {
#if defined(DIV_BY_ZERO_REPORTING)
  OUTPUT("Zbyte: divide by zero in / operation!\n");
#endif
  return 0;
 }
#endif
 return (unsigned char)(b/(float)a.value);
}
// Float operations reversed (leans toward float precision)
unsigned char operator+ ( const Zbyte& a, float b ) {
 return (unsigned char)((float)a.value+b);
}
unsigned char operator- ( const Zbyte& a, float b ) {
 return (unsigned char)((float)a.value-b);
}
unsigned char operator* ( const Zbyte& a, float b ) {
 return (unsigned char)((float)a.value*b);
}
unsigned char operator/ ( const Zbyte& a, float b ) {
#if defined(DIV_BY_ZERO_PROTECTION)
 if ( b == 0.0f ) {
#if defined(DIV_BY_ZERO_REPORTING)
  OUTPUT("Zbyte: divide by zero in / operation!\n");
#endif
  return 0;
 }
#endif

 return (unsigned char)((float)a.value/b);
}

/// Zbyte and double

// Casted double operations (leans toward double precision)
unsigned char operator+ ( double b, const Zbyte& a ) {
 return (unsigned char)((double)a.value+b);
}
unsigned char operator- ( double b, const Zbyte& a ) {
 return (unsigned char)(b-(double)a.value);
}
unsigned char operator* ( double b, const Zbyte& a ) {
 return (unsigned char)((double)a.value*b);
}
unsigned char operator/ ( double b, const Zbyte& a ) {
#if defined(DIV_BY_ZERO_PROTECTION)
 if ( a.value == 0) {
#if defined(DIV_BY_ZERO_REPORTING)
  OUTPUT("Zbyte: divide by zero in / operation!\n");
#endif
  return 0;
 }
#endif
 return (unsigned char)(b/(double)a.value);
}
// Casted double operations reversed (leans toward double precision)
unsigned char operator+ ( const Zbyte& a, double b ) {
 return (unsigned char)((double)a.value+b);
}
unsigned char operator- ( const Zbyte& a, double b ) {
 return (unsigned char)((double)a.value-b);
}
unsigned char operator* ( const Zbyte& a, double b ) {
 return (unsigned char)((double)a.value*b);
}
unsigned char operator/ ( const Zbyte& a, double b ) {
#if defined(DIV_BY_ZERO_PROTECTION)
 if ( b == 0.0 ) {
#if defined(DIV_BY_ZERO_REPORTING)
  OUTPUT("Zbyte: divide by zero in / operation!\n");
#endif
  return 0;
 }
#endif
 return (unsigned char)((double)a.value/b);
}


// Boolean operations
bool operator>= ( const Zbyte& a, const Zbyte& b ) { return ( a.value >= b.value );    }
bool operator>= ( const Zbyte& a, int b )            { return ( a.value >= (unsigned char) b ); }
bool operator>= ( const Zbyte& a, float b )          { return ( a.value >= (unsigned char) b ); }
bool operator>= ( const Zbyte& a, double b )         { return ( a.value >= (unsigned char) b ); }
bool operator>= ( int a, const Zbyte& b )            { return ( (unsigned char) a >= b.value ); }
bool operator>= ( float a, const Zbyte& b )          { return ( (unsigned char) a >= b.value ); }
bool operator>= ( double a, const Zbyte& b )         { return ( (unsigned char) a >= b.value ); }
bool operator== ( const Zbyte& a, const Zbyte& b ) { return ( a.value == b.value );    }
bool operator== ( const Zbyte& a, int b )            { return ( a.value == (unsigned char) b ); }
bool operator== ( const Zbyte& a, float b )          { return ( a.value == (unsigned char) b ); }
bool operator== ( const Zbyte& a, double b )         { return ( a.value == (unsigned char) b ); }
bool operator== ( int a, const Zbyte& b )            { return ( (unsigned char) a == b.value ); }
bool operator== ( float a, const Zbyte& b )          { return ( (unsigned char) a == b.value ); }
bool operator== ( double a, const Zbyte& b )         { return ( (unsigned char) a == b.value ); }
bool operator!= ( const Zbyte& a, const Zbyte& b ) { return ( a.value != b.value );    }
bool operator!= ( const Zbyte& a, int b )            { return ( a.value != (unsigned char) b ); }
bool operator!= ( const Zbyte& a, float b )          { return ( a.value != (unsigned char) b ); }
bool operator!= ( const Zbyte& a, double b )         { return ( a.value != (unsigned char) b ); }
bool operator!= ( int a, const Zbyte& b )            { return ( (unsigned char) a != b.value ); }
bool operator!= ( float a, const Zbyte& b )          { return ( (unsigned char) a != b.value ); }
bool operator!= ( double a, const Zbyte& b )         { return ( (unsigned char) a != b.value ); }
bool operator<= ( const Zbyte& a, const Zbyte& b ) { return ( a.value <= b.value );    }
bool operator<= ( const Zbyte& a, int b )            { return ( a.value <= (unsigned char) b ); }
bool operator<= ( const Zbyte& a, float b )          { return ( a.value <= (unsigned char) b ); }
bool operator<= ( const Zbyte& a, double b )         { return ( a.value <= (unsigned char) b ); }
bool operator<= ( int a, const Zbyte& b )            { return ( (unsigned char) a <= b.value ); }
bool operator<= ( float a, const Zbyte& b )          { return ( (unsigned char) a <= b.value ); }
bool operator<= ( double a, const Zbyte& b )         { return ( (unsigned char) a <= b.value ); }
bool operator> ( const Zbyte& a, const Zbyte& b )  { return ( a.value > b.value );    }
bool operator> ( const Zbyte& a, int b )             { return ( a.value > (unsigned char) b ); }
bool operator> ( const Zbyte& a, float b )           { return ( a.value > (unsigned char) b ); }
bool operator> ( const Zbyte& a, double b )          { return ( a.value > (unsigned char) b ); }
bool operator> ( int a, const Zbyte& b )             { return ( (unsigned char) a > b.value ); }
bool operator> ( float a, const Zbyte& b )           { return ( (unsigned char) a > b.value ); }
bool operator> ( double a, const Zbyte& b )          { return ( (unsigned char) a > b.value ); }
bool operator< ( const Zbyte& a, const Zbyte& b )  { return ( a.value < b.value );    }
bool operator< ( const Zbyte& a, int b )             { return ( a.value < (unsigned char) b ); }
bool operator< ( const Zbyte& a, float b )           { return ( a.value < (unsigned char) b ); }
bool operator< ( const Zbyte& a, double b )          { return ( a.value < (unsigned char) b ); }
bool operator< ( int a, const Zbyte& b )             { return ( (unsigned char) a < b.value ); }
bool operator< ( float a, const Zbyte& b )           { return ( (unsigned char) a < b.value ); }
bool operator< ( double a, const Zbyte& b )          { return ( (unsigned char) a < b.value ); }

/// Zbyte ////////////////////////////////////////////////////////////////////////////////////////// end


/// Zushort ////////////////////////////////////////////////////////////////////////////////////////// start

unsigned short operator+ ( const Zushort& a, const Zushort& b ) {
 return a.value+b.value;
}
unsigned short operator- ( const Zushort& a, const Zushort& b ) {
 return a.value-b.value;
}
unsigned short operator* ( const Zushort& a, const Zushort& b ) {
 return a.value*b.value;
}
unsigned short operator/ ( const Zushort& a, const Zushort& b ) {
#if defined(DIV_BY_ZERO_PROTECTION)
 if ( b.value == 0 ) {
#if defined(DIV_BY_ZERO_REPORTING)
  OUTPUT("Zushort: divide by zero in / operation!\n");
#endif
  return 0;
 }
#endif
 return a.value/b.value;
}

/// Zbyte and uint

// Casted int operations
unsigned short operator+ ( const Zushort& a, unsigned short b ) {
 return a.value+b;
}
unsigned short operator- ( const Zushort& a, unsigned short b ) {
 return a.value-b;
}
unsigned short operator* ( const Zushort& a, unsigned short b ) {
 return a.value*b;
}
unsigned short operator/ ( const Zushort& a, unsigned short b ) {
#if defined(DIV_BY_ZERO_PROTECTION)
 if ( b == 0 ) {
#if defined(DIV_BY_ZERO_REPORTING)
  OUTPUT("Zushort: divide by zero in / operation!\n");
#endif
  return 0;
 }
#endif
 return a.value/b;
}
// Casted int operations reversed
unsigned short operator+ ( unsigned short b, const Zushort& a ) {
 return a.value+b;
}
unsigned short operator- ( unsigned short b, const Zushort& a ) {
 return b-a.value;
}
unsigned short operator* ( unsigned short b, const Zushort& a ) {
 return a.value*b;
}
unsigned short operator/ ( unsigned short b, const Zushort& a ) {
#if defined(DIV_BY_ZERO_PROTECTION)
 if ( a.value == 0 ) {
#if defined(DIV_BY_ZERO_REPORTING)
  OUTPUT("Zushort: divide by zero in / operation!\n");
#endif
  return 0;
 }
#endif
 return b/a.value;
}

/// Zushort and int

// Casted int operations
unsigned short operator+ ( const Zushort& a, int b ) {
 return a.value+(unsigned short) b;
}
unsigned short operator- ( const Zushort& a, int b ) {
 return a.value-(unsigned short) b;
}
unsigned short operator* ( const Zushort& a, int b ) {
 return a.value*(unsigned short) b;
}
unsigned short operator/ ( const Zushort& a, int b ) {
#if defined(DIV_BY_ZERO_PROTECTION)
 if ( b == 0 ) {
#if defined(DIV_BY_ZERO_REPORTING)
  OUTPUT("Zushort: divide by zero in / operation!\n");
#endif
  return 0;
 }
#endif
 return a.value/(unsigned short) b;
}
// Casted int operations reversed
unsigned short operator+ ( int b, const Zushort& a ) {
 return a.value+(unsigned short) b;
}
unsigned short operator- ( int b, const Zushort& a ) {
 return (unsigned short) b-a.value;
}
unsigned short operator* ( int b, const Zushort& a ) {
 return a.value*(unsigned short) b;
}
unsigned short operator/ ( int b, const Zushort& a ) {
#if defined(DIV_BY_ZERO_PROTECTION)
 if ( a.value == 0 ) {
#if defined(DIV_BY_ZERO_REPORTING)
  OUTPUT("Zushort: divide by zero in / operation!\n");
#endif
  return 0;
 }
#endif
 return (unsigned short) b/a.value;
}

/// Zbyte and float

// Float operations (leans toward float precision)
unsigned short operator+ ( float b, const Zushort& a ) {
 return (unsigned short)((float)a.value+b);
}
unsigned short operator- ( float b, const Zushort& a ) {
 return (unsigned short)(b-(float)a.value);
}
unsigned short operator* ( float b, const Zushort& a ) {
 return (unsigned short)((float)a.value*b);
}
unsigned short operator/ ( float b, const Zushort& a ) {
#if defined(DIV_BY_ZERO_PROTECTION)
 if ( a.value == 0 ) {
#if defined(DIV_BY_ZERO_REPORTING)
  OUTPUT("Zushort: divide by zero in / operation!\n");
#endif
  return 0;
 }
#endif
 return (unsigned char)(b/(float)a.value);
}
// Float operations reversed (leans toward float precision)
unsigned short operator+ ( const Zushort& a, float b ) {
 return (unsigned short)((float)a.value+b);
}
unsigned short operator- ( const Zushort& a, float b ) {
 return (unsigned short)((float)a.value-b);
}
unsigned short operator* ( const Zushort& a, float b ) {
 return (unsigned short)((float)a.value*b);
}
unsigned short operator/ ( const Zushort& a, float b ) {
#if defined(DIV_BY_ZERO_PROTECTION)
 if ( b == 0.0f ) {
#if defined(DIV_BY_ZERO_REPORTING)
  OUTPUT("Zushort: divide by zero in / operation!\n");
#endif
  return 0;
 }
#endif

 return (unsigned short)((float)a.value/b);
}

/// Zbyte and double

// Casted double operations (leans toward double precision)
unsigned short operator+ ( double b, const Zushort& a ) {
 return (unsigned short)((double)a.value+b);
}
unsigned short operator- ( double b, const Zushort& a ) {
 return (unsigned short)(b-(double)a.value);
}
unsigned short operator* ( double b, const Zushort& a ) {
 return (unsigned short)((double)a.value*b);
}
unsigned short operator/ ( double b, const Zushort& a ) {
#if defined(DIV_BY_ZERO_PROTECTION)
 if ( a.value == 0) {
#if defined(DIV_BY_ZERO_REPORTING)
  OUTPUT("Zushort: divide by zero in / operation!\n");
#endif
  return 0;
 }
#endif
 return (unsigned short)(b/(double)a.value);
}
// Casted double operations reversed (leans toward double precision)
unsigned short operator+ ( const Zushort& a, double b ) {
 return (unsigned short)((double)a.value+b);
}
unsigned short operator- ( const Zushort& a, double b ) {
 return (unsigned short)((double)a.value-b);
}
unsigned short operator* ( const Zushort& a, double b ) {
 return (unsigned short)((double)a.value*b);
}
unsigned short operator/ ( const Zushort& a, double b ) {
#if defined(DIV_BY_ZERO_PROTECTION)
 if ( b == 0.0 ) {
#if defined(DIV_BY_ZERO_REPORTING)
  OUTPUT("Zbyte: divide by zero in / operation!\n");
#endif
  return 0;
 }
#endif
 return (unsigned short)((double)a.value/b);
}

/// Zushort ////////////////////////////////////////////////////////////////////////////////////////// end

/// Zint ////////////////////////////////////////////////////////////////////////////////////////// start

int operator+ ( const Zint& a, const Zint& b ) { return a.value+b.value; }
int operator- ( const Zint& a, const Zint& b ) { return a.value-b.value; }
int operator* ( const Zint& a, const Zint& b ) { return a.value*b.value; }
int operator/ ( const Zint& a, const Zint& b ) {
#if defined(DIV_BY_ZERO_PROTECTION)
 if ( b.value == 0 ) {
#if defined(DIV_BY_ZERO_REPORTING)
  OUTPUT("Zint: divide by zero in / operation!\n");
#endif
  return 0;
 }
#endif
 return a.value/b.value;
}

/// Zint and int

// Casted int operations
int operator+ ( const Zint& a, int b ) { return a.value+b; }
int operator- ( const Zint& a, int b ) { return a.value-b; }
int operator* ( const Zint& a, int b ) { return a.value*b; }
int operator/ ( const Zint& a, int b ) {
#if defined(DIV_BY_ZERO_PROTECTION)
 if ( b == 0 ) {
#if defined(DIV_BY_ZERO_REPORTING)
  OUTPUT("Zint: divide by zero in / operation!\n");
#endif
  return 0;
 }
#endif
 return a.value/b;
}
int operator% ( const Zint& a, int b ) {
#if defined(DIV_BY_ZERO_PROTECTION)
 if ( b == 0 ) {
#if defined(DIV_BY_ZERO_REPORTING)
  OUTPUT("Zint: modulo by zero in %% operation!\n");
#endif
  return 0;
 }
#endif
 return a.value%b;
}
// Casted int operations reversed
int operator+ ( int b, const Zint& a ) { return a.value+b; }
int operator- ( int b, const Zint& a ) { return b-a.value; }
int operator* ( int b, const Zint& a ) { return a.value*b; }
int operator/ ( int b, const Zint& a ) {
#if defined(DIV_BY_ZERO_PROTECTION)
 if ( a.value == 0 ) {
#if defined(DIV_BY_ZERO_REPORTING)
  OUTPUT("Zint: divide by zero in / operation!\n");
#endif
  return 0;
 }
#endif
 return b/a.value;
}
int operator% ( int b, const Zint& a ) {
#if defined(DIV_BY_ZERO_PROTECTION)
 if ( a.value == 0 ) {
#if defined(DIV_BY_ZERO_REPORTING)
  OUTPUT("Zint: modulo by zero in %% operation!\n");
#endif
  return 0;
 }
#endif
 return b%a.value;
}

/// Zint and float

// Float operations (leans toward float precision)
int operator+ ( float b, const Zint& a ) { return (int)((float)a.value+b); }
int operator- ( float b, const Zint& a ) { return (int)(b-(float)a.value); }
int operator* ( float b, const Zint& a ) { return (int)((float)a.value*b); }
int operator/ ( float b, const Zint& a ) {
#if defined(DIV_BY_ZERO_PROTECTION)
 if ( a.value == 0 ) {
#if defined(DIV_BY_ZERO_REPORTING)
  OUTPUT("Zint: divide by zero in / operation!\n");
#endif
  return 0;
 }
#endif
 return (int)(b/(float)a.value);
}
// Float operations reversed (leans toward float precision)
int operator+ ( const Zint& a, float b ) { return (int)((float)a.value+b); }
int operator- ( const Zint& a, float b ) { return (int)((float)a.value-b); }
int operator* ( const Zint& a, float b ) { return (int)((float)a.value*b); }
int operator/ ( const Zint& a, float b ) {
#if defined(DIV_BY_ZERO_PROTECTION)
 if ( b == 0.0f ) {
#if defined(DIV_BY_ZERO_REPORTING)
  OUTPUT("Zint: divide by zero in / operation!\n");
#endif
  return 0;
 }
#endif

 return (int)((float)a.value/b);
}

/// Zint and double

// Casted double operations (leans toward double precision)
int operator+ ( double b, const Zint& a ) { return (int)((double)a.value+b); }
int operator- ( double b, const Zint& a ) { return (int)(b-(double)a.value); }
int operator* ( double b, const Zint& a ) { return (int)((double)a.value*b); }
int operator/ ( double b, const Zint& a ) {
#if defined(DIV_BY_ZERO_PROTECTION)
 if ( a.value == 0) {
#if defined(DIV_BY_ZERO_REPORTING)
  OUTPUT("Zint: divide by zero in / operation!\n");
#endif
  return 0;
 }
#endif
 return (int)(b/(double)a.value);
}
// Casted double operations reversed (leans toward double precision)
int operator+ ( const Zint& a, double b ) { return (int)((double)a.value+b); }
int operator- ( const Zint& a, double b ) { return (int)((double)a.value-b); }
int operator* ( const Zint& a, double b ) { return (int)((double)a.value*b); }
int operator/ ( const Zint& a, double b ) {
#if defined(DIV_BY_ZERO_PROTECTION)
 if ( b == 0.0 ) {
#if defined(DIV_BY_ZERO_REPORTING)
  OUTPUT("Zint: divide by zero in / operation!\n");
#endif
  return 0;
 }
#endif
 return (int)((double)a.value/b);
}

// Modulo

int operator% ( const Zint& b, const Zint& a ) {
#if defined(DIV_BY_ZERO_PROTECTION)
 if ( a.value == 0 ) {
#if defined(DIV_BY_ZERO_REPORTING)
  OUTPUT("Zint: modulo by zero in %% operation!\n");
#endif
  return 0;
 }
#endif
 return b.value%a.value;
}

// Zint boolean operations
bool operator>= ( const Zint& a, const Zint& b ) { return ( a.value >= b.value ); }
bool operator>= ( const Zint& a, unsigned int b ) { return ( (unsigned int) a.value >= b ); }
bool operator>= ( const Zint& a, int b )         { return ( a.value >= b );       }
bool operator>= ( const Zint& a, float b )       { return ( a.value >= (int) b ); }
bool operator>= ( const Zint& a, double b )      { return ( a.value >= (int) b ); }
bool operator>= ( unsigned int a, const Zint& b ) { return ( a >= (unsigned int) b.value ); }
bool operator>= ( int a, const Zint& b )         { return ( a >= b.value );       }
bool operator>= ( float a, const Zint& b )       { return ( (int) a >= b.value ); }
bool operator>= ( double a, const Zint& b )      { return ( (int) a >= b.value ); }
bool operator== ( const Zint& a, const Zbyte& b )   { return ((unsigned char) a.value == b.value ); }
bool operator== ( const Zint& a, const Zushort& b ) { return ((unsigned short) a.value == b.value ); }
bool operator== ( const Zint& a, const Zuint& b )   { return ((unsigned int) a.value == b.value ); }
bool operator== ( const Zint& a, const Zdouble& b ) { return ((double) a.value == b.value ); }
bool operator== ( const Zbyte& a, const Zint& b )   { return (a.value == (unsigned char) b.value ); }
bool operator== ( const Zushort& a, const Zint& b ) { return (a.value == (unsigned short) b.value ); }
bool operator== ( const Zuint& a, const Zint& b )   { return (a.value == (unsigned int) b.value ); }
bool operator== ( const Zdouble& a, const Zint& b ) { return (a.value == (double) b.value ); }
bool operator== ( const Zint& a, const Zint& b ) { return ( a.value == b.value ); }
bool operator== ( const Zint& a, unsigned int b ) { return ( (unsigned int) a.value >= b ); }
bool operator== ( const Zint& a, int b )         { return ( a.value == b );       }
bool operator== ( const Zint& a, float b )       { return ( a.value == (int) b ); }
bool operator== ( const Zint& a, double b )      { return ( a.value == (int) b ); }
bool operator== ( unsigned int a, const Zint& b ) { return ( a == (unsigned int) b.value ); }
bool operator== ( int a, const Zint& b )         { return ( a == b.value );       }
bool operator== ( float a, const Zint& b )       { return ( (int) a == b.value ); }
bool operator== ( double a, const Zint& b )      { return ( (int) a == b.value ); }
bool operator!= ( const Zint& a, const Zint& b ) { return ( a.value != b.value ); }
bool operator!= ( const Zint& a, unsigned int b ) { return ( (unsigned int) a.value != b ); }
bool operator!= ( const Zint& a, int b )         { return ( a.value != b );       }
bool operator!= ( const Zint& a, float b )       { return ( a.value != (int) b ); }
bool operator!= ( const Zint& a, double b )      { return ( a.value != (int) b ); }
bool operator!= ( unsigned int a, const Zint& b ) { return ( a != (unsigned int) b.value ); }
bool operator!= ( int a, const Zint& b )         { return ( a != b.value );       }
bool operator!= ( float a, const Zint& b )       { return ( (int) a != b.value ); }
bool operator!= ( double a, const Zint& b )      { return ( (int) a != b.value ); }
bool operator<= ( const Zint& a, const Zint& b ) { return ( a.value <= b.value ); }
bool operator<= ( const Zint& a, unsigned int b ) { return ( (unsigned int) a.value <= b ); }
bool operator<= ( const Zint& a, int b )         { return ( a.value <= b );       }
bool operator<= ( const Zint& a, float b )       { return ( a.value <= (int) b ); }
bool operator<= ( const Zint& a, double b )      { return ( a.value <= (int) b ); }
bool operator<= ( unsigned int a, const Zint& b ) { return ( a <= (unsigned int) b.value ); }
bool operator<= ( int a, const Zint& b )         { return ( a <= b.value );       }
bool operator<= ( float a, const Zint& b )       { return ( (int) a <= b.value ); }
bool operator<= ( double a, const Zint& b )      { return ( (int) a <= b.value ); }
bool operator> ( const Zint& a, const Zint& b )  { return ( a.value > b.value ); }
bool operator> ( const Zint& a, unsigned int b ) { return ( (unsigned int) a.value > b ); }
bool operator> ( const Zint& a, int b )          { return ( a.value > b );       }
bool operator> ( const Zint& a, float b )        { return ( a.value > (int) b ); }
bool operator> ( const Zint& a, double b )       { return ( a.value > (int) b ); }
bool operator> ( unsigned int a, const Zint& b ) { return ( a > (unsigned int) b.value ); }
bool operator> ( int a, const Zint& b )          { return ( a > b.value );       }
bool operator> ( float a, const Zint& b )        { return ( (int) a > b.value ); }
bool operator> ( double a, const Zint& b )       { return ( (int) a > b.value ); }
bool operator< ( const Zint& a, const Zint& b )  { return ( a.value < b.value ); }
bool operator< ( const Zint& a, unsigned int b ) { return ( (unsigned int) a.value < b ); }
bool operator< ( const Zint& a, int b )          { return ( a.value < b );       }
bool operator< ( const Zint& a, float b )        { return ( a.value < (int) b ); }
bool operator< ( const Zint& a, double b )       { return ( a.value < (int) b ); }
bool operator< ( unsigned int a, const Zint& b ) { return ( a < (unsigned int) b.value ); }
bool operator< ( int a, const Zint& b )          { return ( a < b.value );       }
bool operator< ( float a, const Zint& b )        { return ( (int) a < b.value ); }
bool operator< ( double a, const Zint& b )       { return ( (int) a < b.value ); }

/// Zint ////////////////////////////////////////////////////////////////////////////////////////// end

/// Zuint ////////////////////////////////////////////////////////////////////////////////////////// start

unsigned int operator+ ( const Zuint& a, const Zuint& b ) {
 return a.value+b.value;
}
unsigned int operator- ( const Zuint& a, const Zuint& b ) {
 return a.value-b.value;
}
unsigned int operator* ( const Zuint& a, const Zuint& b ) {
 return a.value*b.value;
}
unsigned int operator/ ( const Zuint& a, const Zuint& b ) {
#if defined(DIV_BY_ZERO_PROTECTION)
 if ( b.value == 0 ) {
#if defined(DIV_BY_ZERO_REPORTING)
  OUTPUT("Zuint: divide by zero in / operation!\n");
#endif
  return 0;
 }
#endif
 return a.value/b.value;
}

/// Zuint and uint

// Casted int operations
unsigned int operator+ ( const Zuint& a, unsigned int b ) {
 return a.value+b;
}
unsigned int operator- ( const Zuint& a, unsigned int b ) {
 return a.value-b;
}
unsigned int operator* ( const Zuint& a, unsigned int b ) {
 return a.value*b;
}
unsigned int operator/ ( const Zuint& a, unsigned int b ) {
#if defined(DIV_BY_ZERO_PROTECTION)
 if ( b == 0 ) {
#if defined(DIV_BY_ZERO_REPORTING)
  OUTPUT("Zuint: divide by zero in / operation!\n");
#endif
  return 0;
 }
#endif
 return a.value/b;
}
bool operator< ( unsigned int a, const Zuint& b ) { return ( a < b.value ); }
// Casted int operations reversed
unsigned int operator+ ( unsigned int b, const Zuint& a ) {
 return a.value+b;
}
unsigned int operator- ( unsigned int b, const Zuint& a ) {
 return b-a.value;
}
unsigned int operator* ( unsigned int b, const Zuint& a ) {
 return a.value*b;
}
unsigned int operator/ ( unsigned int b, const Zuint& a ) {
#if defined(DIV_BY_ZERO_PROTECTION)
 if ( a.value == 0 ) {
#if defined(DIV_BY_ZERO_REPORTING)
  OUTPUT("Zuint: divide by zero in / operation!\n");
#endif
  return 0;
 }
#endif
 return b/a.value;
}

/// Zuint and int

// Casted int operations
unsigned int operator+ ( const Zuint& a, int b ) {
 return a.value+(unsigned int) b;
}
unsigned int operator- ( const Zuint& a, int b ) {
 return a.value-(unsigned int) b;
}
unsigned int operator* ( const Zuint& a, int b ) {
 return a.value*(unsigned int) b;
}
unsigned int operator/ ( const Zuint& a, int b ) {
#if defined(DIV_BY_ZERO_PROTECTION)
 if ( b == 0 ) {
#if defined(DIV_BY_ZERO_REPORTING)
  OUTPUT("Zuint: divide by zero in / operation!\n");
#endif
  return 0;
 }
#endif
 return a.value/(unsigned int) b;
}
// Casted int operations reversed
unsigned int operator+ ( int b, const Zuint& a ) {
 return a.value+(unsigned int) b;
}
unsigned int operator- ( int b, const Zuint& a ) {
 return (unsigned int) b-a.value;
}
unsigned int operator* ( int b, const Zuint& a ) {
 return a.value*(unsigned int) b;
}
unsigned int operator/ ( int b, const Zuint& a ) {
#if defined(DIV_BY_ZERO_PROTECTION)
 if ( a.value == 0 ) {
#if defined(DIV_BY_ZERO_REPORTING)
  OUTPUT("Zuint: divide by zero in / operation!\n");
#endif
  return 0;
 }
#endif
 return (unsigned int) b/a.value;
}

/// Zuint and float

// Float operations (leans toward float precision)
unsigned int operator+ ( float b, const Zuint& a ) {
 return (unsigned int)((float)a.value+b);
}
unsigned int operator- ( float b, const Zuint& a ) {
 return (unsigned int)(b-(float)a.value);
}
unsigned int operator* ( float b, const Zuint& a ) {
 return (unsigned int)((float)a.value*b);
}
unsigned int operator/ ( float b, const Zuint& a ) {
#if defined(DIV_BY_ZERO_PROTECTION)
 if ( a.value == 0 ) {
#if defined(DIV_BY_ZERO_REPORTING)
  OUTPUT("Zuint: divide by zero in / operation!\n");
#endif
  return 0;
 }
#endif
 return (unsigned int)(b/(float)a.value);
}
// Float operations reversed (leans toward float precision)
unsigned int operator+ ( const Zuint& a, float b ) {
 return (unsigned int)((float)a.value+b);
}
unsigned int operator- ( const Zuint& a, float b ) {
 return (unsigned int)((float)a.value-b);
}
unsigned int operator* ( const Zuint& a, float b ) {
 return (unsigned int)((float)a.value*b);
}
unsigned int operator/ ( const Zuint& a, float b ) {
#if defined(DIV_BY_ZERO_PROTECTION)
 if ( b == 0.0f ) {
#if defined(DIV_BY_ZERO_REPORTING)
  OUTPUT("Zuint: divide by zero in / operation!\n");
#endif
  return 0;
 }
#endif

 return (unsigned int)((float)a.value/b);
}

/// Zuint and double

// Casted double operations (leans toward double precision)
unsigned int operator+ ( double b, const Zuint& a ) {
 return (unsigned int)((double)a.value+b);
}
unsigned int operator- ( double b, const Zuint& a ) {
 return (unsigned int)(b-(double)a.value);
}
unsigned int operator* ( double b, const Zuint& a ) {
 return (unsigned int)((double)a.value*b);
}
unsigned int operator/ ( double b, const Zuint& a ) {
#if defined(DIV_BY_ZERO_PROTECTION)
 if ( a.value == 0) {
#if defined(DIV_BY_ZERO_REPORTING)
  OUTPUT("Zuint: divide by zero in / operation!\n");
#endif
  return 0;
 }
#endif
 return (unsigned int)(b/(double)a.value);
}
// Casted double operations reversed (leans toward double precision)
unsigned int operator+ ( const Zuint& a, double b ) {
 return (unsigned int)((double)a.value+b);
}
unsigned int operator- ( const Zuint& a, double b ) {
 return (unsigned int)((double)a.value-b);
}
unsigned int operator* ( const Zuint& a, double b ) {
 return (unsigned int)((double)a.value*b);
}
unsigned int operator/ ( const Zuint& a, double b ) {
#if defined(DIV_BY_ZERO_PROTECTION)
 if ( b == 0.0 ) {
#if defined(DIV_BY_ZERO_REPORTING)
  OUTPUT("Zuint: divide by zero in / operation!\n");
#endif
  return 0;
 }
#endif
 return (unsigned int)((double)a.value/b);
}

/// Zuint ////////////////////////////////////////////////////////////////////////////////////////// end

/// Zdouble ////////////////////////////////////////////////////////////////////////////////////////// start

// Mixed type operations
double operator+ ( const Zdouble& a, const Zfloat& b ) { return a.value + (double) b.value; }
double operator+ ( const Zfloat& a, const Zdouble& b ) { return (double) a.value + b.value; }
double operator+ ( const Zdouble& a, const Zint& b )   { return a.value + (double) b.value; }
double operator+ ( const Zint& a, const Zdouble& b )   { return (double) a.value + b.value; }
double operator* ( const Zdouble& a, const Zfloat& b ) { return a.value * (double) b.value; }
double operator* ( const Zfloat& a, const Zdouble& b ) { return (double) a.value * b.value; }
double operator* ( const Zdouble& a, const Zint& b )   { return a.value * (double) b.value; }
double operator* ( const Zint& a, const Zdouble& b )   { return (double) a.value * b.value; }
// Zdouble and itself
double operator+ ( const Zdouble& a, const Zdouble& b ) { return a.value+b.value; }
double operator- ( const Zdouble& a, const Zdouble& b ) { return a.value-b.value; }
double operator* ( const Zdouble& a, const Zdouble& b ) { return a.value*b.value; }
double operator/ ( const Zdouble& a, const Zdouble& b ) {
#if defined(DIV_BY_ZERO_PROTECTION)
 if ( b.value == 0.0f ) {
#if defined(DIV_BY_ZERO_REPORTING)
  OUTPUT("Zdouble: divide by zero in / operation!\n");
#endif
  return 0.0f;
 }
#endif
 return a.value/b.value;
}

/// Zdouble and int

// Casted int operations (leans toward double precision)
double operator+ ( const Zdouble& a, int b ) { return a.value+(double)b; }
double operator- ( const Zdouble& a, int b ) { return a.value-(double)b; }
double operator* ( const Zdouble& a, int b ) { return a.value*(double)b; }
double operator/ ( const Zdouble& a, int b ) {
#if defined(DIV_BY_ZERO_PROTECTION)
 if ( b == 0 ) {
#if defined(DIV_BY_ZERO_REPORTING)
  OUTPUT("Zdouble: divide by zero in / operation!\n");
#endif
  return 0.0;
 }
#endif
 return a.value/(double)b;
}
// Casted int operations reversed (leans toward double precision)
double operator+ ( int b, const Zdouble& a ) { return a.value+(double)b; }
double operator- ( int b, const Zdouble& a ) { return (double)b-a.value; }
double operator* ( int b, const Zdouble& a ) { return a.value*(double)b; }
double operator/ ( int b, const Zdouble& a ) {
#if defined(DIV_BY_ZERO_PROTECTION)
 if ( a.value == 0.0 ) {
#if defined(DIV_BY_ZERO_REPORTING)
  OUTPUT("Zdouble: divide by zero in / operation!\n");
#endif
  return 0.0;
 }
#endif
 return (double)b/a.value;
}

/// Zdouble and float

// Float operations (leans toward float precision)
double operator+ ( float b, const Zdouble& a ) { return a.value+(double)b; }
double operator- ( float b, const Zdouble& a ) { return (double)b-a.value; }
double operator* ( float b, const Zdouble& a ) { return a.value*(double)b; }
double operator/ ( float b, const Zdouble& a ) {
#if defined(DIV_BY_ZERO_PROTECTION)
 if ( a.value == 0.0 ) {
#if defined(DIV_BY_ZERO_REPORTING)
  OUTPUT("Zdouble: divide by zero in / operation!\n");
#endif
  return 0.0;
 }
#endif
 return (double)b/a.value;
}
// Float operations reversed (leans toward float precision)
double operator+ ( const Zdouble& a, float b ) { return a.value+(double)b; }
double operator- ( const Zdouble& a, float b ) { return a.value-(double)b; }
double operator* ( const Zdouble& a, float b ) { return a.value*(double)b; }
double operator/ ( const Zdouble& a, float b ) {
#if defined(DIV_BY_ZERO_PROTECTION)
 if ( b == 0.0f ) {
#if defined(DIV_BY_ZERO_REPORTING)
  OUTPUT("Zdouble: divide by zero in / operation!\n");
#endif
  return 0.0;
 }
#endif
 
 return a.value/(double)b;
}

/// Zdouble and double

// Casted double operations
double operator+ ( double b, const Zdouble& a ) { return a.value+b; }
double operator- ( double b, const Zdouble& a ) { return b-a.value; }
double operator* ( double b, const Zdouble& a ) { return a.value*b; }
double operator/ ( double b, const Zdouble& a ) {
#if defined(DIV_BY_ZERO_PROTECTION)
 if ( a.value == 0.0) {
#if defined(DIV_BY_ZERO_REPORTING)
  OUTPUT("Zdouble: divide by zero in / operation!\n");
#endif
  return 0.0;
 }
#endif
 return b/a.value;
}
// Casted double operations reversed
double operator+ ( const Zdouble& a, double b ) { return a.value+b; }
double operator- ( const Zdouble& a, double b ) { return a.value-b; }
double operator* ( const Zdouble& a, double b ) { return a.value*b; }
double operator/ ( const Zdouble& a, double b ) {
#if defined(DIV_BY_ZERO_PROTECTION)
 if ( b == 0.0 ) {
#if defined(DIV_BY_ZERO_REPORTING)
  OUTPUT("Zdouble: divide by zero in / operation!\n");
#endif
  return 0.0;
 }
#endif
 return a.value/b;
}

// Boolean operations
bool operator>= ( const Zdouble& a, const Zdouble& b ) { return ( a.value >= b.value );    }
bool operator>= ( const Zdouble& a, int b )            { return ( a.value >= (double) b ); }
bool operator>= ( const Zdouble& a, float b )          { return ( a.value >= (double) b ); }
bool operator>= ( const Zdouble& a, double b )         { return ( a.value >= b );          }
bool operator>= ( int a, const Zdouble& b )            { return ( (double) a >= b.value ); }
bool operator>= ( float a, const Zdouble& b )          { return ( (double) a >= b.value ); }
bool operator>= ( double a, const Zdouble& b )         { return ( a >= b.value );          }
bool operator== ( const Zdouble& a, const Zdouble& b ) { return ( a.value == b.value );    }
bool operator== ( const Zdouble& a, int b )            { return ( a.value == (double) b ); }
bool operator== ( const Zdouble& a, float b )          { return ( a.value == (double) b ); }
bool operator== ( const Zdouble& a, double b )         { return ( a.value == b );          }
bool operator== ( int a, const Zdouble& b )            { return ( (double) a == b.value ); }
bool operator== ( float a, const Zdouble& b )          { return ( (double) a == b.value ); }
bool operator== ( double a, const Zdouble& b )         { return ( a == b.value );          }
bool operator!= ( const Zdouble& a, const Zdouble& b ) { return ( a.value != b.value );    }
bool operator!= ( const Zdouble& a, int b )            { return ( a.value != (double) b ); }
bool operator!= ( const Zdouble& a, float b )          { return ( a.value != (double) b ); }
bool operator!= ( const Zdouble& a, double b )         { return ( a.value != b );          }
bool operator!= ( int a, const Zdouble& b )            { return ( (double) a != b.value ); }
bool operator!= ( float a, const Zdouble& b )          { return ( (double) a != b.value ); }
bool operator!= ( double a, const Zdouble& b )         { return ( a != b.value );          }
bool operator<= ( const Zdouble& a, const Zdouble& b ) { return ( a.value <= b.value );    }
bool operator<= ( const Zdouble& a, int b )            { return ( a.value <= (double) b ); }
bool operator<= ( const Zdouble& a, float b )          { return ( a.value <= (double) b ); }
bool operator<= ( const Zdouble& a, double b )         { return ( a.value <= b );          }
bool operator<= ( int a, const Zdouble& b )            { return ( (double) a <= b.value ); }
bool operator<= ( float a, const Zdouble& b )          { return ( (double) a <= b.value ); }
bool operator<= ( double a, const Zdouble& b )         { return ( a <= b.value );          }
bool operator> ( const Zdouble& a, const Zdouble& b )  { return ( a.value > b.value );    }
bool operator> ( const Zdouble& a, int b )             { return ( a.value > (double) b ); }
bool operator> ( const Zdouble& a, float b )           { return ( a.value > (double) b ); }
bool operator> ( const Zdouble& a, double b )          { return ( a.value > b );          }
bool operator> ( int a, const Zdouble& b )             { return ( (double) a > b.value ); }
bool operator> ( float a, const Zdouble& b )           { return ( (double) a > b.value ); }
bool operator> ( double a, const Zdouble& b )          { return ( a > b.value );          }
bool operator< ( const Zdouble& a, const Zdouble& b )  { return ( a.value < b.value );    }
bool operator< ( const Zdouble& a, int b )             { return ( a.value < (double) b ); }
bool operator< ( const Zdouble& a, float b )           { return ( a.value < (double) b ); }
bool operator< ( const Zdouble& a, double b )          { return ( a.value < b );          }
bool operator< ( int a, const Zdouble& b )             { return ( (double) a < b.value ); }
bool operator< ( float a, const Zdouble& b )           { return ( (double) a < b.value ); }
bool operator< ( double a, const Zdouble& b )          { return ( a < b.value );          }

/// Zdouble ////////////////////////////////////////////////////////////////////////////////////////// end

/// Zstring ////////////////////////////////////////////////////////////////////////////////////////// end

bool operator== ( const Zstring& a, const Zstring& b ) {
 bool result= !str_cmp(a.value.c_str(),b.value.c_str());
 if ( !result ) {
  if ( is_decimal(a.value.c_str()) && is_decimal(b.value.c_str()) ) {
   double A=atof(a.value.c_str());
   double B=atof(b.value.c_str());
   return ( A == B );
  }
 }
 return result;
}

bool operator== ( const Zstring& a, const char * b ) {
 return !str_cmp(a.value.c_str(),b);
}

bool operator== ( const char * b, const Zstring& a ) {
 return !str_cmp(a.value.c_str(),b);
}

bool operator== ( const Zstring& a, string b ) {
 return !str_cmp(a.value.c_str(),b.c_str());
}

bool operator== ( string b, const Zstring& a ) {
 return !str_cmp(a.value.c_str(),b.c_str());
}

string operator+ ( const Zstring& a, const Zstring& b ) {
 return a.value+b.value;
}

string operator+ ( const Zstring& a, const string& b ) {
 return a.value+b;
}

string operator+ ( const string& b, const Zstring& a ) {
 return a.value+b;
}

string operator+ ( const Zstring& a, char c ) {
 return a.value+c;
}

string operator- ( const Zstring& a, const Zstring& b ) {
 string result=a.value;
 replaceOnce(result,b.value,string(""));
 return result;
}

string operator- ( const Zstring& a, const string& b ) {
 string result=a.value;
 replaceOnce(result,b,string(""));
 return result;
}

string operator- ( const string& b, const Zstring& a ) {
 string result=b;
 replaceOnce(result,a.value,string(""));
 return result;
}

string operator- ( const Zstring& a, const char *b ) {
 string result=a.value;
 replaceOnce(result,string(b),string(""));
 return result;
}

string operator- ( const char *b, const Zstring& a ) {
 string result=string(b);
 replaceOnce(result,a.value,string(""));
 return result;
}

string operator/ ( const Zstring& a, const Zstring& b ) {
 string result=a.value;
 replaceAll(result,b.value,string(""));
 return result;
}

string operator/ ( const Zstring& a, const string& b ) {
 string result=a.value;
 replaceAll(result,b,string(""));
 return result;
}

string operator/ ( const string& b, const Zstring& a ) {
 string result=b;
 replaceAll(result,a.value,string(""));
 return result;
}

string operator/ ( const Zstring& a, const char *b ) {
 string result=a.value;
 replaceAll(result,string(b),string(""));
 return result;
}

string operator/ ( const char *b, const Zstring& a ) {
 string result=string(b);
 replaceAll(result,a.value,string(""));
 return result;
}

string operator* ( const Zstring& a, unsigned int i ) {
 string temp=string("");
 for ( unsigned int j=0; j<i; j++ ) {
  temp+=a.value;
 }
 return temp;
}

/// Zstring ////////////////////////////////////////////////////////////////////////////////////////// end
