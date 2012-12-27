// file: CTimer.h
// CTimer class header file

#ifndef _CTIMER_H
#define _CTIMER_H

// a class that can be used to "time" parts of programs
// or as a general timer
//
// operations are:
//
//     Start() : starts the timer 
//     Stop()  : stops the timer
//     ElapsedTime() : returns the elapsed time between 
//                     start and the last stop
//     CumulativeTime(): returns cumulative total of all
//                      "laps" (timed intervals), i.e., sum of
//                      calls to ElapsedTime
//     Reset()    : resets cumulative time to 0
//                  so "removes" history of timer
//
//

class CTimer
{
  public:
    CTimer();
    // Post: elapased and cumulative times are zero;
    void reset();                     
    // Post: elapsed time has been reset to 0
    void start();
    // Post: timer has been started
    void stop();
    // Post: timer has been stopped
    double elapsedTime();             
    // Post: time between last start/stop has been returned
    double cumulativeTime();          
    // Post: total of all times since last reset has been returned
  
  private:
    long myStartTime;                 // start of current interval
    double myElapsed;                 // time between last start and stop
    double myCumulative;              // sum of all timed intervals
};

#endif      // _CTIMER_H not defined
