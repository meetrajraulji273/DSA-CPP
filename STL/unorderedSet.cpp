#include<bits/stdc++.h>
using namespace std;

void explainUnorderedSet(){
    unordered_set<int> s;
    s.insert(7);
    s.insert(2);
    s.emplace(5);

    for(auto it: s){
        cout<<it<<" ";
    }

    for(auto it : s){
        cout<<it<<" ";
    }
}

int main(){
    cout<<"--------";
    cout<<endl<<endl;
    
    cout<<endl<<endl;
    cout<<"--------";
}