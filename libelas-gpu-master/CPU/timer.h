/*
Copyright 2011. All rights reserved.
Institute of Measurement and Control Systems
Karlsruhe Institute of Technology, Germany

This file is part of libelas.
Authors: Andreas Geiger

libelas is free software; you can redistribute it and/or modify it under the
terms of the GNU General Public License as published by the Free Software
Foundation; either version 3 of the License, or any later version.

libelas is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with
libelas; if not, write to the Free Software Foundation, Inc., 51 Franklin
Street, Fifth Floor, Boston, MA 02110-1301, USA 
*/

#ifndef __TIMER_H__
#define __TIMER_H__

#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <string>

#ifdef _MSC_VER   // windows VS
#include <stdint.h>
#include <time.h>     
#include<chrono>   
#include <Windows.h>
#else   //  for unix
#include <sys/time.h>  
    typedef __int8            int8_t;
    typedef __int16           int16_t;
    typedef __int32           int32_t;
    typedef __int64           int64_t;
    typedef unsigned __int8   uint8_t;
    typedef unsigned __int16  uint16_t;
    typedef unsigned __int32  uint32_t;
    typedef unsigned __int64  uint64_t;
#endif

class Timer 
{
public:
      Timer() {}
      ~Timer() {}
  
      void start(std::string title);
      void stop();
      void plot();
      void reset();
      void gettimeofday(struct timeval* tv);
  
private:
  
  std::vector<std::string>  desc;
  std::vector<timeval>      time;

  void push_back_time ();
  float getTimeDifferenceMilliseconds(timeval a, timeval b);
};


#endif
