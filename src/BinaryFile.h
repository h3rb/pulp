#pragma once
#include "string_functions.h"
#include "macros.h"
#include "ZeroTypes.h"
#include "Indexed.h"

//#include <iostream>
//#include <fstream>

void print_fopen_err( errno_t err );

// File Handler
class BinaryFile {
public:
// ifstream file;
 FILE *fp;
 Zbool end_of_file;
 errno_t err;
 size_t size;
 string filename;
 BinaryFile( const char *name, bool write ) {
  size=0;
  filename=string(name);
  fp = fopen(name, ( write ? "wb" : "rb" ) );
  if ( !fp ) {
   OUTPUT("BinaryFile::fopen_s() reports error accessing file `%s`\n", name);
   OUTPUT("Error message was "); print_fopen_err((int)errno);
   if ( fp ) fclose(fp);
  }
  if ( !write ) { /* checksums */ }
 }
/*
 BinaryFile( char *name, bool write, bool use_ifstream ) {
  filename=string(name);
  if ( use_ifstream ) {
   if ( write ) {
    file.open(name,ios::out|ios::binary);
   } else {
    file.open(name,ios::in|ios::binary);
   }
  } else {
   err = fopen_s(&fp,name, ( write ? "wb" : "rb" ) );
   if ( err != 0 ) OUTPUT("BinaryFile::fopen_s() reports error accessing file `%s`\n", name);
  }
 }
 */
 ~BinaryFile() {
  if ( fp ) {
   clearerr(fp);
   err=fflush(fp);
   if ( err != 0 ) {
    OUTPUT("fflush() reported an error %d, ferror() reports %d, errno=%d\n", err, ferror(fp), errno );
    OUTPUT("Error message was "); print_fopen_err((int)errno);
   }
   if ( fp ) err=fclose(fp);
   if ( err != 0 ) {
    OUTPUT("fclose() reported an error %d, ferror() reports %d, errno=%d\n", err, ferror(fp), errno );
    OUTPUT("Error message was "); print_fopen_err((int)errno);
   }
  }
  /*if (file.is_open()) file.close();*/
 }
 bool fileok() {
  return ( fp && err==0 && !end_of_file );
 }

