//
// Created by Hoda Touny on 12/5/2022.
//
#include "vectorlib.h"
template<class T>
HMVector<T>::HMVector(int n){
    Sizee=0;
    Capacity=n;
    Element = new T[Capacity];
}

template<class T>
HMVector<T>::HMVector(T*x,int n) {
    Sizee=n;
    Capacity=n;
    Element = new T[Capacity];
    for (int i = 0; i < n; ++i) {
        Element[i] = x[i];
    }

}

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

template<class T>
HMVector<T>::~HMVector() {
    delete [] Element;
}
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
template<class T>
HMVector<T> &HMVector<T>::operator=(const HMVector &&obj) {
    if (this != &obj) {
        delete[] Element;
        Sizee = obj.Sizee;
        Capacity = obj.Capacity;
        Element= new T [Capacity];
        for (int i = 0; i < Sizee; i++)
            Element[i] = obj.Element[i];



       Element = obj._data;
        Sizee = obj.Sizee;
        Capacity = obj.Capacity;
        obj.Element = nullptr;
        obj.Sizee = 0;
        obj.Capacity = 0;
    }
    return *this;
    }






template<class T>
T &HMVector<T>::operator[](int i) {
    if( i<0 || i > this->size()-1)
    {

        //cout<<"Array index isn't found.\n";
        //throw invalid_argument("out of index");
        exit(0);
    }else {
        return *(this->Element + i);
    }

}
template<class T>
int HMVector<T> ::push_back(T x) {
    if(this->size()> this->capacity()){
        this->resize();
        Element[size()] = x;
    }else{
        Element[size()] = x;
    }
    this->Sizee+=1;
}
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


template<class T>
void HMVector<T> ::erase(iterator) {

}
template<class T>
void HMVector<T> ::erase(iterator1, iterator2) {

}
template<class T>
void HMVector<T> ::clear() {
    this->Sizee =0;
    for(int i=0;i<this->size();i++){
        this->Element[i] =0;
    }
}
template<class T>
void HMVector<T> ::insert(iterator, T) {

}
/*template<class T>
iterator HMVector<T> ::begin() {

}
template<class T>
iterator HMVector<T> ::end() {

}*/
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
template<class T>
bool HMVector<T> ::operator< (const HMVector<T>& obj){
    int x =0;
    if(this->size()> obj.size()){
        x = this->size();
    }else{
        x = obj.size();
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
template<class T>
int HMVector<T> ::size() const{
    return Sizee;
}
template<class T>
int HMVector<T> ::capacity() const {
    return Capacity;
}
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
template<class T>
bool HMVector<T>::empty() {
    int x = size();
    if(x==0)
        return true;
    else
        return false;
}

template<class T>
ostream& operator <<(ostream& out, const HMVector<T>& temp){
    for(int i=0;i<temp.Sizee;i++){
        out<<temp.Element[i]<<" ";
    }
    return out;
}
