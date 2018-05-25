#include <sstream>
#include <iomanip>
//Time is represented as: "5/24/2018 11:40:24 PM"
void syncTimeCommand(String arguments){
  int pivot1 = arguments.indexOf('/');
  int pivot2 = arguments.indexOf('/',pivot1);
  int pivot3 = arguments.indexOf(' ');
  int pivot4 = arguments.indexOf(':');
  int pivot5 = arguments.indexOf(':', pivot4);
  int pivot6 = arguments.indexOf(' ', pivot5);
  int monthS = arguments.substring(0, pivot1-1).toInt();
  int dayS = arguments.substring(pivot1+1, pivot2-1).toInt();
  int yearS = arguments.substring(pivot2+1, pivot3-1).toInt();
  int hourS = arguments.substring(pivot3+1, pivot4-1).toInt();
  int minuteS = arguments.substring(pivot4+1, pivot5-1).toInt();
  int secondS = arguments.substring(pivot5+1, pivot6-1).toInt();
  Serial.println("Time is being set!");
  setTime(hourS, minuteS, secondS, dayS, monthS, yearS);
}