 void Error( bool reading ) {
  err=1;
  if ( reading ) {
   end_of_file=true;
   OUTPUT("BinaryFile::read() warned of unexpected EOF (or other error, ferror=%d errno=%d) encountered.\n", ferror(fp),errno);
   OUTPUT("Error message was "); print_fopen_err((int)errno);
  } else {
   OUTPUT("BinaryFile::write() warns of unexpected error.\n");
   OUTPUT("Error message was "); print_fopen_err((int)errno);
  }
  if (fp) {
   OUTPUT("Closing file.\n");
   err=fclose(fp);
   if ( err!=0 ) OUTPUT("Error message was "); print_fopen_err((int)errno);
  }
 }
 inline void write( size_t size, size_t length, void *val ) {
  if ( !fileok() ) return;
  this->size=fwrite( val, size, length, fp );
  if ( this->size != size*length ) Error(false);
 }
 inline void write( bool *val )           { if ( !fileok() ) return; write(1,val); }
 inline void write( const char *val )     { if ( !fileok() ) return; write(1,val); }
 inline void write( byte *val )           { if ( !fileok() ) return; write(1,val); }
 inline void write( short *val )          { if ( !fileok() ) return; write(1,val); }
 inline void write( unsigned short *val ) { if ( !fileok() ) return; write(1,val); }
 inline void write( int *val )            { if ( !fileok() ) return; write(1,val); }
 inline void write( unsigned int *val )   { if ( !fileok() ) return; write(1,val); }
 inline void write( float *val )          { if ( !fileok() ) return; write(1,val); }
 inline void write( double *val )         { if ( !fileok() ) return; write(1,val); }
 inline void write( size_t length, bool *val )           { if ( !fileok() ) return; size=fwrite( val, sizeof(bool), length, fp );           if ( size != length ) { Error(false); } }
 inline void write( size_t length, const char *val )     { if ( !fileok() ) return; size=fwrite( val, sizeof(char), length, fp );           if ( size != length ) { Error(false); } }
 inline void write( size_t length, byte *val )           { if ( !fileok() ) return; size=fwrite( val, sizeof(byte), length, fp );           if ( size != length ) { Error(false); } }
 inline void write( size_t length, unsigned short *val ) { if ( !fileok() ) return; size=fwrite( val, sizeof(unsigned short), length, fp ); if ( size != length ) { Error(false); } }
 inline void write( size_t length, short *val )          { if ( !fileok() ) return; size=fwrite( val, sizeof(short), length, fp );          if ( size != length ) { Error(false); } }
 inline void write( size_t length, int *val )            { if ( !fileok() ) return; size=fwrite( val, sizeof(int), length, fp );            if ( size != length ) { Error(false); } }
 inline void write( size_t length, unsigned int *val )   { if ( !fileok() ) return; size=fwrite( val, sizeof(unsigned int), length, fp );   if ( size != length ) { Error(false); } }
 inline void write( size_t length, float *val )          { if ( !fileok() ) return; size=fwrite( val, sizeof(float), length, fp );          if ( size != length ) { Error(false); } }
 inline void write( size_t length, double *val )         { if ( !fileok() ) return; size=fwrite( val, sizeof(double), length, fp );         if ( size != length ) { Error(false); } }
 inline void write( Indexed<Zbyte> *values )   { if ( !fileok() ) return; unsigned int length=(unsigned int)(values->length); write(&length); for ( unsigned int i=0; i<length && err!=1; i++ ) { write(&((*values)[i].value)); } }
 inline void write( Indexed<Zushort> *values ) { if ( !fileok() ) return; unsigned int length=(unsigned int)(values->length); write(&length); for ( unsigned int i=0; i<length && err!=1; i++ ) { write(&((*values)[i].value)); } }
 inline void write( Indexed<Zuint> *values )   { if ( !fileok() ) return; unsigned int length=(unsigned int)(values->length); write(&length); for ( unsigned int i=0; i<length && err!=1; i++ ) { write(&((*values)[i].value)); } }
 inline void write( Indexed<Zint> *values )    { if ( !fileok() ) return; unsigned int length=(unsigned int)(values->length); write(&length); for ( unsigned int i=0; i<length && err!=1; i++ ) { write(&((*values)[i].value)); } }
 inline void write( Indexed<Zfloat> *values )  { if ( !fileok() ) return; unsigned int length=(unsigned int)(values->length); write(&length); for ( unsigned int i=0; i<length && err!=1; i++ ) { write(&((*values)[i].value)); } }
 inline void write( Indexed<Zdouble> *values ) { if ( !fileok() ) return; unsigned int length=(unsigned int)(values->length); write(&length); for ( unsigned int i=0; i<length && err!=1; i++ ) { write(&((*values)[i].value)); } }
 inline void write( Zbyte *b )   { write(&(b->value)); }
 inline void write( Zuint *u )   { write(&(u->value)); }
 inline void write( Zint *i )    { write(&(i->value)); }
 inline void write( Zfloat *f )  { write(&(f->value)); }
 inline void write( Zdouble *d ) { write(&(d->value)); }
 inline void write( const Zstring &s ) { write(s.value); }
 inline void write( const string& s ) {
  int length=s.length();
  write(&length);
  write(s.length(),(char *)s.c_str());
 }
 inline void read( string *target ) {
  if ( !fileok() ) return;
  *target=string("");
  int to_read=0;
  read(&to_read);
  for ( int i=0; i<to_read && (err!=1); i++ ) {
   char c;
   read(&c);
   *target+=c;
  }
 }
 inline void read( Zstring *target ) {
  string temp=string("");
  read(&temp);
  (*target)=temp;
 }
 void read( bool *target )                           { if ( !fileok() ) return; bfread(1,target,sizeof(bool));                }
 void read( char *target )                           { if ( !fileok() ) return; bfread(1,target,sizeof(char));                }
 void read( byte *target )                           { if ( !fileok() ) return; bfread(1,target,sizeof(byte));                }
 void read( short *target )                          { if ( !fileok() ) return; bfread(1,target,sizeof(short));               }
 void read( unsigned short *target )                 { if ( !fileok() ) return; bfread(1,target,sizeof(unsigned short));      }
 void read( int *target )                            { if ( !fileok() ) return; bfread(1,target,sizeof(int));                 }
 void read( unsigned int *target )                   { if ( !fileok() ) return; bfread(1,target,sizeof(unsigned int));        }
 void read( float *target )                          { if ( !fileok() ) return; bfread(1,target,sizeof(float));               }
 void read( double *target )                         { if ( !fileok() ) return; bfread(1,target,sizeof(double));              }
 void read( char *target,   size_t length )          { if ( !fileok() ) return; bfread(length,target,sizeof(char));           }
 void read( byte *target,   size_t length )          { if ( !fileok() ) return; bfread(length,target,sizeof(byte));           }
 void read( unsigned short *target,  size_t length ) { if ( !fileok() ) return; bfread(length,target,sizeof(unsigned short)); }
 void read( short *target,  size_t length )          { if ( !fileok() ) return; bfread(length,target,sizeof(short));          }
 void read( unsigned int *target, size_t length )    { if ( !fileok() ) return; bfread(length,target,sizeof(unsigned int));   }
 void read( int *target,    size_t length )          { if ( !fileok() ) return; bfread(length,target,sizeof(int));            }
 void read( float *target,  size_t length )          { if ( !fileok() ) return; bfread(length,target,sizeof(float));          }
 void read( double *target, size_t length )          { if ( !fileok() ) return; bfread(length,target,sizeof(double));         }
 inline void read( Indexed<Zbyte> *values )   { if ( !fileok() ) return; unsigned int length; read(&length); values->Size((size_t)length); for ( unsigned int i=0; i<length && err!=1; i++ ) { read(&((*values)[i].value)); } }
 inline void read( Indexed<Zushort> *values ) { if ( !fileok() ) return; unsigned int length; read(&length); values->Size((size_t)length); for ( unsigned int i=0; i<length && err!=1; i++ ) { read(&((*values)[i].value)); } }
 inline void read( Indexed<Zuint> *values )   { if ( !fileok() ) return; unsigned int length; read(&length); values->Size((size_t)length); for ( unsigned int i=0; i<length && err!=1; i++ ) { read(&((*values)[i].value)); } }
 inline void read( Indexed<Zint> *values )    { if ( !fileok() ) return; unsigned int length; read(&length); values->Size((size_t)length); for ( unsigned int i=0; i<length && err!=1; i++ ) { read(&((*values)[i].value)); } }
 inline void read( Indexed<Zfloat> *values )  { if ( !fileok() ) return; unsigned int length; read(&length); values->Size((size_t)length); for ( unsigned int i=0; i<length && err!=1; i++ ) { read(&((*values)[i].value)); } }
 inline void read( Indexed<Zdouble> *values ) { if ( !fileok() ) return; unsigned int length; read(&length); values->Size((size_t)length); for ( unsigned int i=0; i<length && err!=1; i++ ) { read(&((*values)[i].value)); } }
 inline void read( size_t length, Indexed<Zbyte> *values )   { if ( !fileok() ) return; values->Size(length); for ( unsigned int i=0; i<length && err!=1; i++ ) { read(&((*values)[i].value)); } }
 inline void read( size_t length, Indexed<Zushort> *values ) { if ( !fileok() ) return; values->Size(length); for ( unsigned int i=0; i<length && err!=1; i++ ) { read(&((*values)[i].value)); } }
 inline void read( size_t length, Indexed<Zuint> *values )   { if ( !fileok() ) return; values->Size(length); for ( unsigned int i=0; i<length && err!=1; i++ ) { read(&((*values)[i].value)); } }
 inline void read( size_t length, Indexed<Zint> *values )    { if ( !fileok() ) return; values->Size(length); for ( unsigned int i=0; i<length && err!=1; i++ ) { read(&((*values)[i].value)); } }
 inline void read( size_t length, Indexed<Zfloat> *values )  { if ( !fileok() ) return; values->Size(length); for ( unsigned int i=0; i<length && err!=1; i++ ) { read(&((*values)[i].value)); } }
 inline void read( size_t length, Indexed<Zdouble> *values ) { if ( !fileok() ) return; values->Size(length); for ( unsigned int i=0; i<length && err!=1; i++ ) { read(&((*values)[i].value)); } }
 inline void read( Zbyte *b )   { read(&(b->value)); }
 inline void read( Zuint *u )   { read(&(u->value)); }
 inline void read( Zint *i )    { read(&(i->value)); }
 inline void read( Zfloat *f )  { read(&(f->value)); }
 inline void read( Zdouble *d ) { read(&(d->value)); }

