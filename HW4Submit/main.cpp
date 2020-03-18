// ITP 365 Spring 2017
// HW4 - Wedding Planner
// Name: Mana Mehraein
// Email: mehraein@usc.edu
// Platform: Mac

#include <iostream>
#include <stdio.h>
#include <vector>
#include "HEvent.h"
#include "HCal.h"
#include "dateconv.h"
#include <fstream>
#include "vector.h"


// Function: loadCal
// Purpose: This function will read in the .csv file, create the appropriate holiday events, and load them into a calendar
// Input: string for filename
// Output: a pointer to the HCal when your function is done
HCal* loadCal (std::string& fileName)
{
    //This function will read in the .csv file, create the appropriate holiday events, and load them into a calendar.
    //Notice that the files have the holidays listed in chronological order.
    //Your function must process a text file by reading in the file and dynamically creating an HEvent for each line of data in the file. Each of the new HEvents should be added to the end of a new a new HCal you’ve also created dynamically.
    //Return a pointer to the HCal when your function is done.
    std::ifstream file(fileName);
    HCal* Hptr=new HCal;
    if (file.is_open())
    {
        while (!file.eof())
        {
            
            std::string line;
            std::getline(file, line);
            //            std::cout << "just got \""<< line << "\"" <<std::endl; //close the quote
            //            std::string clearwhitespc =trim(line); //Remove leading / triming whitespace
            
            if ( line. find("0") !=std::string::npos)
            {
                std::string delimiter = ",";
                
                //            make a vector to split two parts with a comma
                //get a line, determine if it is good line, (remove first and last)
                //get the first field Epoch sec and last field which is the holiday
                //make a new HEvent on the heap and add that memory address to the HCal using addEvent function
                Vector<std::string> sec = stringSplit(line, delimiter);
                unsigned long long number = 0;
                std::string epochTimeString = sec[0];
                number = std::stoull(epochTimeString);
                HEvent* HVpoint=new HEvent(number, sec[2]);
                Hptr->addEvent(HVpoint);
            }
        }
        
    }
    // file not found
    else
    {
        std::cout << " File could not be openned!"<< std::endl;
    }
    
    //delete Hptr;
    //returns a pointer to a HCal
    return Hptr;
}


// Function: mergeFunction
// Purpose: Now we need to put all the Brazilian, Chinese, and US calendars together. To do this, we’ll merge calendars – 2 at a time – into a new calendar with a merge function.
// Input: It should accept 2 HCals (a pointer to HCal A and a pointer to HCal B)
// Output: a new HCal (returned as a pointer)
HCal* mergeFunction (HCal* A, HCal* B)
{
    //    1. Dynamically create a new HCal. This will be the value we return. It will be called HCal C.
    HCal* C=new HCal();
    //    2. Create indexes for each of the 2 inputted calendars. Index i will be used to count
    //        through HCal A and index j will be used to count through HCal B.
    int i=0;
    int j=0;
    
    //    3. Create a loop that executes while i and j are within range (before the ends of their respective calendars).
    while (i<A->getsize() && j<B->getsize() )
    {
        //    1. If the HEvent at A[i] occurs before the HEvent at B[j] add A[i] to the end of C.
        if(*(A->get(i)) < *(B->get(j)))
            
        {
            C -> addEvent(A->get(i));
            //        2. Then increment i.
            i++;
        }
        //        3. Otherwise add the event at B[j] to the end of C.
        else
        {
            C -> addEvent(B->get(j));
            //     4. Then increment j.
            j++;
        }
        
    }
    //    4. When the above loop is over there will be a portion of either A or B left over (it hasn’t been added to C). If A has items remaining, add them to the end of C. If B has items remaining add them to the end of C.
    
    if (i<A->getsize()+1)
    {
        for (int g=i; g<A->getsize(); g++)
        {
        C -> addEvent(A->get(g));
        }
    }
    else if (j<B->getsize()+1)
    {
        for (int g=j; g<B->getsize(); g++)
        {
        C -> addEvent(B->get(g));
        }
    }
    
    
    return C;
}

int main(int argc, char** argv)
{
    bool quit = false;
    //Read in all the data files and create a merged calendar for 2017 for all 3 countries.
    
    std::string fileNameA = "BRholiday2016.csv";
    std::string fileNameB = "CHholiday2016.csv";
    std::string fileNameC = "USholiday2016.csv";
    HCal* A=loadCal (fileNameA);
    HCal* B=loadCal (fileNameB);
    HCal* C=loadCal (fileNameC);
    
    
    HCal* m1=mergeFunction ( A, B);
    HCal* m2=mergeFunction ( m1, C);
    
    
    while (!quit) {
        
        std::string choice;
        std::cout << " Welcome to the wedding planner!" << std::endl;
        std::cout << " You can enter q anytime to quit!" << std::endl;
        std::cout << " Please enter a date (MM/DD/YYYY): " << std::endl;
        std::cin >> choice;
        std::cin.ignore();
        
        if (choice == "q" || choice == "Q") // for quitting
        {
            std::cout << "Quitting!" << std::endl;
            quit = true;
            return 0;
        }
        std::string EpochChange= choice;
        // converting dates and Epoch
        int index=(int)EpochChange.find("/",0);
        int index2=(int)EpochChange.find("/",index+1);
        
        int month= stringToInteger(EpochChange.substr(0,index));
        int day=stringToInteger(EpochChange.substr(index+1,index2));
        int year=stringToInteger(EpochChange.substr(index2+1));
        
        // change to GMT + daylight saving
        if (EpochChange >= "1457870400" && EpochChange< "1478433600")  //3/13-11/6
//        if (month>=4 && month <11)
        {
            unsigned long long date=(getEpochSecs(month,day,year))-25200;
            //Create a new HEvent object and use the search function in HCal to see if an event occurs the
            //    date in question.

            HEvent* Hpoint= new HEvent(date,"user_input");
            int srch= m2->binarySearchPart(Hpoint, 0, (int)m2->getsize()-1);

            //    Inform the user of what holiday occurs on the selected date (or if the date is available).
            //    If the user enters “q” or “Q” quit the program.

            if (srch == -1) // if not found
            {
                std::cout << "That’s a great day for a wedding! " << std::endl;
                std::cout << std::endl;

            }

            else if ( srch!=-1) // if found a holiday
            {

                std::cout << choice << " is " << m2->get(srch)->getHname() << std::endl;
                std::cout << std::endl;

            }


        }
        else // rest of the months
        {
            unsigned long long date=(getEpochSecs(month,day,year))-25200-3600;
            //Create a new HEvent object and use the search function in HCal to see if an event occurs the
            //    date in question.

            HEvent* Hpoint= new HEvent(date,"user_input");
            int srch= m2->binarySearchPart(Hpoint, 0, (int)m2->getsize()-1);

            //    Inform the user of what holiday occurs on the selected date (or if the date is available).
            //    If the user enters “q” or “Q” quit the program.

            if (srch == -1) // if didn't find a holiday
            {
                std::cout << "That’s a great day for a wedding! " << std::endl;
                std::cout << std::endl;
            }

            else if ( srch!=-1) //if found a holiday
             
            {

                std::cout << choice << " is " << m2->get(srch)->getHname() << std::endl;
                std::cout << std::endl;

            }

        }
        
    }
    return 0;
}
