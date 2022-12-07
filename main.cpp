#include "bits/stdc++.h"
using namespace std;
#include "vectorlib.cpp"
//azboty al [] mtnseesh
int main() {
   int c[5] ={1,2,3,4,5};
    HMVector<int> m(c,5);
    HMVector<int> v(2);
    cout<<"Size before push:"<<v.size()<<"\n"<<"added Capacity:"<<v.capacity()<<endl;
    v.push_back(1);
    v.push_back(2);
    v.push_back(2);
    cout<<"Vec1 < vec2 :"<<(v<m)<<endl;
    cout<<"Vec1 == vec2 :"<<(v==m)<<endl;
    cout<<"Size after push:"<<v.size()<<"\n"<<"Capacity after resize:"<<v.capacity()<<endl;
    cout<<"Vec:"<<v<<endl;
    v.pop_back();
    cout<<"Vec after pop_back:"<<v<<endl;
    HMVector<int> :: iterator ptr=v.begin()+1;
    v.insert(ptr,9);
    cout<<"Vec after insert:"<<v<<endl;
    cout<<"is vector empty? "<<v.empty();
    v.clear();
    cout<<v<<endl;
    return 0;
}
