// ITP 365 Fall 2017
// HW3 Towers of Hannoi
// Name: Mana Mehraein
// Email: mehraein@usc.edu
// Platform: Mac
//

#include "Disk.h"
#include "random.h"

Disk::Disk()
{
    mXcoord=0;
    mYcoord=0;
    mHeight=0;
    mWidth=0;
    
    // to have random color for disks
    int r=randomInteger(0, 255);
    int g=randomInteger(0, 255);
    int b=randomInteger(0, 255);
    std::ostringstream stream;
    stream <<"#";
    stream << std::hex <<  r;
    stream << std::hex << g;
    stream << std::hex << b;
    mColor=stream.str();
}

Disk::Disk(int x, int y, int width, int height)
{
    setX (x);
    setY (y);
    mHeight=height;
    mWidth=width;
    
    int r=randomInteger(0, 255);
    int g=randomInteger(0, 255);
    int b=randomInteger(0, 255);
    std::ostringstream stream;
    stream <<"#";
    stream << std::hex <<  r;
    stream << std::hex << g;
    stream << std::hex << b;
    mColor=stream.str();
    
}

//setters
void Disk::setX (int x)
{
    mXcoord=x;
}
void Disk::setY (int y)
{
    mYcoord=y;
}


//getter
int Disk::getHeight()
{
    return mHeight;
}


//functions

// Function: drawDisk
void Disk::drawDisk (GWindow& gw)
{
    //draw a filled rectangle as our disk
    gw.setColor(mColor);
    gw.fillRect(mXcoord-(mWidth/2), mYcoord-mHeight, mWidth, mHeight);
    gw.setColor("black"); // set color for it
    gw.drawRect(mXcoord-(mWidth/2), mYcoord-mHeight, mWidth, mHeight); //draw the rectangle as our disk
}




