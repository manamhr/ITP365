// ITP 365 Fall 2017
// HW6 - Doubly Linked List and Movie Player
// Name: Mana Mehraein
// Email: mehraein@usc.edu
// Platform: Mac
//
// ITPDoubleList.hpp
// Defines and implements the ITPDoubleList collection
//

#pragma once
#include "error.h"
#include <ostream>
#include <sstream>
#include "leaker.h"

template <typename T>
class ITPDoubleList
{
private:
    
    // Node only used internally to list
    struct Node
    {
        // Data in this node
        T mData;
        // Link to previous node
        Node* mPrev;
        // Link to next node
        Node* mNext;
    };
    
    // Pointer to the head node
    Node* mHead;
    // Pointer to the tail node
    Node* mTail;
    // Number of nodes currently in the list
    unsigned mSize;
    
public:
    // Iterator helper class...
    class Iterator
    {
    private:
        Node* mCurr;
    public:
        // Needed for List access
        friend class ITPDoubleList;
        // Constructors
        Iterator()
        {
            // TODO: Implement
            mCurr = nullptr;
            
        }
        
        Iterator(Node* inCurr)
        {
            // TODO: Implement
            mCurr=inCurr;
        }
        
        Iterator(const Iterator& src)
        {
            // TODO: Implement
            mCurr=src.mCurr;
            
        }
        
        // Assignment
        Iterator& operator=(const Iterator& src)
        {
            // TODO: Implement
            mCurr=src.mCurr;
            
            return (*this); // FIX RETURN VALUE
        }
        
        // Incrementors / Decrementors
        // ++i
        Iterator& operator++()
        {
            // TODO: Implement
            
            mCurr=mCurr->mNext;
            
            return (*this); // FIX RETURN VALUE
        }
        
        // i++
        Iterator operator++(int)
        {
            // TODO: Implement
            Iterator retval(*this);
            mCurr=mCurr->mNext;
            return (retval); // FIX RETURN VALUE
        }
        
        // --i
        Iterator& operator--()
        {
            // TODO: Implement
            mCurr=mCurr->mPrev;
            return (*this); // FIX RETURN VALUE
        }
        
        // i--
        Iterator operator--(int)
        {
            // TODO: Implement
            Iterator retval(*this);
            mCurr=mCurr->mPrev;
            return (retval); // FIX RETURN VALUE
        }
        
        // Dereference
        T& operator*() const
        {
            // TODO: Implement
            return mCurr->mData; // FIX RETURN VALUE
        }
        
        Node* operator->() const
        {
            // TODO: Implement
            return mCurr; // FIX RETURN VALUE
        }
        
        // Comparison
        bool operator==(const Iterator& rhs) const
        {
            // TODO: Implement
            
            return mCurr == rhs.mCurr; // FIX RETURN VALUE
        }
        
        bool operator!=(const Iterator& rhs) const
        {
            // TODO: Implement
            
            return (mCurr !=rhs.mCurr); // FIX RETURN VALUE
        }
        
    };
    
    // List functions...
    
    // Function: Default Constructor
    // Purpose: Initializes size to 0 and head/tail to null
    // Input: None
    // Returns: Nothing
    ITPDoubleList()
    {
        mSize = 0;
        mHead = nullptr;
        mTail = nullptr;
    }
    
    // Function: Copy Constructor
    // Purpose: Initializes this list as a deep copy of other
    // Input: Other list to copy (const reference)
    // Returns: Nothing
    ITPDoubleList(const ITPDoubleList& other)
    {
        // TODO: Implement
        
        //        1. Set size to 0, head to null, tail to null
        mSize=0;
        mHead=nullptr;
        mTail=nullptr;
        //        2. Create a temp that points to the head node in “other”
        Node* temp=other.mHead;
        //        3. While temp is not null…
        //        1. Insert_back temp’s data into this list
        //        2. Advance temp to the next node
        while (temp!=nullptr)
        {
            push_back(temp->mData);
            temp=temp->mNext;
        }
        
    }
    
    // Function: Destructor
    // Purpose: Calls the clear function to delete the list
    // Input: None
    // Returns: Nothing
    ~ITPDoubleList()
    {
        // TODO: Implement
        clear();
    }
    
    // Function: clear
    // Purpose: Deletes every node in this list, sets size to 0, and head/tail to null
    // Input: None
    // Returns: Nothing
    void clear()
    {
        // TODO: Implement
        
        //        a) Call remove_front
        //        1. While size > 0…
        while (mSize!=0)
        {
            pop_front();
        }
        
    }
    
    // Assignment Operator
    // Function: Assignment Operator
    // Purpose: Clear this list, and then make a deep copy of other
    // Input: Other list to copy (const reference)
    // Returns: *this
    ITPDoubleList& operator=(const ITPDoubleList& other)
    {
        //            1. Call clear (to clear out any values already in this list)
        clear();
        //            2. Create a temp that points to the head node in “other”
        Node* temp= other.mHead;
        //            3. While temp is not null…
        //                1. Insert_back temp’s data into this list
        //                2. Advance temp to the next node
        while(temp!=nullptr)
        {
            push_back(temp->mData);
            temp=temp->mNext;
        }
        //            4. By convention, operator= returns *this
        
        
        return (*this); // FIX RETURN VALUE
    }
    
