//
// sieve.cpp
// Name: Mana Mehraein
// Email: mehraein@usc.edu
// ITP 365 Spring 2017
// HW1 – Sieve of Eratosthenes
// Platform: Mac
//

#include "sieve.h"
#include <string>
#include "gwindow.h"
#include "strlib.h"


// Function drawSquare

void drawSquare (GWindow& gw, int number, NumberType type, double x, double y)
{
    //    colors for each fill type
    //    NumberType UNKNOWN = "white";
    //    NumberType PRIME = "green";
    //    NumberType COMPOSITE = "red";
    
    
    if (type== UNKNOWN)
    {
        gw.setColor("white");
    }
    
    else if (type==PRIME)
    {
        gw.setColor("green");
    }
    else if (type== COMPOSITE)
    {
        gw.setColor("red");
    }
    
    //    GWindow gw(500, 500);
    int width=50;
    int height=50;
    gw.fillRect(x, y, width, height);
    
    gw.setColor("black");
    gw.drawRect(x, y, 50, 50);
    
    //    gw.setColor("blue");
    std::string num;  // change integer to string to be able to use it as string in drawLable
    num=integerToString(number);
    gw.drawLabel(num, x+25, y+25); // used +25 to put the numbers in the middle of the squares
    
}

//Function initVectors
void initVectors (Vector<int>& number, Vector<NumberType>& type)
{
    for (int i=2; i<=101; i++)
    {
        number.add(i); // add numbers
        type.add (UNKNOWN); // set their types to UNKNOWN
    }
    
}

// Function drawGrid
void drawGrid (GWindow& GW, Vector<int>& number, Vector<NumberType>& type)
{
    int x=0;
    int y=0;
    int i=0;
    while(i<100)
    {
        
        if (x==500) //after going over a row, come to next row, make x=0 and increase y by 50
        {
            
            y+=50;
            x=0;
        }
        while (x<451) //use drawSquare function to make the squares
        {
            
            drawSquare (GW, number[i], type[i], x, y);
            i++;
            x+=50;
        }
    }
    
}



//Function calcNextPrime
int calcNextPrime (Vector<int>& number, Vector<NumberType>& type, int startAt)
{
    
    
    int index=startAt-2;
    int prime=-1; // in order to return -1 in case there is no prime number is left
    if(index<number.size()) // in order for the loop not to go over grid 101
    {
        while (type[index]!=UNKNOWN) // while loop to go over all grids
        {
            index++;
            if(index>=number.size())
            {
                break; //to break out of the loop
            }
        }
        
        
        if(index<number.size())
        {
            type[index]=PRIME; // finding the prime numbers and change the type to prime
            prime=number[index];
            while (index<number.size())
            { // find the multiples of prime numbers and make their types equal to composite
                index+=prime;
                if(index<number.size()){
                    type[index]=COMPOSITE;
                }
                
            }
        }
    }
    
    return prime;
}




