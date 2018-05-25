class Event{
  private:
   int dayS;
   int hourS;
   int minuteS;
   int secondS;
   
   float offsetMinute; //How many minutes before the actual event time, the "low time" arises.
   float offsetStart;
   int dayE;
   int hourE;
   int minuteE;
   int secondE;
   
 public:
   Event(int yearS, int monthS, int dayS, int hourS, int minuteS, int secondS, int yearE, int monthE, int dayE, int hourE, int minuteE, int secondE, float offsetMinute, float offsetStart);
   void lowTime();
   void finishEvent();
   void startEvent();
   void currentTime();
};
