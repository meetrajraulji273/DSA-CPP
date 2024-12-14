#include<bits/stdc++.h>
using namespace std;

void explainBuitinPopcount(){
    int num = 7;
    int count = __builtin_popcount(num);

    cout<<count<<endl;

    long long num2 = 1673987838;
    int count2 = __builtin_popcountll(num2); 

    cout<<count2<<endl;
}

void explainNextPermutation(){
    string s = "123";
    do{
        cout<<s<<endl;
    }while(next_permutation(s.begin(),s.end()));
}

void explainMaxEelement(){
    int arr[] = {1,2,3,4,5,6};

    cout<<*max_element(arr,arr+5)<<endl;
}

int main(){
    cout<<"--------";
    cout<<endl<<endl;
    
    explainMaxEelement();

    cout<<endl<<endl;
    cout<<"--------";
}