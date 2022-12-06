#include "bits/stdc++.h"
using namespace std;
#include "vectorlib.cpp"
int main() {
   int n[5]={1,2,3,2,5};
   int c[5] ={1,2,3,4,5};
    HMVector<int> v(n,5);
    HMVector<int> m(c,5);
    cout<<v[6]<<endl;
    //cout<<v[3]<<endl;
    return 0;
}
