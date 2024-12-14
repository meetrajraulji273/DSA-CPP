#include<bits/stdc++.h>
using namespace std;

//brute-force method ---> T.C --> O(max element in piles[] * n(length of the piles array)) ---> S.C ----> O(1)
int getMaxEl(vector<int> &piles){
    int maxi = INT_MIN;
    int n = piles.size();
    for(int i=0;i<n;i++){
        maxi = max(maxi,piles[i]);
    }
    return maxi;
}

int getTotalHours(vector<int> &piles,int hourly){
    int total_hours = 0;
    int n = piles.size();
    for(int i=0;i<n;i++){
        total_hours += ceil(double(piles[i])/double(hourly));
    }
    return total_hours;
}

int getKValue1(vector<int> &piles,int hours){
    int maxi = getMaxEl(piles);
    for(int i=1;i<=maxi;i++){
        int total_hours = getTotalHours(piles,i);
        if(total_hours<=hours){
            return i;
        }
    }
    return -1;
}

//optimal-approach ---> T.C --> O(n(length of the piles[]) * (  log 2 (max element in piles[])  )   )
int getKValue2(vector<int> &piles,int hours){
    int maxi = getMaxEl(piles);
    int low = 1;
    int high = maxi;
    int ans;
    while(low <= high){
        int mid = low + (high - low)/2;
        int total_hours = getTotalHours(piles,mid);
        if(total_hours<=hours){
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
    cout<<"Enter the strength of the piles array : ";
    cin>>n;
    vector<int> piles(n);
    for(int i=0;i<n;i++){
        cout<<"Enter the number of bannana's in the piles["<<i<<"] : ";
        cin>>piles[i];
    }
    int hrs;
    cout<<"Enter the number of hours within the piles of bannana's should be finished ";
    cin>>hrs;

    cout<<"The min integer k bannana's/hr that finishes the pile within given hours is : "<<getKValue2(piles,hrs);

    return 0;
}