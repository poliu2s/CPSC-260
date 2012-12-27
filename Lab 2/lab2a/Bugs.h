// File:     Bugs.h
//
// Author:   Kellogg Booth
//
// Modified: 2008 Jan 24
//
// Bugs header file used by all CPSC 260 assignments

#ifndef BUGS_H
#define BUGS_H

#include <iostream>

using namespace std;

void setBugUser( const char* userID=NULL, bool verbose=false  );
/*
*  PRE:  userID is a valid CS undergrad userid
*
*  POST: All subsequent bugs numbers will be determined by
*        the userID parameter if it is not NULL, otherwise
*        the current logged in user name will be used.
*/

void getBugUser( bool verbose=false );
/*
*  PRE:  (none)
*
*  POST: The user is prompted for a userID, which is then
*        passed to setBugUser().
*
*        If verbose is true, the userID that determines the
*        bug mapping will be printed, otherwise nothing is
*        printed.
*/


void setBug( int bug, bool verbose=false );
/*
*  PRE:  bug is a valid bug number for the assignment
*
*  POST: All subsequent method invocations for the class
*        being tested will be conducted in the presence of
*        the specified bug until another one is specified.
*
*        A bug number of zero indicates that no bugs should
*        be present.
*
*        If verbose is true, the userID that determines the
*        bug mapping and the bug number will be printed,
*        otherwise nothing is printed.
*/

void getBug( bool verbose=false );
/*
*  PRE:  (none)
*
*  POST: The user is prompted for a bug number, which is then
*        passed to setBug().
*
*        If verbose is true, the userID that determines the
*        bug mapping and the bug number will be printed,
*        otherwise nothing is printed.
*/

#endif
