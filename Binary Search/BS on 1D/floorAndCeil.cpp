#include<bits/stdc++.h>
using namespace std;

vector<int> floorAndCeil(vector<int> &arr,int target){
    int n = arr.size();
    int floor = -1; int ceil = -1;
    vector<int> temp;
    int low = 0;int high = n -1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(arr[mid] <= target){
            floor = arr[mid];
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    temp.push_back(floor);
    low = 0;high = n - 1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(arr[mid]>=target){
            ceil = arr[mid];
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    temp.push_back(ceil);
    return temp;
}

int main(){
    int n;
    cout<<"Enter the strength of the array : ";
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cout<<"Enter the element arr["<<i<<"] : ";
        cin>>arr[i];
    }
    int target;
    cout<<"Enter the target number : ";
    cin>>target;
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"The floor and the ceil of the array is : ";
    vector<int> temp = floorAndCeil(arr,target);
    for(auto it : temp) cout<<it<<" ";
    return 0;
}