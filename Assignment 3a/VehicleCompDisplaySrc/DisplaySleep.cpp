
#include <Windows.h>

// Author:  Donald Acton
// Date: October 9, 2009
// Revised: October 9, 2009
// File: DisplaySleep.cpp



// Pre-condition - takes as an argument the amount of time, in milliseonds,
//                 to sleep this thread for.
// Post-condition - sleeps for the specified time


void DisplaySleep(int duration) {
	Sleep(duration);
}