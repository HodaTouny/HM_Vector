//
// Created by Hoda Touny on 12/5/2022.
//
#ifndef HM_VECTOR_VECTOR_LIB_H
#define HM_VECTOR_VECTOR_LIB_H
#include "bits/stdc++.h"
using namespace std;
template<class T> class HMVector;

template<class T>
ostream& operator<<(ostream&out,const HMVector<T>& temp);

template<class T>
class HMVector{
private:
    // msh mot2kda mn al iterators kda bas 3l4an al error ymshy!!
    T* Element;
    int Sizee,Capacity;
public:
    using iterator = T*;
    using  iterator1 =T*;
    using iterator2 = T*;

    HMVector (int n);	// Initialize by specific capacity // No content is added, size = 0 // Assign a default size value

    HMVector (T*x,int n );	// Initialize by n items from array

    HMVector (const HMVector & obj);    // Copy Constructor

    ~HMVector()	;		// Delete allocated memory

    HMVector &operator=(const HMVector& obj);  // Copy assignment

    HMVector &operator=(const HMVector && obj); // Move assignment

    T& operator[](int i); // Access item by reference  // Access operations
    // Throw an exception if out of range

    // Modifying operations
    int push_back(T x) ;// Add item to end of vec & return # of items
    // Increase capacity of needed
    T pop_back() ;    // Remove and return last element in vec
    void erase(iterator);      // Remove item at iterator
    // Throw exception if invalid iter
    void erase(iterator1, iterator2);// Remove items between // iterator 1 <= iterator 2 otherwise do nothing // Throw exception if any iterator outside range

    void clear()  ;   // Delete all vector content

    void insert(iterator, T)  ;     // Insert item at iterator
    // Throw exception if invalid // Iterators 		// Supports *, + and ++ operations at least
// Can use: typedef T* iterator // Or u can use std::iterator so you can // apply STL algorithms on XYVector

    iterator begin(){
        return iterator(Element);
    } // Return an iterator (T*)

    iterator end(){
        return iterator(Element+size());
    }	// Return an iterator (T*)

// Comparison operations
    bool operator==(const HMVector<T>& obj) ;// Return true if ==
    bool operator< (const HMVector<T>& obj); // Compares item by item
    // Return true if first different item in this is < in other

// Capacity operations
    int size() const{return Sizee;}    // Return current size of vec
    int capacity() const{return Capacity;}// Return size of current allocated array
    int resize()    ;     // Relocate to bigger space
    bool empty()  ;       // Return true if size is 0

// Friend
    friend ostream& operator<< <T> (ostream& out, const HMVector<T>& temp);

};

#endif //HM_VECTOR_VECTOR_LIB_H