 void bfread( size_t length, void *target, size_t size ) {
  if ( !fileok() ) return;
  clearerr(fp);
  size_t total=length*size;
  size_t read_in=fread(target, size, length, fp);
  if ( read_in != total ) {
   err=1;
   OUTPUT("BinaryFile::bfread(`%s`) warns, fread_s: %d read values did not meet the expected size of %d\n",
    (char *) filename.c_str(), (int) size, (int) length );
   if ( feof(fp) ) {
    end_of_file=true;
    OUTPUT("feof() reports that there was an EOF encountered, ferror() reports %d\n", ferror(fp) );
    OUTPUT("Error message was "); print_fopen_err((int)errno);
   }
   else {
    OUTPUT("ferror() reports %d, errno=%d\n", ferror(fp), (int) errno );
    OUTPUT("Error message was "); print_fopen_err((int)errno);
   }
   OUTPUT("If no EOF detected, possible causes: opening a file for reading when writing or vice versa (calling read or write in the wrong place),\n actual file i/o error, a modicum of other possibilities\n");
  } else
  if ( ferror(fp) != 0 ) {
   OUTPUT("ferror() reports %d, errno=%d\n", ferror(fp), (int) errno );
   OUTPUT("Error message was "); print_fopen_err((int)errno);
  }
  if ( end_of_file ) {
   OUTPUT("Closing file.\n");
   OUTPUT("Error message was "); print_fopen_err((int)errno);
   err=fclose(fp);
  }
 }
};

