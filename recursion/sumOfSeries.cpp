#include<bits/stdc++.h>
using namespace std;
// input : 3
// 1*1*1 + 2*2*2 + 3*3*3 = 36
long long sumOfSeries(long long n){
    if(n<1) return 0;
    return n*n*n + sumOfSeries(n-1);
}
int main(){
    long long n;
    cout<<"Enter the series no. : ";
    cin>>n;
    cout<<sumOfSeries(n);
}