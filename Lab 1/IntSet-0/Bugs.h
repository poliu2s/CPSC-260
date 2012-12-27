// File: Bugs.h
//
// Author:   Kellogg Booth     *** Your name ALWAYS goes here
//           12345678          *** Your ID number ALWAYS goes here
//           ksbooth           *** Your userID ALWAYS goes here
//           L20               *** Your lab section ALWAYS goes here
//
// Modified: 2008 January 11   *** Add a new date if you modify the file!
//           2007 January 15
//
// CPSC 260 Bug generation header file

#ifndef BUGS_H
#define BUGS_H

#include <exception>
#include <stdexcept>

void setBug( int bug, bool verbose=true );
//
//  Specify which bug is to be in effect for subsequent invocations
//  of the class being tested.
//
//  PRE:   0<=bug<=BUGS  (the parameter must specify an existing bug)
//
//  POST:  Any bug that is currently in effect will be cancelled.
//
//         If bug=0, no bugs will be put into effect
//
//         If 0<bug<=BUGS, the specified bug will be put into effect
//         for all subsequent invocations of any method in the class being
//         tested.  The bug will remain in effect until the next invocation
//         of setBug().
//
//         If verbose=true, a multi-line text message will be sent to cout
//         indicating the userid of the invoking program and the bug that
//         was specified. No message is produced if verbose=false.

void getBug(bool verbose=true);
// 
// Request a bug number from the user, and call setBug with this number.
//

#endif
