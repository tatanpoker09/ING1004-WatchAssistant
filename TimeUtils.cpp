#include "TimeUtils.h"

bool isBefore(int day1, int hour1, int minute1, int second1, int day2, int hour2, int minute2, int second2){
  if(day1<day2) return true;
  if(hour1<hour2) return true;
  if(minute1<minute2) return true;
  if(second1>second2) return true;
  return false;
}
bool isAfter(int year1, int month1, int day1, int hour1, int minute1, int second1, int year2, int month2, int day2, int hour2, int minute2, int second2){
  if(day1>day2) return true;
  if(hour1>hour2) return true;
  if(minute1>minute2) return true;
  if(second1>second2) return true;
  return false;
}
void takeFrom(int *monthS, int *dayS, int *hourS, int *minuteS, int *secondS, float minutesTaken){
  int minutes = (int)minutesTaken;
  int seconds = (minutesTaken-minutes)*60;
  
  if(*secondS<seconds){
    int over = seconds-*secondS;
    *secondS = (60-over);
    *minuteS --;
    if(*minuteS<0){
      *minuteS = 60;
      *hourS--;
    }
  } else {
    *secondS -= seconds; 
  }
  
  if(*minuteS<minutes){
    int over = minutes-*minuteS;
    *minuteS = 60-over;
    *hourS--;
    if(*hourS<0){
     *hourS = 23;
     *dayS--;
     if(*dayS<0){
       *dayS = 30;
        *monthS--; 
     }
    }
  } else {
    *minuteS -=minutes;
  }
}

