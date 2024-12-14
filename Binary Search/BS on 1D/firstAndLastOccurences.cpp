#include<bits/stdc++.h>
using namespace std;

//brute-force method ---> T.C ---> O(n) ---> S.C ---> O(1)
vector<int> firstAndLastOccurences1(vector<int> &arr,int n,int target){
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int first = -1;int last = -1;
    for(int i=0;i<n;i++){
        if(arr[i]==target){
            if(first == -1) first = i;
            last = i;
        }
    }
    return {first,last};
}

//better-approach ---> T.C ---> O(log 2 N + log 2 N) ---> S.C ---> O(1)
int lower_bound1(vector<int> &arr,int target){
    int low = 0;
    int  high = arr.size() - 1;
    int ans = arr.size();
    while(low<=high){
        int mid = low + (high - low)/2;
        if(arr[mid] >= target){
            ans = mid;
            high = mid-1;
        }else if(arr[mid] < target){
            low = mid + 1;
        }
    }
    return ans;
}
int upper_bound1(vector<int> &arr,int target){
    int low = 0;
    int  high = arr.size() - 1;
    int ans = arr.size();
    while(low<=high){
        int mid = low + (high - low)/2;
        if(arr[mid] > target){
            ans = mid;
            high = mid-1;
        }else{
            low = mid + 1;
        }
    }
    return ans;
}
vector<int> firstAndLastOccurences2(vector<int> &arr,int n,int target){
    sort(arr.begin(),arr.end());
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    if(lower_bound1(arr,target)==arr.size() || arr[lower_bound1(arr,target)] != target) return {-1,-1};
    return {lower_bound1(arr,target),upper_bound1(arr,target)-1};
}

//optimal-approach ---> T.C ----> O() ----> S.C ---> O()
int firstOccurences(vector<int> &arr,int n,int target){
    int first = -1;
    int low = 0;int high = n-1;
    while(low<=high){
        int mid = low + (high - low)/2;
        if(arr[mid]==target){
            first = mid;
            high = mid -1;
        }else if(arr[mid]>target){
            high = mid -1;
        }else{
            low = mid + 1;
        }
    }
    return first;
}
int lastOccurences(vector<int> &arr,int n,int target){
    int last = -1;
    int low = 0;int high = n-1;
    while(low<=high){
        int mid = low + (high - low)/2;
        if(arr[mid] == target){
            last = mid;
            low = mid + 1;
        }else if(arr[mid]>target){
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return last;
}

vector<int> firstAndLastOccurences3(vector<int> &arr,int n,int target){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int first = firstOccurences(arr,n,target);
    if(first == -1) return {-1,-1};
    int last = lastOccurences(arr,n,target);
    return {first,last};
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
    vector<int> temp = firstAndLastOccurences3(arr,n,target);
    cout<<"The first and the last occurences of the number is : ";
    for(auto it : temp){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}