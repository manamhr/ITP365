//
// sieve.h
// Name: Mana Mehraein
// Email: mehraein@usc.edu
// ITP 365 Spring 2017
// HW1 – Sieve of Eratosthenes
// Platform: Mac
//

#pragma once

#include <string>
#include "gwindow.h"

enum NumberType
{
    UNKNOWN,
    PRIME,
    COMPOSITE
};

// Function: drawSquare
// Purpose: draws square
// Input: GWindow, int number, NumberType, two doubles x and y as coordinates
// Output: nothing

void drawSquare (GWindow& GW, int number, NumberType type, double x, double y);



// Function: initVectors
// Purpose: one vector contains numbers and the other type
// Input: vector of int, vector of NumberType to contain type
// Output: nothing

void initVectors (Vector<int>& number, Vector<NumberType>& type);


// Function: drawGrid
// Purpose: draws the whole grid
// Input: GWindow, int number, NumberType,
// Output: nothing

void drawGrid (GWindow& GW, Vector<int>& number, Vector<NumberType>& type);


// Function: calcNextPrime
// Purpose: find prime number and make its multiples as composites
// Input: int number, NumberType, int startAt
// Output: -1 in case did not find a prime number

int calcNextPrime (Vector<int>& number, Vector<NumberType>& type, int startAt);

