#include "bits/stdc++.h"
using namespace std;
#include "vectorlib.cpp"
int main() {
   int n[5]={1,2,3,4,5};
    HMVector<int> v(6);
    cout<<v.size()<<endl;
    cout<<v.capacity()<<endl;
    v.resize();
    cout<<v.size()<<endl;
    cout<<v.capacity()<<endl;
    return 0;
}
