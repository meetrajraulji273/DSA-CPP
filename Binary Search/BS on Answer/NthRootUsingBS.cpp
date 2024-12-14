#include<bits/stdc++.h>
using namespace std;

//brute-force method ---> T.C ---> O(n) ---> S.C ---> O(1)
int func(int i,int n){
    long long  ans = 1;
    long long base = i;
    while (n > 0) {
        if (n % 2) {
            n--;
            ans = ans * base;
        }
        else {
            n /= 2;
            base = base * base;
        }
    }
    return ans;
}

int NthRootUsingBS1(int target,int n){
    int ans = 1;
    for(int i=1;i<=target;i++){
        long long val = func(i, n);
        if(val==target){
            ans = i;
        }else if(val>target){
            break;
        }
    }
    return ans;
}

//optimal-approach ---> T.C ---> O(log 2 m) ----> S.C ---> O(1)
int Func(int mid ,int n,int target){
    int ans = 1;
    for(int i=1;i<=n;i++){
        ans = ans * mid;
        if(ans > target) return 0;
    }
    if(ans == target) return 1;
    else return 2;
}

int NthRootUsingBS2(int target,int n){
    int low = 1;int high = target;
    while(low <= high){
        int mid = low + (high -low)/2;
        long long value = Func(mid,n,target);
        if(value == 1) return mid;
        else if(value == 0) high = mid - 1;
        else low = mid + 1;
    }
    return -1;
}

int main(){
    int target;
    cout<<"Enter the target number for which you want to find Nth root :";
    cin>>target;
    int n;
    cout<<"Enter the root which you want to calculate ";
    cin>>n;
    cout<<"The nth root of the targeted number is : "<<NthRootUsingBS2(target,n);
}