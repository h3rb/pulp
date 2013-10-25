#pragma once

#include <sys/time.h>
#include "ListItem.h"
#include "TimeKeeper.h"

class Time : public ListItem {
public:
 Zint dow,doy,day,year,month,hour,min,sec;
 Time() : ListItem() {
  Now();
 }
 Time( Time *t ) : ListItem() { Set(t); }
 void Set ( Time *t ) {
  dow=t->dow;
  doy=t->doy;
  day=t->day;
  year=t->year;
  month=t->month;
  hour=t->hour;
  min=t->min;
  sec=t->sec;
 }
 void Set( int wd, int yd, int d, int y, int mo, int h, int m, int s ) {
  dow=wd;
  doy=yd;
  day=d;
  year=y;
  hour=h;
  min=m;
  sec=s;
 }
 void Now() {
  sec=timekeeper.local->tm_sec;
  min=timekeeper.local->tm_min;
  hour=timekeeper.local->tm_hour;
  day=timekeeper.local->tm_mday;
  dow=timekeeper.local->tm_wday;
  doy=timekeeper.local->tm_yday;
  month=timekeeper.local->tm_mon+1;
  year=timekeeper.local->tm_year;
 }
 string Formatted() {
  return FORMAT(buf,1024, "%s%s%d%s, %d at %d:%02d:%02d",
   (int) dow == 0 ? "Sunday " :
   (int) dow == 1 ? "Monday " :
   (int) dow == 2 ? "Tuesday " :
   (int) dow == 3 ? "Wednesday " :
   (int) dow == 4 ? "Thursday " :
   (int) dow == 5 ? "Friday " :
   (int) dow == 6 ? "Saturday " : "",
   (int) month == 0 ? "January " :
   (int) month == 1 ? "February " :
   (int) month == 2 ? "March " :
   (int) month == 3 ? "April " :
   (int) month == 4 ? "May " :
   (int) month == 5 ? "June " :
   (int) month == 6 ? "July " :
   (int) month == 7 ? "August " :
   (int) month == 8 ? "September " :
   (int) month == 9 ? "October " :
   (int) month == 10 ? "November " :
   (int) month == 11 ? "December " : "",
   (int) day,
   (int) day == 1 ? "st" :
   (int) day == 2 ? "nd" :
   (int) day == 3 ? "rd" :
   (int) day == 4 ? "th" :
   (int) day == 21 ? "st" :
   (int) day == 22 ? "nd" :
   (int) day == 23 ? "rd" :
   (int) day == 24 ? "th" :
   (int) day == 25 ? "th" :
   (int) day == 26 ? "th" :
   (int) day == 27 ? "th" :
   (int) day == 28 ? "th" :
   (int) day == 29 ? "th" :
   (int) day == 30 ? "th" :
   (int) day == 31 ? "st" : "",
   (int) year,
   (int) hour,
   (int) min,
   (int) sec
  );
 }
 string toString() {
  return FORMAT(buf,1024,"dow %d doy %d day %d year %d month %d hour %d min %d sec %d",
   (int) dow,
   (int) day,
   (int) year,
   (int) month,
   (int) hour,
   (int) min,
   (int) sec
  );
 }
 void fromString( const char *s ) {
  const char *in=s;
  string one=string("");
  while ( *in != '\0' ) {
   in=string_argument(in,&one);
   if ( !str_cmp(one.c_str(),"dow") ) {
    in=string_argument(in,&one);
    dow=atoi(one.c_str());
   } else if ( !str_cmp(one.c_str(),"doy") ) {
    in=string_argument(in,&one);
    doy=atoi(one.c_str());
   } else if ( !str_cmp(one.c_str(),"day") ) {
    in=string_argument(in,&one);
    day=atoi(one.c_str());
   } else if ( !str_cmp(one.c_str(),"year") ) {
    in=string_argument(in,&one);
    year=atoi(one.c_str());
   } else if ( !str_cmp(one.c_str(),"month") ) {
    in=string_argument(in,&one);
    month=atoi(one.c_str());
   } else if ( !str_cmp(one.c_str(),"hour") ) {
    in=string_argument(in,&one);
    hour=atoi(one.c_str());
   } else if ( !str_cmp(one.c_str(),"min") ) {
    in=string_argument(in,&one);
    min=atoi(one.c_str());
   } else if ( !str_cmp(one.c_str(),"sec") ) {
    in=string_argument(in,&one);
    sec=atoi(one.c_str());
   }
  }
 }
};

extern Time boot;