    // Function: size
    // Purpose: Gets the current size of the linked list
    // Input: None
    // Returns: size of the list
    unsigned size() const
    {
        // TODO: Implement
        return mSize; // FIX RETURN VALUE
    }
    
    // Function: push_front
    // Purpose: Inserts a node at the front of the linked list
    // Input: Value to store in the new node
    // Returns: Nothing
    void push_front(const T& value)
    {
        // TODO: Implement
        //        1. Dynamically allocate a new node
        
        Node* mNewNode= new Node();
        
        //        a) Set its data to the value
        mNewNode -> mData= value;
        //        b) Set its previous to null (since this will be the new head)
        mNewNode -> mPrev = nullptr;
        //        c) Set its next to the current head
        mNewNode -> mNext = mHead;
        //        2. If the size is 0…The tail is the new node
        if (mSize==0)
        {
            mTail= mNewNode;
        }
        //        3. Otherwise…set the previous of the current head to the new node
        else
        {
            mHead -> mPrev = mNewNode;
        }
        //        4. Set the head to the new node
        mHead = mNewNode;
        //        5. Increment the size
        mSize++;
        
    }
    
    // Function: front
    // Purpose: Gets the value of the node at the front of the list
    // Input: None
    // Returns: Value of the node at the front of the list
    T& front()
    {
        // TODO: Implement
        
        //        1. If the size is 0, error!
        
        if (mSize==0)
        {
            error("Size is 0!!");
        }
        //        2. Return the data at the head node
        
        return (mHead->mData); // FIX RETURN VALUE
    }
    
    // Function: pop_front
    // Purpose: Removes the node at the front of the list
    // Input: None
    // Returns: None
    void pop_front()
    {
        // TODO: Implement
        //        1. If the size is 0…error!
        if (mSize==0)
        {
            error("Size is 0!!");
        }
        //        2. Otherwise if the size is 1…
        //            1. Delete the head node
        //            2. Set head and tail to null, size to 0
        
        else if (mSize==1)
        {
            delete mHead;
            mHead= nullptr;
            mTail= nullptr;
            mSize=0;
        }
        //        3. Otherwise…
        //            1. Set a temp equal to the next node after head
        //            2. Delete the head node
        //            3. The new head is temp
        //            4. The new head previous is now null
        //            5. Decrement size
        else
        {
            Node* temp=(mHead->mNext);
            delete mHead;
            mHead=temp;
            mHead->mPrev=nullptr;
            mSize--;
        }
        
    }
    
    // Function: push_back
    // Purpose: Inserts a node at the end of the linked list
    // Input: Value to store in the new node
    // Returns: Nothing
    void push_back(const T& value)
    {
        // TODO: Implement
        //        1. Dynamically allocate a new node
        Node* mNewNode= new Node();
        
        //        a) Set its data to the value
        
        mNewNode -> mData= value;
        
        //        b) Set its previous to the current tail
        mNewNode -> mPrev = mTail;
        
        //        c) Set the next to null (since this will be the new tail)
        mNewNode -> mNext = nullptr;
        
        //        2. If the size is 0…The head is the new node
        if (mSize == 0)
        {
            mHead=mNewNode;
        }
        //        3. Otherwise…set the next of the current tail to the new node
        else
        {
            mTail-> mNext=mNewNode;
        }
        //        4. Set the tail to the new node
        mTail=mNewNode;
        //        5. Increment the size
        mSize++;
        
    }
    
    // Function: back
    // Purpose: Gets the value of the node at the back of the list
    // Input: None
    // Returns: Value of the node at the back of the list
    T& back()
    {
        // TODO: Implement
        //        1. If the size is 0, error!
        if (mSize==0)
        {
            error("Size is 0!");
        }
        //        2. Return the data at the tail node
        
        return (mTail->mData); // FIX RETURN VALUE
    }
    
    // Function: pop_back
    // Purpose: Removes the node at the end of the list
    // Input: None
    // Returns: None
    void pop_back()
    {
        // TODO: Implement
        //        1. If the size is 0…error!
        if (mSize==0)
        {
            error("Size is 0!");
        }
        //        2. Otherwise if the size is 1…
        //          1. Delete the tail node
        //          2. Set head and tail to null, size to 0
        else if (mSize==1)
        {
            delete mTail;
            mHead=nullptr;
            mTail=nullptr;
            mSize=0;
        }
        //
        //        3. Otherwise…
        //            1. Set a temp equal to the previous node before the tail
        //            2. Delete the tail node
        //            3. The new tail is temp
        //            4. The new tail next is now null
        //            5. Decrement size
        
        else
        {
            Node* temp= mTail->mPrev;
            delete mTail;
            mTail=temp;
            mTail->mNext=nullptr;
            mSize--;
        }
        
    }
    
