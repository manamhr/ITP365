// ITP 365 Spring 2017
// HW4 - Wedding Planner
// Name: Mana Mehraein
// Email: mehraein@usc.edu
// Platform: Mac

#include "HEvent.h"
#include <stdio.h>
#include <vector>
#include <iostream>
#include "dateconv.h"

//constructor
HEvent::HEvent(unsigned long long Epoch, std::string Hname)

{
    mEpoch=Epoch;
    mHname=Hname;
}

//Function: getEpoch()
unsigned long long HEvent::getEpoch() const
{
    return mEpoch;
}

//Function:getHname
std::string HEvent::getHname() 
{
    return mHname; 
}
//Function: operator overload ==
bool operator == (const HEvent &h1, const HEvent &h2)
{
    return (h1.mEpoch == h2.mEpoch);
}
//Function: operator overload !=
bool operator != (const HEvent &h1, const HEvent &h2)
{
    return !(h1==h2);
}
//Function: operator overload <<
std::ostream& operator << (std::ostream& dateprint, const HEvent& date)
{
    dateprint << date.mEpoch <<":" << date.mHname;
    // dateprint << getMonth(date.mEpoch) << "/" << getMonthDay(date.mEpoch) << "/" << getYear(date.mEpoch);
    return dateprint;
}
//Function: operator overload <
bool operator < (const HEvent &h1 , const HEvent &h2)
{
    return (h1.mEpoch < h2.mEpoch);

}
//Function: operator overload >
bool operator > (const HEvent &h1 , const HEvent &h2)
{
    return (h1.mEpoch > h2.mEpoch);
    
}


