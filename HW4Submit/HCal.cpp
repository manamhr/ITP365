// ITP 365 Spring 2017
// HW4 - Wedding Planner
// Name: Mana Mehraein
// Email: mehraein@usc.edu
// Platform: Mac

#include "HCal.h"
#include <iostream>
#include <vector>


HCal::HCal()
{}

//Function: getsize
unsigned long HCal::getsize() const
{
    return Hpointers.size();
}


//    HCal must have an addEvent function that will add the inputted HEvent pointer to the end of
//    HEvent pointer vector.

//Function: addEvent
void HCal::addEvent(HEvent* Hpts)
{
    Hpointers.push_back(Hpts);
}

//    You must have way to access the underlying vector with a get function. It should accept an
//    unsigned int as input and return a pointer to the appropriate HEvent pointer.

//Function: get
HEvent* HCal::get(unsigned int input) const
{
    return Hpointers[input];
}

//Function: binarySearchPart
int HCal::binarySearchPart( HEvent* HPoint, int start, int end)
{
    if (end < start)
    {
    return -1;
        
    }
    
    int middleIndex = (end + start) / 2;
    
    if (*Hpointers[middleIndex] == *HPoint)   //deference, do that on the merge too check?????????????????????? * or ->
    {
        return middleIndex;
    }
    if ((*Hpointers[middleIndex]) > *HPoint) // check dereference ?????????????
    {
        // Binary search the first half
        return binarySearchPart(HPoint, start, middleIndex - 1);
    }
    else
    {
        // Binary search the second half
        return binarySearchPart(HPoint, middleIndex + 1, end);
    
    }
    
}