// the following was written for the #NEVER code below, the CLR version, crapola!!!!!
// you could use this to 'queue' data pointers to be later dumped in one blocking shot.

#include "LinkedList.h"

enum BinaryFileWriteQueueTypes {
 _nulls,
 _bytes,
 _ints,
 _uints,
 _floats,
 _doubles,
 _chars
};

class BinaryFileWriteQueued : public ListItem {
public:
 BinaryFileWriteQueueTypes type;
 byte *bytes;
 int *ints;
 unsigned int *uints;
 float *floats;
 double *doubles;
 char *chars;
 int length;
 BinaryFileWriteQueued() : ListItem() {
  bytes=null;
  ints=null;
  uints=null;
  floats=null;
  doubles=null;
  chars=null;
  length=0;
  type=_nulls;
 }
 void Bytes( byte *data, int length ) {
  this->bytes=data;
  this->length=length;
  type=_bytes;
 }
 void Ints( int *data, int length ) {
  this->ints=data;
  this->length=length;
  type=_ints;
 }
 void UnsignedInts( unsigned int *data, int length ) {
  this->uints=data;
  this->length=length;
  type=_uints;
 }
 void Floats( float *data, int length ) {
  this->floats=data;
  this->length=length;
  type=_floats;
 }
 void Doubles( double *data, int length ) {
  this->doubles=data;
  this->length=length;
  type=_doubles;
 }
 void Chars( const char *data, int length ) {
  this->chars=(char *) data;
  this->length=length;
  type=_chars;
 }
};

