// Step 3 and 4 of Lab 3b



// file: rpnCalculator.cpp
// Simple RPN Calculator
// This is an in-lab exercise and is incomplete

#include <iostream>    // used in main()
#include <cctype>
#include <stack>
#include "Complex.h"

using namespace std;

// ====== MODIFY THE NEXT LINE DURING STEPS 3 & 4 OF LAB ===========
typedef Complex rpnType;

bool isOperator( char nextChar );
// Post: returns true if nextChar is an arithmetic operator; false otherwise

int opSize( char nextOperation );
// Pre:  nextOperation is a valid binary operand
// Post: number of operands required is returned
//       been pushed onto stack

// ====== ADD ONE LINE HERE DURING STEP 4 OF LAB ===================
template <typename valueType>

void doOp( stack< valueType >& operands, char nextOperation );
// Pre: nextOperation is a valid binary operand and size of operands stack is at least 2
// Post: operation has been applied to first two operands popped from stack and result has
//       been pushed onto stack

// ====== ADD ONE LINE HERE DURING STEP 4 OF LAB ===================
template <typename valueType>

void displayStack( stack< valueType >& operands );
// Post: operands stack has been displayed on screen in order in which items were
//       pushed onto stack; "No operands in stack" printed if stack is empty

int main()

   // Simple interactive RPN calculator
   // Library facilities used: cin, cout, peek(), ignore() from iostream
   //                          isdigit() from cctype
   //                          stack, push(), top(), pop() from the STL
{
    const char SHOWSTACK = ':';     // show stack operator
// ====== MODIFY THE NEXT LINE DURING STEP 4 OF LAB ================
    stack< rpnType > operands;       // stack of operands

// ====== MODIFY THE NEXT LINE DURING STEP 4 OF LAB ================
    rpnType nextNumber;
    char   nextOperation;

    cout << "Type \"ctrl-Z\" (\"ctrl-D\" on Unix) to terminate\n";

    while ( cin.peek() != EOF )
    {
        if( isdigit( cin.peek() ) )
        {
            cin >> nextNumber;
            operands.push( nextNumber );
        }
        else if( isOperator( cin.peek() ) )
        {
            cin >> nextOperation;

            // handle unary minus
            if ( isdigit( cin.peek() ) || cin.peek() == '.' )
            {
                cin.putback( nextOperation );
                cin >> nextNumber;
                operands.push( nextNumber );   // unary minus is handled by input
            }
            // do binary operation
            else if ( operands.size() < opSize( nextOperation ) )
            {
                cout << "Not enough operands for " << nextOperation << "\n";
            }
            else
            {
                doOp( operands, nextOperation );

                cout << "-----\n";
                cout << operands.top() << "\n\n";
            }
        }
        else if( cin.peek() == SHOWSTACK )
        {
            // display stack operation
            cin >> nextOperation;           // remove ':' from input stream
            displayStack( operands );        
        }
        else
        {
             cin.ignore();
        }
    }

    // report errors
    if ( operands.size() > 1 )
    {
      cout << "Left over operands on the stack\n";
      return -1;
    }

    return 0;    // normal exit code
}


bool isOperator( char nextChar )
// Post: returns true if nextChar is an arithmetic operator; false otherwise
{
    return( nextChar == '+' || nextChar == '-' || nextChar == '*' || nextChar == '/' || nextChar == '~'
// ====== ADD LINES HERE DURING STEP 2 OF LAB ======================
         || nextChar == '#');
}


int opSize( char nextOperation )
// Pre:  nextOperation is a valid binary operand
// Post: number of operands required is returned
//       been pushed onto stack
{
    switch ( nextOperation )
    {
    case '+':
    case '-':
    case '*':
    case '/':
       return 2;
    case '#':
// ====== ADD LINES HERE DURING STEP 3 OF LAB ======================
	case '~':   
		return 1;
    }
}


// ====== ADD ONE LINE HERE DURING STEP 4 OF LAB ===================
template <typename valueType>

void doOp( stack< valueType >& operands, char nextOperation )
// PRE:  nextOperation is a valid binary operand and size of the operands stack
//       is at least 2,
//       or nextOperaton is a valid unary operand and the size of the operands
//       stack is at least 1.
// POST: operation has been applied to first two operands popped from stack and result has
//       been pushed onto stack
// ====== ADD LINES TO THIS FUNCTION DURING STEPS 2 & 3 OF LAB =====
{
    valueType leftOperand;
    valueType rightOperand;

    rightOperand = operands.top();
    operands.pop();
    if ( opSize( nextOperation ) == 2 )
    {
       leftOperand = operands.top();
       operands.pop();
    }

    switch ( nextOperation )
    {
    case '+':
       operands.push( leftOperand + rightOperand );
       break;
    case '-':
       operands.push( leftOperand - rightOperand );
       break;
	case '*':
		operands.push( leftOperand * rightOperand );
		break;
	case '/':
		operands.push( leftOperand / rightOperand );
		break;
    case '#':
       operands.push( - rightOperand );
       break;
	case '~':
	   double tempImag1 = rightOperand.getImag();
	   double tempReal1 = rightOperand.getReal();
	   tempReal1 = -tempReal1;
	   rightOperand.setComplex( tempReal1, tempImag1 );

	   operands.push( - rightOperand );
	   break;
    }
}

// ====== ADD ONE LINE HERE DURING STEP 4 OF LAB ===================
template <typename valueType>

void displayStack( stack< valueType >& operands )
// Post: operands stack has been displayed on screen in order in which items were
//       pushed onto stack; "No operands in stack" printed if stack is empty
// Note: at the end of the function call the operands stack must have the same state 
//       as it did at the start of the function call!
{
// ====== ADD LINES HERE DURING STEP 2 OF LAB ======================
	if (operands.empty()) cout << "No operands in the stack" << endl;

	stack< valueType> tempStack;
	tempStack = operands;

	while(!tempStack.empty()) {
		cout << "Operand: "<< tempStack.top() << endl;
		tempStack.pop();
	}

}