    // Function: begin
    // Purpose: Gets an iterator for the start of the list
    // Input: None
    // Returns: Iterator pointing to beginning of list
    Iterator begin() const
    {
        // TODO: Implement
        Iterator my_iterator=Iterator(mHead);
        return my_iterator;
        // FIX RETURN VALUE
    }
    
    // Function: end
    // Purpose: Gets an iterator for the end of the list
    // Input: None
    // Returns: Iterator pointing to end of list
    Iterator end() const
    {
        // TODO: Implement
//        Iterator my_iterator2=Iterator(mTail);
        return Iterator(mTail->mNext); // FIX RETURN VALUE
    }
    
    // Function: erase
    // Purpose: Removes the item at the node pointed to by i
    // Input: Iterator pointing to a valid node to remove before
    // Returns: A new iterator pointing to the node after the removed item
    Iterator erase(Iterator& i)
    {
        // TODO: Implement
        
        //        1. If the iterator is invalid … error!
        if (i.mCurr==nullptr)
        {
            error("Nothing to search!!");
            return nullptr;
        }
        //        2. If the iterator is at begin
        //            1. pop_front
        //            2. Return begin
        else if (i.mCurr==mHead)
        {
            pop_front();
            return mHead;
        }
        
        //        3. If the iterator is at the tail
        //            1. pop_back
        //            2. Return end
        
        else if (i.mCurr==mTail)
        {
            pop_back();
            return mTail;
            
        }
        //        4. Otherwise…
        //            1. Make “before”, “after”, and “toDel” pointers
        //            2. Delete “toDel”
        //            3. Set before’s next to after
        //            4. Set after’s previous to before
        //            5. Decrement size
        //            6. Return an iterator to after
        else
        {
            Node* before=i.mCurr->mPrev;
            Node* after=i.mCurr->mNext;
            Node* toDel=i.mCurr;
            delete toDel;
            before->mNext=after;
            after->mPrev=before;
            mSize--;
            return after;
            
        }
//        return *(new Iterator); // FIX RETURN VALUE
    }
    
    // Function: insert
    // Purpose: Inserts a list item before node pointed to by i
    // Input: Iterator pointing to a valid node to insert before
    // Returns: A new iterator pointing to the inserted value
    Iterator insert(Iterator& i, const T& val)
    {
        // TODO: Implement
        //        1. If the iterator is invalid … error!
        if (i.mCurr==nullptr)
        {
            error("Nothing to search!!");
            return nullptr;
        }
        //        2. If the iterator is at begin
        //            1. push_front
        //            2. Return begin
        else if (i.mCurr==mHead)
        {
            push_front(val);
            return mHead;
        }
        //        3. If the iterator is at end
        //            1. push_back
        //            2. Return iterator to last element (not end!)
        
        else if (i.mCurr==mTail->mNext)
        {
            push_back(val);
            return mTail;
        }
        //        4. Otherwise…
        //            1. Make “before” and “after” pointers
        //            2. Dynamically allocate a new node
        //                a) Set its data to the value
        //                b) Set its previous to before
        //                c) Set its next to after
        //            3. Set before’s next to the new node
        //            4. Set after’s previous to the new node
        //            5. Increment size
        //            6. Return an iterator pointing to the inserted node
        
        else
        {
            Node* before=i.mCurr->mPrev;
            Node* after=i.mCurr;
            Node* mNewNode= new Node;
            mNewNode->mData=val;
            mNewNode->mPrev=before;
            mNewNode->mNext=after;
            before->mNext=mNewNode;
            after->mPrev=mNewNode;
            mSize++;
            return mNewNode;
        }
        
        
        
    }
    
    // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    // !!!! DO NOT EDIT BELOW THIS LINE !!!!
    // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
public:
    // Function: Output Stream Operator
    // Purpose: Prints the contents of the list to the provided stream
    // Written in the format of {x, y, ..., z}
    // Input: Stream to write to, list to write
    // Output: Stream after values are written
    friend std::ostream& operator<<(std::ostream& os, const ITPDoubleList<T>& list)
    {
        os << "{";
        
        Node* temp = list.mHead;
        while (temp != nullptr)
        {
            os << temp->mData;
            if (temp != list.mTail)
            {
                os << ",";
            }
            
            temp = temp->mNext;
        }
        
        os << "}";
        return os;
    }
    
    // Function: toString
    // Purpose: Converts list to a string
    // Input: None
    // Output: String (in the format as the ostream)
    std::string toString() const
    {
        std::stringstream str;
        str << *this;
        return str.str();
    }
    
    // Function: toReverseString
    // Purpose: Outputs the list in reverse
    // Input: None
    // Output: String in reverse
    std::string toReverseString() const
    {
        std::stringstream str;
        
        str << "{";
        
        Node* temp = mTail;
        while (temp != nullptr)
        {
            str << temp->mData;
            if (temp != mHead)
            {
                str << ",";
            }
            
            temp = temp->mPrev;
        }
        
        str << "}";
        
        return str.str();
    }
};
