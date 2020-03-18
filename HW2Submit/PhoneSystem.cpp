// ITP 365 Spring 2017
// HW2 – itpPhone
// Name: Mana Mehraein
// Email: mehraein@usc.edu
// Platform: Mac
//
// PhoneSystem.cpp
// Implements PhoneSystem class
//

#include "PhoneSystem.h"
#include <fstream>

// Function: Constructor
// Purpose: Constructs two maps --
//          (1) area codes -> locations
//              (loaded from areacodes.txt)
//          (2) phone numbers -> contacts
//              (loaded from contacts.txt)
// Input: None
// Output: None
PhoneSystem::PhoneSystem()
{
    std::ifstream fileInput1("areacodes.txt");
    if (fileInput1.is_open())
    {
        // Continue looping as long as not at EOF!
        while (!fileInput1.eof() )
        {
            
            std::string str1;
            std::getline(fileInput1, str1);
            // using stringSplit
            //both works!
//                        std::string delimiter1 = "|";
//                        //int number = 0;
//                        //make a vector to split two parts with a comma
//                        Vector<std::string> name = stringSplit(str1, delimiter1);
//            
//                        mAreaCode[name[0]]=name[1];
            
            // seperating area int and string of area code text file and make mAreaCode based on that
            std::string area=str1.substr(0,3);
            std::string value1 = str1.substr(4);
            mAreaCode[area]=value1;
            
        }
    }
    else
    {
        error("Sorry file does not exists!!");
    }
    
    std::ifstream fileInput2("contacts.txt");
    if (fileInput2.is_open())
    {
        // Continue looping as long as not at EOF!
        while (!fileInput2.eof() )
        {
            
            std::string str2;
            std::getline(fileInput2, str2);
            //            std::string delimiter2 = "|";
            //            //int num = 0;
            //            //make a vector to split two parts with a comma
            //            Vector<std::string> contact = stringSplit(str2, delimiter2);
            //            mPhoneNum[contact[0]]=contact[1];
            
            // seperating phone numbers and names tin ext file and make mPhoneNum based on that

            std::string phoneNum = str2.substr(0,12);
            std::string value2 = str2.substr(13);
            mPhoneNum[phoneNum]=value2;
            //            std::cout << mPhoneNum.toString();
            
        }
        //         std::cout << mPhoneNum.toString();
    }
    // in case the file does not exist and is relocared
    else
    
    {
        error("Sorry file does not exists!!");
    }
//    std::cout<<mPhoneNum<<std::endl;
//    std::cout<<mAreaCode<<std::endl;
    
    
}

// Function: addDigit
// Purpose: Called when the user adds a digit
//          to the current phone number
// Input: Digit to add (to the end of the number)
// Output: None
void PhoneSystem::addDigit(char digit)
{
    // TODO: Implement
    if (mCurrPhone.size() < 12)
    {
        //adds each digit to mCurrPhone
        mCurrPhone+=digit;
        
        // adds - between numbers for better readability
        if (mCurrPhone.length()==3 )
        {
            mCurrPhone+= "-";
        }
        
        if (mCurrPhone.length()==7 )
        {
            mCurrPhone+= "-";
        }
        
        
    }
    
}

// Function: backspace
// Purpose: Removes the rightmost digit from the number
// Input: None
// Output: None
void PhoneSystem::backspace()
{
    
    if (mCurrPhone.size() != 0)
    {
        mCurrPhone.pop_back();
    }
    //removing hyphens to find area code
    if (mCurrPhone.size() == 4)
    {
        mCurrPhone.pop_back();
    }
    if (mCurrPhone.size() == 8)
    {
        mCurrPhone.pop_back();
    }
    
    
}

// Function: getNumber
// Purpose: Returns the current number the user has dialed
// Input: None
// Output: Current number user has dialed
std::string PhoneSystem::getNumber()
{
    
    return mCurrPhone; // FIX TO RETURN CORRECT VALUE
}

// Function: lookupNumber
// Purpose: Looks up the current number in the two maps:
//          (1) First checks if this number is a contact
//          (2) Otherwise, checks if the first three digits
//              are a known area code
// Input: None
// Output: Returns a string that contains either:
//         (a) The name of the contact
//         (b) The location of the area code
//         (c) "UNKNOWN" if it's neither a contact nor
//             contains a valid area code
std::string PhoneSystem::lookupNumber()
{
//    std::cout<<mCurrPhone<<std::endl;
//    std::cout<<mCurrPhone.substr(0,3)<<std::endl;
    if ( mPhoneNum.containsKey(mCurrPhone))
    {
        return mPhoneNum[mCurrPhone];
    }
    // only get the three first numbers for the area code
    else if (mAreaCode.containsKey(mCurrPhone.substr(0,3)))
    {
        return mAreaCode[mCurrPhone.substr(0,3)];
    }
    else
    {
        return "UNKNOWN"; // FIX TO RETURN CORRECT VALUE
    }
}
