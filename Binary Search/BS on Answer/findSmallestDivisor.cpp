#include<bits/stdc++.h>
using namespace std;

//brute-force method ---> T.C --> O(max element in piles[] * n(length of the piles array)) ---> S.C ----> O(1)
int getMaxEl(vector<int> &arr){
    int maxi = INT_MIN;
    int n = arr.size();
    for(int i=0;i<n;i++){
        maxi = max(maxi,arr[i]);
    }
    return maxi;
}

int getSum(vector<int> arr,int k){
    int sum = 0;
    for(int i=0;i<arr.size();i++){
        sum += ceil(double(arr[i])/double(k));
    }
    return sum;
}

int getSmallestDivisor1(vector<int> &arr,int th){
    int maxi = getMaxEl(arr);
    for(int i=1;i<=maxi;i++){
        int sum = getSum(arr,i);
        if(sum<=th){
            return i;
        }
    }
    return -1;
}

//optimal-approach ---> T.C --> O(n(length of the piles[]) * (  log 2 (max element in piles[])  )   )
int getSmallestDivisor2(vector<int> &arr,int th){
    int maxi = getMaxEl(arr); 
    int ans = -1;
    int low = 1;
    int high = maxi;
    while(low <= high){
        int mid = low + (high - low)/2;
        int sum = getSum(arr,mid);
        if(sum<=th){
            ans = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter the strength of the array : ";
    cin>>n;

    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cout<<"Enter the array element arr["<<i<<"] : ";
        cin>>arr[i];
    }

    int th;
    cout<<"Enter the threshold value : ";
    cin>>th;
    cout<<"The smallest divisor which is less than or equal to the threshold is :"<<getSmallestDivisor2(arr,th);
    
    return 0;
}