class BinaryFileWriteQueue : public LinkedList {
public:
 CLEARLISTRESET(BinaryFileWriteQueued);
 ~BinaryFileWriteQueue() { Clear(); }
 void Bytes( byte *data, int length ) {
  BinaryFileWriteQueued *item=new BinaryFileWriteQueued;
  item->Bytes(data,length);
  Append(item);
 }
 void Ints( int *data, int length ) {
  BinaryFileWriteQueued *item=new BinaryFileWriteQueued;
  item->Ints(data,length);
  Append(item);
 }
 void UnsignedInts( unsigned int *data, int length ) {
  BinaryFileWriteQueued *item=new BinaryFileWriteQueued;
  item->UnsignedInts(data,length);
  Append(item);
 }
 void Floats( float *data, int length ) {
  BinaryFileWriteQueued *item=new BinaryFileWriteQueued;
  item->Floats(data,length);
  Append(item);
 }
 void Doubles( double *data, int length ) {
  BinaryFileWriteQueued *item=new BinaryFileWriteQueued;
  item->Doubles(data,length);
  Append(item);
 }
 void Chars( const char *data, int length ) {
  BinaryFileWriteQueued *item=new BinaryFileWriteQueued;
  item->Chars(data,length);
  Append(item);
 }
};


#if defined(NEVER)

// We don't use this because of the FORMAT() function, because varargs are not supported by CLR,
// and guess what, we used it extensively.

// Source: http://msdn.microsoft.com/en-us/library/67czzkst.aspx
// binary_write.cpp
// compile with: /clr
#using<system.dll>
using namespace System;
using namespace System::IO;

class BinaryFile {
 BinaryFileWriteQueue queue;
 string filename;
 bool open,error;
 BinaryFile() { open=false; error=true; filename=string("tempfile"); }
 BinaryFile( char *filename ) {
  this->filename=string(filename);
  open=true;
  error=false;
 }
 void Write() { 
  FileStream^ fs;
  String^ FileName=gcnew String(filename.c_str());
  if (File::Exists(FileName)) {
   fs = gcnew FileStream(FileName, FileMode::Truncate);
  } else fs = gcnew FileStream(FileName, FileMode::Create);
  BinaryWriter^ w = gcnew BinaryWriter(fs);
  open=true;
  error=false;
  EACH(queue.first,BinaryFileWriteQueued,b) {
   for ( int i=0; !error&&i<b->length; i++ ) {
    switch ( b->type ) {
     case _bytes:
      try { w->Write(b->bytes[i]); } catch (Exception^) {
       OUTPUT("BinaryFile:Write() reports failed to write bytes to `%s`, closing.\n", (char *) filename.c_str() );
       fs->Close();
       error=true;
       open=false;
       return;
      }
      break;
     case _ints:
      try { w->Write(b->ints[i]); } catch (Exception^) {
       OUTPUT("BinaryFile:Write() reports failed to write ints to `%s`, closing.\n", (char *) filename.c_str() );
       fs->Close();
       error=true;
       open=false;
       return;
      }
      break;
     case _uints:
      try { w->Write(b->uints[i]); } catch (Exception^) {
       OUTPUT("BinaryFile:Write() reports failed to write uints to `%s`, closing.\n", (char *) filename.c_str() );
       fs->Close();
       error=true;
       open=false;
       return;
      }
      break;
     case _floats:
      try { w->Write(b->floats[i]); } catch (Exception^) {
       OUTPUT("BinaryFile:Write() reports failed to write floats to `%s`, closing.\n", (char *) filename.c_str() );
       fs->Close();
       error=true;
       open=false;
      }
      break;
     case _doubles:
      try { w->Write(b->doubles[i]); } catch (Exception^) {
       OUTPUT("BinaryFile:Write() reports failed to write doubles to `%s`, closing.\n", (char *) filename.c_str() );
       fs->Close();
       error=true;
       open=false;
       return;
      }
      break;
     case _chars:
      try { w->Write(b->chars[i]); } catch (Exception^) {
       OUTPUT("BinaryFile:Write() reports failed to write chars to `%s`, closing.\n", (char *) filename.c_str() );
       fs->Close();
       error=true;
       open=false;
       return;
      }
      break;
    }
   }
  }
  fs->Close();
  open=false;
  error=false;
  OUTPUT("BinaryFile:Write() wrote the file `%s`\n", (char *) filename.c_str() );
 }
 void Bytes( byte *data, int length ) {
  queue.Bytes(data,length);
 }
 void Ints( int *data, int length ) {
  queue.Ints(data,length);
 }
 void UnsignedInts( unsigned int *data, int length ) {
  queue.UnsignedInts(data,length);
 }
 void Floats( float *data, int length ) {
  queue.Floats(data,length);
 }
 void Doubles( double *data, int length ) {
  queue.Doubles(data,length);
 }
 void Chars( char *data, int length ) {
  queue.Chars(data,length);
 }
 ~BinaryFile() {
 }
};

