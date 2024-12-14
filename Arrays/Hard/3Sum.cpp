#include<bits/stdc++.h> 
using namespace std;

//brute-force method ---> T.C ---> O(n*n*n) ---> S.C ---> O(2*no. of unique elements + log(no. of unique elemenst))
void threeSum1(int arr[],int n){
    set<vector<int>> st;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                int sum = arr[i] + arr[j] + arr[k];
                if(sum == 0){
                    vector<int> temp = {arr[i], arr[j], arr[k]};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(),st.end());
    cout<<endl;
    cout<<"----------------------"<<endl;
    cout<<"The triplets are as follows : "<<endl;
    int index = 1;
    for(auto it : ans){
        cout<<index<<".) ";
        for(auto it1 : it){
            cout<<it1<<" ";
        }
        cout<<endl;
        index++;
    }  
}

//better-approach ---> T.C ---> O(n*n + log(no. of unique triplets)) ----> S.C ----> O(n + 2 * no. of unique elements)
void threeSum2(int arr[],int n){
    set<vector<int>> st;
    for(int i=0;i<n;i++){
        set<int> hashSet;
        for(int j=i+1;j<n;j++){
            int third = -(arr[i] + arr[j]);
            if(hashSet.find(third) != hashSet.end()){
                vector<int> temp = {arr[i],arr[j],third};
                sort(temp.begin(),temp.end());
                st.insert(temp);
            }
            hashSet.insert(arr[j]);
        }
    }
    vector<vector<int>> ans(st.begin(),st.end());
    cout<<endl;
    cout<<"----------------------"<<endl;
    cout<<"The triplets are as follows : "<<endl;
    int index = 1;
    for(auto it : ans){
        cout<<index<<".) ";
        for(auto it1 : it){
            cout<<it1<<" ";
        }
        cout<<endl;
        index++;
    }
}

//optimal-approach
void threeSum3(int arr[],int n){
    set<vector<int>> st;
    sort(arr,arr+n);
    for(int i=0;i<n;i++){
        int j = i + 1;
        int k = n - 1;
        while(j<k){
            int sum = arr[i] + arr[j] + arr[k];
            if(sum < 0){
                j++;
            }else if(sum > 0){
                k--;
            }else{
                vector<int> temp = {arr[i],arr[j],arr[k]};
                sort(temp.begin(),temp.end());
                st.insert(temp);
                j++;
                k--;
                while(j<k && arr[j] == arr[j-1]) j++;
                while(j<k && arr[k] == arr[k+1]) k--;
            }
        }
    }
    vector<vector<int>> ans(st.begin(),st.end());
    cout<<endl;
    cout<<"----------------------"<<endl;
    cout<<"The triplets are as follows : "<<endl;
    int index = 1;
    for(auto it : ans){
        cout<<index<<".) ";
        for(auto it1 : it){
            cout<<it1<<" ";
        }
        cout<<endl;
        index++;
    }
}

int main(){
    int n;
    cout<<"Enter the strength of the array : ";
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"Enter the element arr["<<i<<"] : ";
        cin>>arr[i];
    }
    threeSum2(arr,n);
    return 0;
}