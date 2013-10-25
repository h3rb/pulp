#pragma once

#include <sys/time.h>
#include "ZeroTypes.h"

class TimeKeeper {
public:
 struct tm *local;
 timeval now,then,delta;
 Zint micros;
 time_t t;
 Zstring timeString;
 Zdouble ms;
 Zdouble frame,elapsed;
 Zbool error;
 string error_message;
 TimeKeeper() {
  gettimeofday(&then,NULL);
  t=time(NULL);
  timeString=string(ctime(&t));
  local=localtime(&t);
 }
 void Between() {
  t=time(NULL);
  timeString=string(ctime(&t));
  local=localtime(&t);
  if ( error ) return;
  gettimeofday(&now,NULL);
  timersub(&now,&then,&delta);
  int micros_this_frame=(int)delta.tv_usec;
  micros+=micros_this_frame;
  ms.value=((double)micros_this_frame/1000.0)
        + (delta.tv_sec>0 ? (double)(int)delta.tv_sec*1000.0 : 0.0)
        ;
  while ( micros > 1000 ) { elapsed +=0.001; micros-=1000; }
  frame=ms/1000.0;
  then=now;
/*
  OUTPUT("TimeKeeper: tv_usec=%f ms=%f micros_this_frame=%d, micros=%d, tv_sec=%f elapsed=%f frame=%f\n",
   (double) delta.tv_usec,
   (double) ms,
   (int) micros_this_frame,
   (int) micros,
   (double) delta.tv_sec,
   (double) elapsed,
   (double) frame );
 */
 }
};

extern TimeKeeper timekeeper;
