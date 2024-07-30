#include<bits/stdc++.h>
using namespace std;

bool func(int i,vector<int> &a){
    if(i>=a.size()/2) return true;
    if(a[i]!=a[a.size()-i-1]) return false;
    return func(i+1,a);
}

int main(){
    string s ="A man, a plan, a canal: Panama";
    string s1 = "Race a Car";
    string s2 = "Was it a car or a cat I saw?";
    vector<int> a;
    for(auto it: s2){
        if(isalnum(it)){
            a.push_back(tolower(it));
        }
    }
    cout<<func(0,a);
}