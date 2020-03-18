// ITP 365 Fall 2017
// HW3 Towers of Hannoi
// Name: Mana Mehraein
// Email: mehraein@usc.edu
// Platform: Mac
//

#include "Peg.h"
#include "Disk.h"



Peg::Peg()
{
    mXPcoord=0;
    mYPcoord=0;
    //units in pixels
    mPHeight=0;
    mPWidth=0;
    mPColor="black";
    
}

Peg::Peg(int xp, int yp, int pwidth, int pheight)
{
    setXP (xp);
    setYP (yp);
    setPHeight (pheight);
    setPWidth (pwidth);
    mXPcoord=xp;
    mYPcoord=yp;
    mPHeight=pheight;
    mPWidth=pwidth;
    mPColor="black";
    
}

//setters


void Peg::setXP (int xp)
{
    mXPcoord=xp;
}
void Peg::setYP (int yp)
{
    mYPcoord=yp;
}
void Peg::setPHeight(int pheight)
{
    mPHeight=pheight;
}
void Peg::setPWidth (int pwidth)
{
    mPWidth=pwidth;
}

//functions

//Function: drawPeg
void Peg::drawPeg (GWindow& gw)
{
    // just draw black pegs
    gw.setColor("black");
    gw.fillRect(mXPcoord-(mPWidth/2), mYPcoord-mPHeight, mPWidth, mPHeight);
    
    
    for (int i=0; i<myDisks.size();i++)
    {
        myDisks[i].drawDisk(gw);
    }
}

//Function: addDisk
void Peg::addDisk(Disk diskp)
{
    //set x of the disk
    int x=mXPcoord;
    diskp.setX(x);
    
    
    //set the y
    int y=mYPcoord-(diskp.getHeight()*myDisks.size());
    diskp.setY(y);
    
    //add it to the vector of the disk
    myDisks.add(diskp);
    
}

//Function: removeDisk
Disk Peg::removeDisk()
{
    Disk last=myDisks[myDisks.size()-1];
    myDisks.remove(myDisks.size()-1);
    return last;
    
}
