// ITP 365 Spring 2017
// HW4 - Wedding Planner
// Name: Mana Mehraein
// Email: mehraein@usc.edu
// Platform: Mac

#pragma once

#include <stdio.h>
#include <iostream>
#include <vector>
#include "HEvent.h"


class HCal
{

private:
    std::vector<HEvent*> Hpointers;

    
    
public:
    // default constructor
    HCal();
    
    //holds a vector of HEvent pointers
    
    //    HCal must have an addEvent function that will add the inputted HEvent pointer to the end of
    //    HEvent pointer vector.
    
    
    // Function: addEvent
    // Purpose: Nwill add the inputted HEvent pointer to the end of HEvent pointer vector.
    // Input: HEvent pointer
    // Output: nothing
    void addEvent(HEvent* Hpts);
    
    
    
    //    HCal should have a getter for the size of the contained vector.
    
    
    // Function: getsize
    // Purpose: HCal should have a getter for the size of the contained vector.
    // Input: nothing
    // Output: the size of the contained vector.
    unsigned long getsize() const;
    
    //    You must have way to access the underlying vector with a get function. It should accept an
    //    unsigned int as input and return a pointer to the appropriate HEvent pointer.
    
    // Function: getsize
    // Purpose: HCal should have a getter for the size of the contained vector.
    // Input: nothing
    // Output: the size of the contained vector.
    HEvent* get(unsigned int input) const;
    
    //    You may add any other functions that will help you along the way.
    //    You should probably test your HCal class by dynamically allocating (with the new keyword)
    //    several HEvent variables and adding them to a HCal. Access the contained HEvents (maybe with a loop) and display the event details.
    
    
    // Function: binarySearchPart
    // Purpose: to do binary search
    // Input: an HEvent pointer, two ints for start and end of search
    // Output: -1 if nothing was found, and the index of event if found
    int binarySearchPart(HEvent* HPoint, int start, int end);
    
};
