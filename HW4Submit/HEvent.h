// ITP 365 Spring 2017
// HW4 - Wedding Planner
// Name: Mana Mehraein
// Email: mehraein@usc.edu
// Platform: Mac

#pragma once

#include <string>
#include <iostream>



class HEvent
{
public:
    
    // constructor
    HEvent (unsigned long long Epoch, std::string Hname);
    
    
    // Function: getEpoch
    // Purpose: get Epoch
    // Input: nothing
    // Output: Epoch
    unsigned long long getEpoch() const;
    
    
    // Function: getHname
    // Purpose: gets the name
    // Input: nothing
    // Output: name of the event
    std::string getHname() ;
    
    
    // Function: operator overload ==
    // Purpose: operator overload to compare two events
    // Input: two events to compare
    // Output: returns true if they are equal
    friend bool operator == (const HEvent &h1 , const HEvent &h2);
    
    // Function: operator overload !=
    // Purpose: operator overload to compare two events
    // Input: two events to compare
    // Output: returns true if they are not equal
    friend bool operator != (const HEvent &h1, const HEvent &h2);
    
    // Function: operator overload <<
    // Purpose: print date
    // Input: date
    // Output: date
    friend std::ostream& operator << (std::ostream& dateprint, const HEvent& date);
    
    // Function: operator overload <
    // Purpose: operator overload to compare two events
    // Input: two events to compare
    // Output: returns true if first one is smaller than the other
    friend bool operator < (const HEvent &h1 , const HEvent &h2);
    
    // Function: getsize
    // Purpose: operator overload to compare two events
    // Input: two events to compare
    // Output: returns true if first one is bigger than the other
    friend bool operator > (const HEvent &h1 , const HEvent &h2);

    
private:
    
    unsigned long long mEpoch;
    std::string mHname;
    
};

