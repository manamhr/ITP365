// ITP 365 Fall 2017
// HW3 Towers of Hannoi
// Name: Mana Mehraein
// Email: mehraein@usc.edu
// Platform: Mac

#include <iostream>
#include "gwindow.h"
#include "Disk.h"
#include "Peg.h"

// Function: promptForDisks
// Purpose: asks the user to enter the number of disks they want to play
// Input: nothing
// Output: number of disks
int promptForDisks()
{
    int numDisk=0;
    
    do
    {
        std::cout << "Enter the number of Disks to start with... it should be between 2 and 10: ";
        std::cin >> numDisk;
    } while (numDisk<2 || numDisk >10);
    
    
    return numDisk;
    
}

// Function: promptForPegs
// Purpose: asks the user to enter the start and end peg
// Input: int for start number and end one
// Output: nothing

void promptForPegs(int& start, int& end)
{
    do{
        std::cout << "Enter the starting peg, a number between 1 to 3! ";
        std::cin >> start;
    }while (start<1 || start>3);
    
    do{
        std::cout << "Enter the ending peg, a number between 1 to 3 and not the same as start! ";
        std::cin >> end;
    } while (end<1 || end >3 || end == start);
    
}

// Function: draw
// Purpose: draw pegs
// Input: gw for GWindow and vector of pegs
// Output: nothing

void draw (GWindow& gw, Vector<Peg>& pegs)
{
    gw.clear();
    
    for (int i=0; i<pegs.size(); i++)
    {
        pegs[i].drawPeg(gw);
        
    }
    pause(500);
    
}

// Function: moveDisk
// Purpose: move the disks, removes the disk from start and add it to the end peg
// Input: gw for GWindowm vector of pegs, start and end pegs
// Output: nothing

void moveDisk (GWindow& gw, Vector<Peg>& pegs,int start, int end )
{
    Disk d=pegs[start].removeDisk();
    pegs[end].addDisk(d);
    draw(gw, pegs);
}


// Function: towerSolver
// Purpose: recursion function to solve the tower problem
// Input: gw for GWindowm vector of pegs, start and end pegs and number of disks
// Output: nothing
void towerSolver(GWindow& gw, Vector<Peg>& pegs,int start, int end, int numDisk )
{
    int temp=3-(start+end);
    
    if (numDisk==0)
    {
        return ;
    }
    
    else
    {
        //        1.4.1. Transfer N−1 Disks from “start” to “temp”. This leaves Disk 0 alone on “start”
        towerSolver(gw, pegs, start, temp, numDisk-1);
        //        1.4.2. Move Disk 0 from “start” to “end”
        moveDisk(gw, pegs, start, end);
        //        1.4.3. Transfer N−1 Disks from “temp” to “end” so they sit on Disk 0
        towerSolver(gw, pegs, temp, end, numDisk-1);
    }
}

int main(int argc, char** argv)
{
    GWindow gw(800, 500);
    gw.setWindowTitle("Tower of Hanoi");
    
    //get number of disks
    int numDisk=promptForDisks();
    
    //get start and end
    int start=0;
    int end=0;
    promptForPegs(start,end);
    start--;
    end--;
    
    // a vector of pegs
    Vector<Peg> myPegs;
    // add 3 pegs
    for (int i=0; i<3; i++)
    {
        myPegs.add(Peg(200+200*i, 480, 5, 400));
    }
    
    // adding disks to pegs
    for (int i=0; i<numDisk; i++)
    {
        myPegs[start].addDisk(Disk (0,0,100-(8*i),20));
    }
    draw(gw, myPegs);
    
    //    moveDisk (gw, myPegs,start,end );
    // calling towerSolver
    towerSolver(gw, myPegs, start, end, numDisk);
    
    return 0;
}
