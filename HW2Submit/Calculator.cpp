// ITP 365 Spring 2017
// HW2 – itpPhone
// Name: Mana Mehraein
// Email: mehraein@usc.edu
// Platform: Mac
//
// Calculator.cpp
// Implements Calculator class
//

#include "Calculator.h"

// Function: Constructor
// Purpose: Does nothing
Calculator::Calculator()
{
    
}

// Function: pushNum
// Purpose: Pushes number onto the stack
// Input: number to push
// Output: None
void Calculator::pushNum(int number)
{
    myStack.push(number);
}

// Function: peekTop
// Purpose: Returns the number on top of the stack
//          (provided the stack is not empty)
// Input: None
// Output: Number on top of the stack
int Calculator::peekTop()
{
    
    //if not empty
    if (!myStack.isEmpty())
    {
    
    int top=myStack.peek();
    
    return top; // FIX TO RETURN CORRECT VALUE
    }
    return 0;
}

// Function: doCalc
// Purpose: Performs the requested arithmetic,
//          provided there are two numbers on the stack.
//          Then pushes the result onto the stack.
//          Silently fails if the stack has less than two
//          numbers on it.
// Input: Type of arithmetic to perform
// Output: None
void Calculator::doCalc(CalcType type)
{
    if (myStack.size()>=2)   //// work on this
    {
        
        //peek
        int x = myStack.peek();
        //pop
        myStack.pop();
        int y= myStack.peek();
        myStack.pop();
        int result=0;
        // do calculations
        if (type==ADD)
        {
            result=y+x;
        }
        else if (type==SUB)
        {
            result=y-x;
        }
        else if (type==MUL)
        {
            result=y*x;
        }
        else if (type==DIV)
        {
            result=y/x;
        }
        
        // push the result
        myStack.push(result);
        
    }
    
    // else do nothing
    else
    {
        
    }
    
    
}
