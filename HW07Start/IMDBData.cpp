// ITP 365 Fall 2017
// HW7 - IMDB Graph
// Name: Mana Mehraein
// Email: mehraein@usc.edu
// Platform: Mac
//
// IDMBData.cpp - Implements IMDBData interface

#include "IMDBData.h"
#include <fstream>
#include <iostream>
#include <queue>

// Do for Part 1
// Function: Default Constructor
// Purpose: Loads in the actor/movie file specified,
// and populates the data into the appropriate hash maps.
// Also constructs the graph with actor relationships.
// Input: Name of file to load (by reference)
// Returns: Nothing
IMDBData::IMDBData(const std::string& fileName)
{
    // TODO for Part 1
    // TODO: Generate the actor to movies map
    std::ifstream file(fileName);
    if (file.is_open())
    {
        std::string actor;
        std::vector<std::string> movies;
        
        while (!file.eof())
        {
            std::string buffer;
            std::getline(file, buffer);
            if ( buffer.find("|")!=std::string::npos)
            {
                
                //                do
                //                {
                std::string mv=buffer.substr(1);
                //                std::cout << mv<< std::endl;
                movies.push_back(mv);
                mActorsToMoviesMap[actor].push_back(mv);
                
                
            }
            else // filling out the mMovieToActorsMap
                
            {
                if (actor != "")
                {
                    reverseMap(actor,movies);
                }
                actor = buffer;
                movies.clear();
                
            }
        }
        
    }
    
    
}

// Do for Part 1
// Function: reverseMap
// Purpose: This is a helper function that is used to generate
// the reverse map (movies to actors)
// Input: Name of actor (by reference), vector of their movies (by reference)
// Returns: Nothing
void IMDBData::reverseMap(const std::string& actorName, const std::vector<std::string>& movies)
{
    // TODO for Part 1
    // TODO: Implement
    std::vector<std::string> actors;
    
//    To aid in this endeavor, you should first implement the reverseMap function. This function takes in the name of an actor as well as a vector which contains all of their movies. For each movie in the vector, you then want to do the following: 1. If mMovieToActorsMap already contains the movie in question, you need to add actorName to that movie’s associated vector 2. Otherwise, you need to add an entry in mMovieToActorsMap that associates the movie with a vector that, for now, only contains actorName
    for (const auto& mov:movies)
    {
        if (mMoviesToActorsMap.find(mov) != mMoviesToActorsMap.end())
        {
            mMoviesToActorsMap[mov].push_back(actorName); //
        }
        else
        {
            std::vector <std::string> actor;
            actor.push_back(actorName);
            mMoviesToActorsMap.insert ({mov, actor});
        }
    }
}

// Do for Part 1
// Function: getMoviesFromActor
// Purpose: Given an actor's name, returns a vector containing their movies
// Input: Name of actor (by reference)
// Returns: Vector of movies (by reference)
std::vector<std::string>& IMDBData::getMoviesFromActor(const std::string& actorName)
{
    // TODO for Part 1
    // TODO: Implement
    
    if (mActorsToMoviesMap.find(actorName) != mActorsToMoviesMap.end())
    {
        return mActorsToMoviesMap[actorName]; //return lookup of the map using []
    }
    
    else
    {
        return sEmptyVector;
    }
}

// Do for Part 1
// Function: getActorsFromMovie
// Purpose: Given a movie's name, returns the name of its actors
// Input: Name of movie (by reference)
// Returns: Vector of actors (by reference)
std::vector<std::string>& IMDBData::getActorsFromMovie(const std::string& movieName)
{
    // TODO for Part 1
    // TODO: Implement
    if (mMoviesToActorsMap.find(movieName) != mMoviesToActorsMap.end())
    {
        return mMoviesToActorsMap[movieName]; //return lookup of the map using []
    }
    
    else
    {
        return sEmptyVector;
    }
}

