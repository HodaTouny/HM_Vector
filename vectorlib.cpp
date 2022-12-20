/**
 * @file vectorlib.cpp
 * @author hoda samir/maya hesham
 * @brief Implementation of the HMVector class
 * @version 0.1
 * @date 2022-12-05
 * @copyright Copyright FCAI (c) 2022
 */
#include "vectorlib.h"
// Constructors and Big 4
/**
    * @brief Construct a new HMVector object
    * @param n
  */

template<class T>
HMVector<T>::HMVector(int n){
    Sizee=0;
    Capacity=n;
    Element = new T[Capacity];
}
/**
    * @brief Construct a new HMVector object
    * @param x
    * @param n
  */

template<class T>
HMVector<T>::HMVector(T*x,int n) {
    Sizee=n;
    Capacity=n;
    Element = new T[Capacity];
    for (int i = 0; i < n; ++i) {
        Element[i] = x[i];
    }

}
/**
    * @brief Construct a new HMVector object
    * @param obj
  */

template<class T>
// Copy Constructor
HMVector<T>::HMVector(const HMVector& obj) {
    Sizee=obj.Sizee;
    Capacity=obj.Capacity;
    Element = new T[Capacity];
    for (int i = 0; i < Sizee; ++i) {
        Element[i] = obj.Element[i];
    }
}
/**
    * @brief Destroy the HMVector object
    * @param obj
  */

template<class T>
HMVector<T> & HMVector<T>::operator=(const HMVector &obj) {
    if (this != &obj) {
        delete[] Element;
        Sizee = obj.Sizee;
        Capacity = obj.Capacity;
        Element= new T [Capacity];
        for (int i = 0; i < Sizee; i++)
           Element[i] = obj.Element[i];
    }
    return *this;

}
/**
    * @brief Destroy the HMVector object
    * @param obj
  */
template<class T>
HMVector<T> &HMVector<T>::operator=(const HMVector &&obj) {
    if (this != &obj) {
       delete[] Element;
       Element = obj._data;
        Sizee = obj.Sizee;
        Capacity = obj.Capacity;
        obj.Element = nullptr;
        obj.Sizee = 0;
        obj.Capacity = 0;
    }
    return *this;
    }
/**
    * @brief Destroy the HMVector object
  */
template<class T>
HMVector<T>::~HMVector() {
    delete [] Element;
}
// Access operations
/**
    * @brief Access item by reference
    * @param i
    * @return T&
  */
template<class T>
T &HMVector<T>::operator[](int i) {
    if (i < 0 || i > this->size() - 1) {
        throw invalid_argument("out of index");
    } else {
        return *(this->Element + i);

    }
}
// Modifying operations
/**
    * @brief Add item to end of vec & return # of items
    * @param x
  */
template<class T>
int HMVector<T> ::push_back(T x) {
    if(this->size()>=this->capacity()){
        this->resize();
        Element[size()] = x;
    }else{
        Element[size()] = x;
    }
    this->Sizee+=1;
    return this->size();
}
/**
    * @brief Remove last item & return it
    * @return T
  */
template<class T>
T HMVector<T> ::pop_back() {
    T temp = Element[Sizee - 1];
    T *newArray = new T[Sizee-1];
    for (int i = 0; i < Sizee-1; ++i) {
        newArray[i]=Element[i];
    }
    delete[] Element;
    Element = newArray;
    newArray= nullptr;
    Sizee--;
    return temp;
}
/**
    * @brief erase item at position
    * @param pos
  */
template<class T>
void HMVector<T> ::erase(iterator pos){
    int index = pos -begin();
    T temp = Element[index];
    T *newArray = new T[Sizee-1];
    for (int i = 0; i < index; ++i) {
        newArray[i]=Element[i];
    }
    for (int i = index; i < Sizee; ++i) {
        newArray[i]=Element[i+1];
    }
    delete[] Element;
    Sizee--;
    Element = newArray;
    newArray= nullptr;
}
/**
    * @brief erase items in range
    * @param pos1
    * @param pos2
  */
template<class T>
void HMVector<T> ::erase(iterator1 pos1, iterator2 pos2) {
    int index = pos1 -begin();
    int index2=pos2 - begin() ;
    int newSize=Sizee-(index2-index);
    T* newarr=new T[newSize] ;
    if(index<index2){
        for (int i=0;i<index;i++){
            newarr[i]=Element[i];
        }
        for(int j=0;j<Sizee-index2;j++){
            newarr[j+index]=Element[j+index2];
        }
        delete[] Element;
        Element = newarr;
        newarr= nullptr;
        Sizee=newSize;
    }
}
/**
    * @brief clear all items
  */
template<class T>
void HMVector<T> ::clear() {
    this->Sizee =0;
    for(int i=0;i<this->size();i++){
        this->Element[i] =0;
    }
}
/**
    * @brief insert item at position
    * @param pos
    * @param x
  */
template<class T>
void HMVector<T> ::insert(iterator pos, T x){
    if(Sizee >= Capacity){
        this->resize();
    }
    T temp[Capacity];
    for (int i = 0; i<Sizee; ++i) {
        temp[i] = Element[i];
    }
    int index = pos - Element;
    delete [] Element;
    Element = new T[Capacity];
   for(int i=0;i<index;i++){
       Element[i] = temp[i];
   }
   Element[index] = x;
    for(int i=index;i<=Sizee;i++){
        Element[i+1] = temp[i];
    }
    Sizee+=1;
}
//Comparison operations
/**
    * @brief compare two vectors
    * @param obj
    * @return true
    * @return false
  */
template<class T>
bool HMVector<T> ::operator==(const HMVector<T>& obj){
    if(this->size()!= obj.size()){
        return false;
    }else{
        for(int i=0;i<this->size();i++){
            if(Element[i] != obj.Element[i]){
                return false;
            }
        }
    }
    return true;

}
/**
    * @brief compare two vectors
    * @param obj
    * @return true
    * @return false
  */
template<class T>
bool HMVector<T> ::operator< (const HMVector<T>& obj){
    int x =0;
    if(Sizee> obj.Sizee){
        x = Sizee;
    }else{
        x = obj.Sizee;
    }
    for(int i=0;i<x;i++){
        if(Element[i] != obj.Element[i]){
            if(Element[i]<obj.Element[i]){
                return true;
            }else{
                return false;
            }
        }
    }}
// Capacity operations
/**
    * @brief resize vector
    * @return int
  */
template<class T>
int HMVector<T> ::resize(){
    T temp[Capacity*2];
    for (int i = 0; i < Sizee; ++i) {
        temp[i] = Element[i];
    }
    delete [] Element;
    Element = new T[Capacity*2];
    for (int i = 0; i < Sizee; ++i) {
        Element[i] = temp[i];
    }
    Capacity*=2;
}
/**
    * @brief check if vector is empty
    * @return int
  */
template<class T>
bool HMVector<T>::empty() {
    int x = size();
    if(x==0)
        return true;
    else
        return false;
}
//friends
/**
    * @brief print vector
    * @param out
    * @param temp
    * @return ostream&
  */
template<class T>
ostream& operator <<(ostream& out, const HMVector<T>& temp){
    for(int i=0;i<temp.Sizee;i++){
        out<<temp.Element[i]<<" ";
    }
    return out;
}
