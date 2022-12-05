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
HMVector<T>::HMVector(const HMVector &obj) {

}
template<class T>
HMVector<T>::~HMVector() {
    delete [] Element;
}
template<class T>
HMVector<T> & HMVector<T>::operator=(const HMVector &obj) {

}
template<class T>
HMVector<T> &HMVector<T>::operator=(const HMVector &&obj) {

}
template<class T>
T &HMVector<T>::operator[](int) {

}
template<class T>
int HMVector<T> ::push_back(T) {

}
template<class T>
T HMVector<T> ::pop_back() {

}
template<class T>
void HMVector<T> ::erase(iterator) {

}
template<class T>
void HMVector<T> ::erase(iterator1, iterator2) {

}
template<class T>
void HMVector<T> ::clear() {

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
bool HMVector<T> ::operator==(const HMVector<T>& obj) {

}
template<class T>
bool HMVector<T> ::operator< (const HMVector<T>& obj) {

}
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

}

/*template<class T>

ostream& operator << (ostream& out, const HMVector<T>& temp){
    for(int i=0;i<temp.Sizee;i++){
        out<<temp.Element[i]<<" ";
    }
    return out;
}
*/