#endif

// a bunch of  leftover notes that demonstrates several different ways to handle files:


 /* Uses CLR: do not use
 BinaryFile *file;
 file=new BinaryFile(filename);
 file->Bytes( set->randoms, 1000000);
 file->UnsignedInts( set->randomsui, 250000 );
 file->Ints( set->randomsi, 250000 );
 file->Floats( set->randomsf, 250000 );
 file->Floats( set->randomsui, 100000 );
 for ( int i=0; i<100; i++ ) file->Ints( set->rands[i].rands, 100 );
 file->Write();
 delete file;
 */
 /*
 HANDLE hFile = CreateFile(filename, GENERIC_READ|GENERIC_WRITE,
    0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
 SetFilePointer(hFile, GetFileSize(hFile, NULL), NULL, FILE_BEGIN);
 DWORD dwBytes=0;
 BOOL bResult = WriteFile(hFile, set, sizeof(*set), &dwBytes, NULL);
 CloseHandle(hFile);
 */
/*    
 // Source: http://msdn.microsoft.com/en-us/library/windows/desktop/bb540534(v=vs.85).aspx
 HANDLE hFile
  = CreateFile(filename,               // name of the write
               GENERIC_WRITE,          // open for writing
               0,                      // do not share
               NULL,                   // default security
               CREATE_ALWAYS,          // create new file only
               FILE_ATTRIBUTE_NORMAL,  // normal file
               NULL);                  // no attr. template
 
 if (hFile == INVALID_HANDLE_VALUE) 
 { 
     OUTPUT("Randoms::SaveRandom reports CreateFile: Terminal failure: Unable to open file `%s` for write.\n", filename);
     return;
 }

 DWORD dwBytesToWrite;
 DWORD dwBytesWritten = 0;
 
 BOOL bErrorFlag
  = WriteFile(hFile,           // open file handle
              (LPVOID) set,      // start of data to write
              dwBytesToWrite=(DWORD) sizeof(*set),  // number of bytes to write
              &dwBytesWritten, // number of bytes that were written
              NULL);            // no overlapped structure
 
 if (FALSE == bErrorFlag) {
  OUTPUT("Randoms::SaveRandom reports WriteFile: Terminal failure: Unable to write to file.\n");
 } else {
  if (dwBytesWritten != dwBytesToWrite) {
      // This is an error because a synchronous write that results in
      // success (WriteFile returns TRUE) should write all data as
      // requested. This would not necessarily be the case for
      // asynchronous writes.
   // note: this probably means disk full
      OUTPUT("Randoms::SaveRandom reports Error: dwBytesWritten != dwBytesToWrite\n");
  } else {
   OUTPUT("Wrote %d bytes.\n", (int)  dwBytesWritten);
  }
 }
 
 CloseHandle(hFile);
 */
/* FILE *pFile;
 errno_t error=fopen_s(&pFile,filename,"wb");
 if ( error != 0 || !pFile ) {
  OUTPUT("Randoms:SaveRandom() Error! Cannot write '%s'\n",filename);
  return;
 } 
 fwrite(set->randoms,sizeof(byte),1000000,pFile);
 fwrite(set->randomsui,sizeof(unsigned int),250000,pFile);
 fwrite(set->randomsi,sizeof(int),250000,pFile);
 fwrite(set->randomsf,sizeof(float),250000,pFile);
 fwrite(set->resequenced,sizeof(float),100000,pFile);
 for ( int i=0; i<100; i++ )
 fwrite(set->rands[i].rands,sizeof(int),PSEUDORAND_MAX,pFile);
 fclose(pFile); there was even one other way*/
