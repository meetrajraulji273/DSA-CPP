#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cout<<"Enter the string : ";
    cin>>s;

    //pre storing or pre compute
    //for string ranging between 'a'-'z'
    int hash[26] = {0};
    for(int i=0;i<s.size();i++){
        hash[s[i]-'a'] += 1;
    }

    //for string ranging between any ascii code charcter 0-255
    int hashh[256] = {0};
    for(int i=0;i<s.size();i++){
        hashh[s[i]] += 1;
    }

    int q;
    cout<<"Enter the no. of queries : ";
    cin>>q;
    while(q--){
        char ch;
        cout<<"Enter the character : ";
        cin>>ch;
        cout<<"Entered character occurs : "<<hashh[ch]<<endl;
    }
}