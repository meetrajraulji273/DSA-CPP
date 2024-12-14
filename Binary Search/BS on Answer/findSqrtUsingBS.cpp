#include<bits/stdc++.h>
using namespace std;

//brute-force method ---> T.C ---> O(n) ----> S.C ----> O(1)
int findSqrtUsingBS1(int target){
    int ans = 1;
    for(int i=1;i<=target;i++){
        if(i*i <= target){
            ans = i;
        }
    }
    return ans;
}

//optimal-approach ---> T.C ---> O(log 2 n) --->  S.C ---> O(1)
int findSqrtUsingBS2(int target){
    int low = 1;
    int high = target;
    int ans = 1;
    while(low<=high){
        long long mid = low + (high -low)/2;
        long long value = mid * mid;
        if(value<=target){
            ans = mid;
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    return ans;
}

int main(){
    int target;
    cout<<"Enter the number whose square root you want to find : ";
    cin>>target;
    cout<<"The square root of the targeted number is : "<<findSqrtUsingBS2(target);
}