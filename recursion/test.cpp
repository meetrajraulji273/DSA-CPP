#include<bits/stdc++.h>
using namespace std;

bool func(int i,vector<char>&a){
        if(i>=a.size()/2) return true;
        if(a[i]!=a[a.size()-i-1]) return false;
        return func(i+1,a);
}

bool isPalindrome(string &s){
    vector<char>a;
    for(auto it:s){
        if(isalnum(it)){
            a.push_back(it);
        }
    }
    cout<<func(0,a);  
}
      
int main(){
    cout<<"--------";
    cout<<endl<<endl;

    cout<<isalnum('k')<<endl;

    string s = "A man, a plan, a canal: Panama";
    isPalindrome(s);
    
    cout<<endl<<endl;
    cout<<"--------";
}