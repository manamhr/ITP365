// ITP 365 Fall 2017
// HW3 Towers of Hannoi
// Name: Mana Mehraein
// Email: mehraein@usc.edu
// Platform: Mac
//

#pragma once
#include "gwindow.h"
#include <stdio.h>
#include "Disk.h"


class Peg
{
public:
    
    //default constructor
    Peg();
    Peg(int xp, int yp, int pwidth, int pheight);
    
    // Function: setXP
    // Purpose: set x coordinate for peg!
    // Input: xp as int
    // Output: nothing
    void setXP (int px);
    
    // Function: setYP
    // Purpose: set y coordinate for peg!
    // Input: yp as int
    // Output: nothing
    void setYP (int py);
    
    // Function: setPHeight
    // Purpose: set height of the peg!
    // Input: pheight as int
    // Output: nothing
    void setPHeight (int pheight);
    
    // Function: setPWidth
    // Purpose: set width of the peg!
    // Input: pwidth as int
    // Output: nothing
    void setPWidth (int pwidth);
    
    // Function: drawPeg
    // Purpose: Draw pegs!
    // Input: gw to draw the pegs and a vector to draw the disks
    // Output: nothing
    void drawPeg (GWindow& gw);
    
    // Function: addDisk
    // Purpose: add disks!
    // Input: a disk
    // Output: nothing
    void addDisk(Disk);
    
    // Function: removeDisk
    // Purpose: removes the last disk and returns it
    // Input: nothing
    // Output: last disk
    Disk removeDisk();
    
    
private:
    //member variables
    
    //The Peg’s x and y coordinates. It is a GoodIdea© to have coordinates be the bottom center of the Peg. The Peg is a tall, skinny rectangle.
    int mXPcoord;
    int mYPcoord;
    //units in pixels
    int mPHeight;
    int mPWidth;
    std::string mPColor;
    //Vector of Disks member variable which will contain all the Disk objects that are “on” that Peg.
    Vector<Disk> myDisks;
    
};

