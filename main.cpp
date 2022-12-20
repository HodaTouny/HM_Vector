#include "bits/stdc++.h"
using namespace std;
#include "vectorlib.cpp"
int main() {
   int n[5]={1,2,3,2,5};
   int c[5] ={1,2,3,4,5};
    HMVector<int> v(2);
    HMVector<int> m(c,5);
        cout << m[1] << endl;


    //cout<<v.size()<<" "<<v.capacity()<<endl;
   v.push_back(7);
   v.push_back(5);
   v.push_back(4);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    HMVector<int> :: iterator ptr=v.begin()+2;
   HMVector<int> :: iterator ptr2=v.begin()+4;
   cout<<v<<endl;
  // v.insert(ptr,9);
    v.erase(ptr);
    cout<<v;
    cout<<endl;
   // cout << m[6] << endl;
  //cout<<v.size()<<" "<<v.capacity()<<endl;
    return 0;
}
