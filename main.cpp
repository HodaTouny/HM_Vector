#include "bits/stdc++.h"
using namespace std;
#include "vectorlib.cpp"
int main() {
   int n[5]={1,2,3,2,5};
   int c[5] ={1,2,3,4,5};
    HMVector<int> v(2);
    HMVector<int> m(c,5);
   // cout<<v[6]<<endl;
   // cout<<v[3]<<endl;
    //cout<<v.size()<<" "<<v.capacity()<<endl;
   v.push_back(7);
   v.push_back(5);
   v.push_back(4);
   HMVector<int> :: iterator ptr;
   for(ptr = v.begin();ptr<v.end();ptr++){
        cout<<*ptr<<" ";
   }

  //cout<<v.size()<<" "<<v.capacity()<<endl;
    return 0;
}
