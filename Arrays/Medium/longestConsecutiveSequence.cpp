#include<bits/stdc++.h>
using namespace std;

//brute-force-method ---> T.C ---> O(N*N) ---> S.C ---> O(1);
// bool ls(int arr[],int num,int n){
//     for(int i=0;i<n;i++){
//         if(arr[i] == num){
//             return true;
//         }
//     }
//     return false;
// }

// int longestConsecutiveSequence(int arr[],int n){
//     if(n==0) return 0;
//     int longest = 1;
//     for(int i=0;i<n;i++){
//         int countCurr = 1;
//         int x = arr[i];
//         while(ls(arr,x+1,n)==true){
//             x = x+1;
//             countCurr = countCurr + 1;
//         }
//         longest = max(longest,countCurr); 
//     }
//     return longest;
// }

//better approach ---> T.C ---> O(Nlog N + N) ----> S.C ---> O(1)
// int longestConsecutiveSequence(int arr[],int n){
//     if(n==0) return 0;
//     sort(arr+0,arr+n);
//     int longest = 1;
//     int countCurr = 1;
//     int lastSmaller = arr[0];
//     for(int i=0;i<n;i++){
//         if(arr[i] - lastSmaller == 1){
//             countCurr++;
//             lastSmaller = arr[i];
//         }else if(arr[i]!=lastSmaller){
//             countCurr = 1;
//             lastSmaller = arr[i];
//         }
//         longest = max(longest,countCurr);
//     }
//     return longest;
// }

int longestConsecutiveSequence(int arr[],int n){
    if(n==0) return 0;
    int longest = 1;
    unordered_set<int> st;
    for(int i=0;i<n;i++){
        st.insert(arr[i]);
    }
    for(auto it: st){
        if(st.find(it-1)==st.end()){
            int cnt = 1;
            int x = it;
            while(st.find(x+1)!=st.end()){
                x = x+1;
                cnt = cnt+1;
            }
            longest = max(longest,cnt);
        }
    }
    return longest;
}

int main(){
    int n;
    cout<<"Enter the strength of the array : ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"Enter the element arr["<<i<<"] : ";
        cin>>arr[i];
    }
    cout<<"The length of the longest consecutive sequence is : "<<longestConsecutiveSequence(arr,n);
}