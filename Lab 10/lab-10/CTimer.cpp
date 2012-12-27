// file: CTimer.cpp
// CTimer class source file

#include "CTimer.h"
#include <ctime>


CTimer::CTimer()
// Post: elapased and cumulative times are zero;
{
    myElapsed = 0.0;
    myCumulative = 0.0;
}

void CTimer::reset()
// Post: elapsed time has been reset to 0
{
    myCumulative = 0.0;
}

void CTimer::start()
// Post: timer has been started
{
    myStartTime = clock();
}

void CTimer::stop()
// Post: timer has been stopped
{
    long myEndTime = clock();

    myElapsed = myEndTime - myStartTime;   // time since last start
    myCumulative += myElapsed;             // add to cumulative time
}
    
double CTimer::elapsedTime()
// Post: time between last start/stop has been returned
{
    return myElapsed / CLOCKS_PER_SEC;
}

double CTimer::cumulativeTime()
// Post: total of all times since last reset has been returned
{
    return myCumulative / CLOCKS_PER_SEC;
}



