#include "MoviePlayer.h"

// ITP 365 Fall 2017
// HW6 - Doubly Linked List and Movie Player
// Name: Mana Mehraein
// Email: mehraein@usc.edu
// Platform: Mac



// Function: Parameterized Constructor
// Purpose: Sets member variables to input, clears list, and calls loader
// Input: None
// Returns: Nothing
MoviePlayer::MoviePlayer(std::string filmName)
{
    // TODO: Implement
    //    The parameterized constructor should set the appropriate
    //    member variables, ensure that the tape is empty, then call the member function
    //    loadTape on the inputted file name.
    
    // Holds the current frame the film is on
    currFrameNum=0;
    
    // Stores the name of the input file
    // that has the ASCII film in it
    mFilmName=filmName;
    
    // The film is made a series of strings
    // each string is 1 frame to be displayed
    // by the main function
    // Stores the current position of the reader
//    mFilm.clear();
    loadTape();
    rewind();
    
}

// Function: Destructor
// Purpose: Empties the list
// Input: None
// Returns: Nothing
MoviePlayer::~MoviePlayer()
{
    // TODO: Implement
    //    While not necessary, we’ll protectively ensure that the tape is
    //    empty here.
    mFilmName.clear();
}

// Function: goFwrd
// Purpose: Moves the current "frame" forward by 1 frame
// Also keeps track of how many frames have been viewed
// Shouldn't go past the end of the movie
// Input: None
// Returns: Nothing
void MoviePlayer::goFwrd()
{
    // TODO: Implement
    
    //    This function should move the tape forward 1 frame. It should also
    //    increment the currFrameNum counter.
    
    if (pos->mNext!=nullptr)
    {
        currFrameNum++;
        pos++;
    }
    
}

// Function: goBack
// Purpose: Moves the current "frame" backward by 1 frame
// Also keeps track of how many frames have been viewed
// Shouldn't go past the end of the movie
// Input: None
// Returns: Nothing
void MoviePlayer::goBack()
{
    // TODO: Implement
    
    //    This function should move the tape backward 1 frame. It should
    //    also decrement the currFrameNum counter.
    if (pos->mPrev!=nullptr)
    {
        currFrameNum--;
        pos--;
    }
}

// Function: rewind
// Purpose: Moves the current "frame" to the movie's beginning again
// Input: None
// Returns: Nothing
void MoviePlayer::rewind()
{
    // TODO: Implement
    //    Here you’ll start the tape over again, being sure to keep track of
    //    the currFrameNum counter.
    currFrameNum=1;
    pos=mFilm.begin();
}

// Function: getCurrFrame
// Purpose: Gets the string that contains the current "frame" as stored
// in the list "mFilm"
// Input: None
// Returns: String with the current "frame"
std::string MoviePlayer::getCurrFrame()
{
    // TODO: Implement
    //    Here you’ll return the current currFrameNum counter.
    
    return *pos; // FIX RETURN VALUE
}

// Function: delCurrFrame
// Purpose: Deletes the current frame, moves forward to the next one
// Also keeps track of how many frames have been viewed
// Input: None
// Returns: Nothing
void MoviePlayer::delCurrFrame()
{
    // TODO: Implement
    //    This function will delete the current frame and move the tape forward 1 frame.
    if (pos->mPrev!=nullptr)
    {
    pos= mFilm.erase(pos); ////check this
}
}

// Function: copyCurrFrame
// Purpose: Copies current frame and places the copy BEFORE the current frame
// Also keeps track of how many frames have been viewed
// Input: None
// Returns: Nothing
void MoviePlayer::copyCurrFrame()
{
    // TODO: Implement
    
    //    This will copy the current frame and move the tape to the newly added frame.
    pos=mFilm.insert(pos,*pos); //check

}

// Function: getCurrFrameNum
// Purpose: Gets the "index" that corresponds to the current frame
// Input: None
// Returns: Number of frames that have been viewed
unsigned MoviePlayer::getCurrFrameNum() const
{
    // TODO: Implement
    //    One takes in no input and returns a string with the contents of the current frame.
    return currFrameNum; // FIX RETURN VALUE
}

// Function: getNumFrames
// Purpose: Gets the total number of frames in the movie
// Input: None
// Returns: The overall number of frames in the movie
unsigned int MoviePlayer::getNumFrames() const
{
    // TODO: Implement
    // Here you’ll return the total number of frames in the movie.
    return mFilm.size(); // FIX RETURN VALUE
}

// Function: getFrameSize
// Purpose: Gives the number of lines in a frame
// For how big the "screen" for the film should be
// Input: None
// Returns: The value stored in FRAMESIZE
unsigned int MoviePlayer::getFrameSize() const
{
    // TODO: Implement
    // This function gets the number of line in a frame.
    return FRAMESIZE; // FIX RETURN VALUE
}

// Function: getCurrFrame
// Purpose: Retrieves the current "frame" from the film list
// Modifies the inputted vector of GLabels to contain the current frame
// Input: A vector of "GLabels" that are the "screen" -- passed by reference
// Returns: Nothing
void MoviePlayer::getCurrFrame(Vector<GLabel*>& screen)
{
    // TODO: Implement
    // takes in a Vector of GLabel pointers, passed in by reference.
    // There should be 13 items in the Vector which is the same as the number of lines in each frame.
    // Each GLabel must have its label set to the corresponding line of text in the frame.
    //
    // do get line on current frame
    // check on how to change labels on stanford
    //make a new string stream
    //set up from current frame in there
    
    
    // or instead of *pos I could use getCurrFrame()
    std::stringstream frames(*pos);
    
    for (int i=0; i< FRAMESIZE; i++)
    {
        //get one line
        std::string num;
        getline(frames,num);
        //        std::string num  = getCurrFrame();
        screen[i]->setLabel(num);
    }
    
}

// Function: loadTape
// Purpose: Uses mFilmName (set by constructor) to fill
// mFilm with strings that make up the movie to display
// Input: None
// Returns: Nothing
void MoviePlayer::loadTape()
{
    // TODO: Implement
    
    //    This function should open the inputted text file. Assume the
    //    user only enters one of the “.ani” files. This function parses out the text file and makes
    //    up the frames and fills the ITPDoubleList with the animations.
    //        std::ifstream mFilmName("starwar.ani");
    std::ifstream file (mFilmName);
    if (file.is_open())
    {
        while (!file.eof())
        {
            std::string line;
            std::getline(file, line);
            //            auto n= line.substr(0,2);
            //            std::cout << n<< std::endl;
            //            auto number=stringToInteger(n);
            //            std::cout << number<< std::endl;
            
            //use stanford, use stringstream
            if (!stringIsInteger(line))
            {
                break;
            }
            else
            {
                //if not a number, break
                //if it is a number save it for later
                //read in 13 lines
                //smush them all together
                //insert the smush n number of times
                
                std::string page;
                std::string frame="";
                
               
                    for (int i=0; i<13; i++)
                    {
                        std::getline(file, page);
                        frame+=page;
                        frame=frame+" \n";
                    }
                    //                    std::cout << frame << std::endl;
                    
                    //converto line to int
                    if(stringIsInteger(line))
                    {
                        int number=stringToInteger(line);
                        for (int i=0; i<number; i++)
                        {
                            mFilm.push_back(frame);
                        }
                    }
                    
                
            }
            
        }
        
    }
    else
    {
        error ("Sorry file does not exist!");
    }
}
