// ITP 365 Fall 2017
// HW3 Towers of Hannoi
// Name: Mana Mehraein
// Email: mehraein@usc.edu
// Platform: Mac
//

#pragma once
#include "gwindow.h"
#include <stdio.h>

class Disk
{
public:
    // x-y coord for disk (to be bottom center of the disk) size is in pixel
    // width and height of the Disk in pixel
    // color of the Disk (as string)
    
    
    //Default constructor
    Disk();
    Disk(int x, int y, int width, int height);
    
    // Function: setX
    // Purpose: set x coordinate for disk!
    // Input: x as int
    // Output: nothing
    void setX (int x);
    // Function: setY
    // Purpose: set y coordinate for disk!
    // Input: y as int
    // Output: nothing
    void setY (int y);
    // Function: getHeight
    // Purpose: get Height of the disk!
    // Input: x as int
    // Output: nothing
    int getHeight();
    
    // Function: drawDisk
    // Purpose: Draw disks!
    // Input: gw to draw the rectangular disks
    // Output: nothing
    void drawDisk (GWindow& gw);
    
    
private:
    
    
    int mXcoord;
    int mYcoord;
    int mHeight;
    int mWidth;
    std::string mColor;
    
};
