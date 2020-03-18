// ITP 365 Fall 2017
// HW5 Vector and Poker Hands
// Name: Mana Mehraein
// Email: mehraein@usc.edu
// Platform: Mac
//
// ITPVector.hpp
// Defines and implements the ITPVector collection
//
#pragma once
#include <sstream>
#include <ostream>
#include "error.h"

template <typename T>
class ITPVector
{
    const unsigned INITIAL_CAPACITY = 10;
    const unsigned CAPACITY_MULTIPLIER = 2;
public:
    // Function: Constructor
    // Purpose: Initializes the ITP vector to have a
    // capacity of INITIAL_SIZE and a size of 0.
    // It also dynamically allocates the underlining array data
    // Input: None
    // Returns: Nothing
    
    ITPVector()
    {
        // TODO: Implement
        //        This constructor should initialize the capacity to
        //        INITIAL_CAPACITY and the size to 0. It should then proceed to dynamically allocate the
        //        underlying array of Ts to have capacity elements in it.
        mCapacity=INITIAL_CAPACITY;
        mSize=0;
        mData=new T[mCapacity];
        
    }
    
    // Function: Destructor
    // Purpose: Deletes the underlying array and
    // sets size/capacity to zero
    // Input: None
    // Returns: Nothing
    ~ITPVector()
    {
        // TODO: Implement
        //        The destructor should delete the underlying array
        //        and set the capacity and size to 0.
        delete[] mData;
        mSize=0;
        mCapacity=0;
    }
    
    // Function: capacity
    // Purpose: Returns the current capacity of the underlying array data
    // Input: None
    // Returns: Capacity of underlying array data
    unsigned capacity() const
    {
        // TODO: Implement
        //        Implement the capacity function that returns the capacity of the ITPVector
        return mCapacity; // FIX RETURN VALUE
    }
    
    // Function: size
    // Purpose: Returns the current size of the vector
    // Input: None
    // Returns: Size of vector
    unsigned size() const
    {
        // TODO: Implement
        //        Implement the size function that returns the size of the ITPVector
        return mSize; // FIX RETURN VALUE
    }
    
    // Function: Subscript operator (read/write version)
    // Purpose: Grabs the specified index from vector
    // Causes an error if the index is out of bounds
    // Input: Index to access
    // Returns: Value at index, by reference
    T& operator[](unsigned index)
    {
        // TODO: Implement
        //        Implement the two subscript operators. Note that both implementations should check for an out-of-bounds index, in which case the error function should be called with an appropriate error message.
        
        //        1. If    index    >=    size    – error!
        //        2. Return    the    value    at    the    requested    index
        
        if (index>= mSize || index <0)
        {
            error ("Out of bound!");
        }
//        else
//        {
            //        return *(new T()); // FIX RETURN VALUE
            
            return mData[index];
//        }
    }
    
    // Function: Subscript operator (read-only version)
    // Purpose: Grabs the specified index from vector
    // Causes an error if the index is out of bounds
    // Input: Index to access
    // Returns: Value at index, by reference
    const T& operator[](unsigned index) const
    {
        // TODO: Implement
        //        Implement the two subscript operators. Note that both implementations should check for an out-of-bounds index, in which case the error function should be called with an appropriate error message.
        
        //        1. If    index    >=    size    – error!
        //        2. Return    the    value    at    the    requested    index
        if (index<0 || index >= mSize)
        {
            error ("Out of bound!");
        }
//        else
//        {
            return mData[index];
//        }
        //        return T(); // FIX RETURN VALUE
    }
    
    // Function: insert_back
    // Purpose: Adds the specified element to the end of the ITPVector
    // It automatically reallocates the underlying array if we are
    // going over capacity
    // Input: Value to add (by const reference)
    // Returns: Nothing
    void insert_back(const T& value)
    {
        // TODO: Implement
        //        If the current size is less than the current
        //        capacity, this is relatively straightforward. However, if the current size is equal to the capacity (meaning the insertion will go over the capacity), you will need to create new underlying array data. Consult the lecture notes for a discussion of this.
        
        if (mSize<mCapacity)
        {
            //            1. Place the element at index size(0)
            mData[mSize]=value; //?????????????????????????????????
            //            2. Increment size
            mSize++;
        }
        else if (mSize==mCapacity)
        {
            //            In the case that capacity == size (as below), we are out of space in our underlying array. So    it’s much more complicated:
            //            1. Increase the capacity (usually double it)
            mCapacity*=CAPACITY_MULTIPLIER;
            //            2. Dynamically allocate a new underlying array w/ new capacity
            T* mNewData= new T[mCapacity];
            //            3. Copy the data from the old array to the new array
            for (int i=0; i<mSize;i++)
            {
                mNewData[i]=mData[i];
            }
            //            4. Delete the old array
            delete[] mData;
            //            5. Set your pointer to the new array
      //    mData -> mNewData;
            mData = mNewData;
            //            6. Add an element at index size
            mData[mSize]=value; //???????????
            //            7. Increment size by 1
            mSize++;
            
        }
    }
    
    // Function: get_back
    // Purpose: Returns the current last element in the vector
    // Does not remove this element from the vector
    // Causes an error if there are no elements in the vector
    // Input: Nothing
    // Returns: Value at back of vector, by reference
    T& get_back()
    {
        // TODO: Implement
        //        This should return the last element in the ITPVector. Note that if the size of the vector is 0, this function should call the error function with an appropriate message.
        //        1. If    size    ==    0    – error!
        //        2. Return    the    element    at    size    - 1
        
        if (mSize==0)
        {
            error ("Nothing to return!");
        }
        //        return T(); // FIX RETURN VALUE
        return mData[mSize-1];
    }
    
    // Function: remove_back
    // Purpose: Removes the last element from the ITPVector
    // Causes an error if there are no elements in the vector
    // Input: Nothing
    // Returns: Nothing
    void remove_back()
    {
        // TODO: Implement
        
        //        This removes the last element in the ITPVector. Note that the size of the vector is 0, this function should call the error function with an appropriate message.
        //
        //        1. If    size    ==    0    – error!
        
        if (mSize==0)
        {
            error ("Nothing to remove!");
        }
        //        2. Decrement    size    by    1
        mSize--;
        
        
    }
    
    // Function: Output Stream Operator
    // Purpose: Prints the contents of the vector to the provided stream
    // Written in the format of {x, y, ..., z}
    // Input: Stream to write to, vector to write
    // Output: Stream after values are written
    friend std::ostream& operator<<(std::ostream& os, const ITPVector<T>& vector)
    {
        // TODO: Implement
        //        This should loop through the vector from the start to end indices, and output a comma separated list of the elements in the vector.
        
        for (int i=0; i< vector.size(); i++)
        {
            if (i==vector.size() - 1) // skip the last comma
            {
                os <<vector[i];
            }
            else
            {
                os << vector[i] << ", ";
            }
        }
        
        return os;
    }
private:
    // TODO: Define member variables here
    //    Add three member variables – two unsigned integers to track the capacity and size,
    //    respectively, and a pointer to a T that you will use to keep track of the underlying array
    //    data.
    unsigned mSize;
    unsigned mCapacity;
    T* mData;
    
    // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    // NOTE: Do not edit code below this line!!!
    // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    
    // Disallow assignment and copy construction
    ITPVector<T>& operator=(const ITPVector<T>& other)
    {
        
    }
    
    ITPVector(const ITPVector<T>& other)
    {
        
    }
};
