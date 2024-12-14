#include<bits/stdc++.h>
using namespace std;

//brute-force method ---> T.C ---> O(n*n*n*n* log(no. of quads)) ----> S.C ---> O(2 * no. of quads) 
void fourSum1(int arr[],int n,int target){
    set<vector<int>> st;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                for(int l=k+1;l<n;l++){
                    int sum = arr[i] + arr[j];
                    sum = sum + arr[k];
                    sum = sum + arr[l];
                    if(sum == target){
                        vector<int> temp = {arr[i],arr[j],arr[k],arr[l]};
                        sort(temp.begin(),temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(),st.end());
    for(auto it : ans){
        for(auto it2 : it){
            cout<<it2<<" ";
        }
        cout<<endl;
    }
}

//better-approach method ---> T.C ---> O(n*n*n* log(no. of quads)) ----> S.C ---> O(2 * no. of quads + n)
void fourSum2(int arr[],int n,int target){
    set<vector<int>> st;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            set<int> hashset;
            for(int k=j+1;k<n;k++){
                int sum = arr[i] + arr[j];
                sum = sum + arr[k];
                int fourth = target - sum;
                if(hashset.find(fourth) != hashset.end()){
                    vector<int> temp = {arr[i],arr[j],arr[k],fourth};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
                hashset.insert(arr[k]);
            }
        }
    }
    vector<vector<int>> ans(st.begin(),st.end());
    for(auto it : ans){
        for(auto it1 : it){
            cout<<it1<<" ";
        }
        cout<<endl;
    }
}

//optimal-approach method ---> T.C ---> O(n*n*n) ----> S.C(no extra space is used) ---> O(2 * no. of quads )
void fourSum3(int arr[],int n,int target){
    vector<vector<int>> ans;
    sort(arr,arr+n);
    for(int i=0;i<n;i++){
        if(i>0 && arr[i-1] == arr[i]) continue;
        for(int j=i+1;j<n;j++){
            if(j>i+1 && arr[j-1] == arr[j]) continue;
            int k = j+1;
            int l = n-1;
            while(k<l){
                int sum = arr[i] + arr[j] + arr[k] + arr[l];
                if(sum < target){
                    k++;
                }else if(sum > target){
                    l--;
                }else{
                    vector<int> temp = {arr[i],arr[j],arr[k],arr[l]};
                    ans.push_back(temp);
                    k++;
                    l--;
                    while(k<l && arr[k-1] == arr[k]) k++;
                    while(k<l && arr[l+1] == arr[l]) l--;
                }
            }
        }
    }
    for(auto it : ans){
        for(auto it2 : it){
            cout<<it2<<" ";
        }
        cout<<endl;
    }
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
    int target;
    cout<<"Enter the target sum : ";
    cin>>target;
    fourSum3(arr,n,target);
    return 0;
}