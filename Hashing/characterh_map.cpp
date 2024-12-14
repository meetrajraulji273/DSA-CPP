#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cout<<"Enter the string : ";
    cin>>s;

    //pre compute
    map<char,int> mpp;
    for(int i=0;i<s.size();i++){
        mpp[s[i]]++;
    }

    for(auto it : mpp){
        cout<<it.first<<"->"<<it.second<<endl;
    }

    int q;
    cout<<"Enter the number of queries : ";
    cin>>q;
    while(q--){
        char ch;
        cout<<"Enter the character : ";
        cin>>ch;
        cout<<"Entered character occurs : "<<mpp[ch]<<endl;
    }
}