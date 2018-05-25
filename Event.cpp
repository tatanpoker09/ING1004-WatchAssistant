#include <Time.h>
#include <TimeLib.h>

#include "Event.h"

Event::Event(int yearS2, int monthS2, int dayS2, int hourS2, int minuteS2, int secondS2, int yearE2, int monthE2, int dayE2, int hourE2, int minuteE2, int secondE2, float offsetMinute2, float offsetStart2){
    dayS = dayS2;
    hourS = hourS2;
    minuteS = minuteS2;
    secondS = secondS2;
    dayE = dayE2;
    hourE = hourE2;
    minuteE = minuteE2;
    secondE = secondE2;
    offsetMinute = offsetMinute2;
    offsetStart = offsetStart2;
 }
 
 
 void Event::lowTime(){
 
 }
 
 void Event::finishEvent(){
 
 }
 void Event::startEvent(){
 
 }