// Do for Part 2
// Function: findRelationship
// Purpose: Tries to find a relationship between two actors, using a BFS
// and outputs (to cout) the result of the search.
// Input: Name of two actors to check for a relationship
// Returns: Nothing
void IMDBData::findRelationship(const std::string& fromActor, const std::string& toActor)
{
    // TODO for Part 1
    // TODO: Implement
    // check if both actors are in the graph – if they aren’t you should cout an error message
    bool check_find=false;
    if (!mGraph.containsActor(fromActor) || !mGraph.containsActor(toActor))
    {
        if (!mGraph.containsActor(fromActor) ) // if from actor was not found
        {
            std::cout << fromActor<< " was not found!" << std::endl;

        }
        else if (!mGraph.containsActor(toActor)) // if to actor was not found
        {
        std::cout << toActor << " was not found!" << std::endl;
        }
        return;
    }
    
    //    //implement BFS
    //
    //    1. Create a queue of ITPGraphNode*, and enqueue the node we’re
    //    starting from
    std::queue<ActorNode*>bfsQueue;
    ActorNode* start= mGraph.getActorNode(fromActor);
    ActorNode* end= mGraph.getActorNode(toActor);
    ActorNode* currentNode=nullptr;
    bfsQueue.push(start);
    
    
    
    //    2. While the BFS queue is not empty
    while (!bfsQueue.empty())
    {
        //    a) Dequeue the front ITPGraphNode*, and save in currentNode
        currentNode = bfsQueue.front();
        //        if (start->mPath.size()==0)
        //        {
        //            start->mPath=currentNode->mPath;
        //        }
        bfsQueue.pop();
        
        //    b) If currentNode is the target node, we found a path!
        
        //    c) Otherwise if currentNode’s visited bool is false
        if (currentNode->mIsVisited== false)
        {
            //        1. Visit the ITPGraphNode*
            //        2. Set currentNode’s visited bool to true
            currentNode->mIsVisited= true;
            //        3. Loop through currentNode’s adjacency list, and a) enqueue all adjacent nodes whose visited flag is false
            for (auto E: currentNode->mEdges)
            {
                ActorNode* other= E->mOtherActor;
                if (other->mIsVisited == false)
                {
                    bfsQueue.push(other);
                    //      b) If the adjacent node path has a size of 0…
                    if (other->mPath.size()==0)
                    {
                        //          a) Set the adjacent node’s path equal to currentNode’spath
                        other->mPath=currentNode->mPath;
                        //          b) Push_backadjacent nodes’srelevant path information (destination name and label in ITPPathInfostruct)
                        PathPair path(E->mMovieName, other->mName );
                        other->mPath.push_back(path);
                    }
                    
                }
                
            }
        }
        else if (currentNode == end)
        {
            check_find=true;
            std::cout << "Found a path!" << std::endl;
            std::cout << end->mPath.size() << " hops..." << std::endl; // print out the hops
            std::cout << fromActor << " was in ..." << std::endl;
            int counter=0;
            for (const PathPair& path: currentNode->mPath)
            {
                
                if (end->mPath.size()-1!=counter) // print out the path
                std::cout << path.getMovieName() << " with " << path.getActorName() << " who was in ..." <<std::endl;
                else
                {
                    std::cout << path.getMovieName() << " with " << path.getActorName() <<std::endl;
                }
                counter++;
                
            }
            
            break;
        }
        
    }
    //                3. If we made it here without finding the target node, no path
    //                exists!
    if(!check_find)
    {
        std::cout << "Didn’t find a path! :("<< std::endl;
    }
    
    
    
    
    // LEAVE THIS AT THE END OF THE FUNCTION
    mGraph.clearVisited();
}

// For Part 2
// Function: createGraph
// Purpose: This helper function constructs the IMDBGraph from the movie to actors map
// Input: None
// Returns: Nothing
void IMDBData::createGraph()
{
    // DO NOT EDIT THIS FUNCTION
    // For every movie in the actors map...
    for (auto& p : mMoviesToActorsMap)
    {
        const std::string& movieName = p.first;
        // Get the actors for this movie
        const std::vector<std::string>& actors = mMoviesToActorsMap[movieName];
        
        // Make n^2 edges between these actors
        for (size_t i = 0; i < actors.size(); i++)
        {
            ActorNode* firstActor = mGraph.getActorNode(actors[i]);
            for (size_t j = i + 1; j < actors.size(); j++)
            {
                ActorNode* secondActor = mGraph.getActorNode(actors[j]);
                mGraph.createActorEdge(firstActor, secondActor, movieName);
            }
        }
    }
}

// Leave here! Do not edit!!! Use in part 1
// DO NOT REMOVE THIS LINE
std::vector<std::string> IMDBData::sEmptyVector;
