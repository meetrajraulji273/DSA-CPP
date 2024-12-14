#include<bits/stdc++.h>
using namespace std;

//pass by value
void doSomething(string s){
    cout<<s<<endl;
    s[0] = 't';
    cout<<s<<endl;
}

int main(){
    cout<<"--------";
    cout<<endl<<endl;

    string s = "Meetraj";

    doSomething(s);
    cout<<s<<endl;

    
    cout<<endl<<endl;
    cout<<"--------";
    return 0;
}