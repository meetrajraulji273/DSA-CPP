#include<bits/stdc++.h>
using namespace std;

//brute-force method ---> T.C ----> O(n * n) ---> S.C ---> O(1)
int cntInversion1(vector<int> &arr){
    int cnt =0;int n = arr.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i] > arr[j]){
                cnt++;
            }
        }
    }
    return cnt;
}

//optimal-approach ---> T.C ---> O(n log n) ---> S.C ---> O(n)
int merge_join(vector<int> &arr,int low,int mid,int high){
    int cnt = 0;
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    while(left<=mid && right <= high){
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
        }else if(arr[right] < arr[left]){
            temp.push_back(arr[right]);
            cnt += mid - left + 1;
            right++;
        }
    }
    while(left <= mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right <= high){
        temp.push_back(arr[right]);
        right++;
    }
    for(int i=low;i<=high;i++){
        arr[i] = temp[i-low];
    }
    return cnt;
}

int merge_sort(vector<int> &arr,int low,int high){
    int cnt = 0;
    if(low >= high) return cnt;
    int mid = low + (high-low)/2;
    cnt += merge_sort(arr,low,mid);
    cnt += merge_sort(arr,mid+1,high);
    cnt += merge_join(arr,low,mid,high);
    return cnt;
}

int cntInversion2(vector<int> &arr){
    int n = arr.size();
    return merge_sort(arr,0,n-1);
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
    cout<<"Number of count inversions are : "<<cntInversion1(arr);
    return 0;
}