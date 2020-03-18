// ITP 365 Fall 2017
// HW5 Vector and Poker Hands
// Name: Mana Mehraein
// Email: mehraein@usc.edu
// Platform: Mac



#include "ITPVector.hpp"
#include "Cards.h"
#include <iostream>

int main(int argc, char** argv)
{
    ITPVector<int> testVector;
    // TODO: Do stuff
    
    bool quit = false;
    while (!quit)
    {
        int choice;
        int elem;
        std::cout << "Select an option..." << std::endl;
        std::cout << "1. Test ITPVector" << std::endl;
        std::cout << "2. Poker Hands" << std::endl;
        std::cin >> choice;
        std::cin.ignore();
        
        if (choice == 1) // if they choose 1 to test ITPVector
        {
            while (!quit)
            {
                std::cout << "*** Constructing an ITPVector..."<<std::endl;
                std::cout << "Contents: { " << testVector<< "}" << std::endl; // print out the contents of testVector
                std::cout << "Capacity: " << testVector.capacity() << " , Size: " << testVector.size() << std::endl; // print out the capacity and size
                std::cout << " Enter a number of elements to add: " ;
                std::cin >> elem;
                std::cin.ignore();
                for (int i=0; i< elem; i++)
                {
                    testVector.insert_back(i*5); // adding contents to the vector
                }
                std::cout << "Contents: { " << testVector<< "}" << std::endl;
                std::cout << "Capacity: " << testVector.capacity() << " , Size: " << testVector.size() << std::endl;
                std::cout << "The back element is: " << testVector.get_back() << std::endl; // peek into the last element
                std::cout << "Called remove_back"<<std::endl; // remove the last element
                testVector.remove_back();
                std::cout << "Contents: { " << testVector<< "}" << std::endl;
                std::cout << "Capacity: " << testVector.capacity() << " , Size: " << testVector.size() << std::endl;
                std::cout << "***Test Complete!" <<std::endl;
                // remove all the content again
                while(testVector.size()!=0)
                {
                    testVector.remove_back();
                    
                }
                
                if (elem== 0) // come out of the loop when 0 is entered
                {
                    std::cout << "Bye!" << std::endl;
                    quit = true;
                }
                
            }
        }
        
        else if (choice == 2)
        {
            while (!quit)
            {
                std::string answer;
                ITPVector<Card> deck;
                //First, it should create a deck,
                createDeck(deck);
                //then create a PokerHand,
                PokerHand hand(deck);
                //and output both which cards you have and what poker hand it forms.
                
                std::cout << "You drew: { "<< hand<< " }" <<std::endl;
                std::cout << hand.getBestPokerHand() <<std::endl;
                std::cout << "Try again (y/n): ";
                std::cin >> answer;
                std::cin.ignore();
                
                // will continue unless they type n or N then it will quit.
                if (answer == "y" || answer == "Y")
                {
                    std::string answer;
                    ITPVector<Card> deck;
                    //First, it should create a deck,
                    createDeck(deck);
                    //then create a PokerHand,
                    PokerHand hand(deck);
                    //and output both which cards you have and what poker hand it forms.
                    
                    std::cout << "You drew: { "<< hand<< " }" <<std::endl;
                    std::cout << hand.getBestPokerHand()<<std::endl;
                    std::cout << "Try again (y/n): ";
                    std::cin >> answer;
                    std::cin.ignore();
                }
                    
                else if (answer=="n" || answer == "N")
                {
                    std::cout << "Okay bye!" << std::endl;
                    quit = true;
                }
                
                
                //Keep repeating this process until the user says to stop
                
                
                //            • Hint: You can check your code for the better hands by creating a “stacked” deck of only the cards you want to draw.
                //                • Output for this part should look something like this (user input in red):
                //                    You drew: {6 of Diamonds,10 of Clubs,10 of Hearts,10 of Spades,Ace of Diamonds} You have a three of a kind
                //            Try again (y/n):y
                //            You drew: {3 of Hearts,6 of Clubs,10 of Spades,Jack of Diamonds,King of Clubs} You have a high card
                //            Try again (y/n):y
                //            You drew: {6 of Diamonds,6 of Hearts,7 of Hearts,8 of Hearts,King of Diamonds} You have a pair
            }
        }
        
        else
        {
            std::cout << "Bye!" << std::endl;
            quit = true;
        }
    }
    return 0;
    
}
