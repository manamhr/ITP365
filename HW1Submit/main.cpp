// ITP 365 Spring 2017
// HW1 - Sieve of Eratosthenes
// Name: Mana Mehraein
// Email: mehraein@usc.edu
// Platform: Mac

#include <iostream>
#include "gwindow.h"
#include "sieve.h"
#include <string>
#include "vector.h"
#include "strlib.h"


int main(int argc, char** argv)
{
    
    // Create a 500x500 window
    GWindow gw(500, 500);
    
    Vector<int> number;
    Vector<NumberType> type;
    
    // Call initVectors in main
    initVectors (number, type);
    
    // drawGrid
    drawGrid(gw,number,type);
    
    int index=2;
    
    // loop to find prime numbers and composites
    while (calcNextPrime(number, type, index)!=-1)
    {
        drawGrid(gw,number,type);
        pause(1000.0);
        index++;
        
    }
    
    return 0;
}
