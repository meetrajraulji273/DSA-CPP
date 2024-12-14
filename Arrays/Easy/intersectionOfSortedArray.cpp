#include<bits/stdc++.h>
using namespace std;

//brute-force-method ----> T.C ----> o(n1 * n2) ----> S.C ---> o(n2)
// void intersectionArray(vector<int> &a,vector<int> &b){
//     int n1 = a.size();
//     int n2 = b.size();
//     vector<int> temp;
//     int visArr[n2] = {0};
//     for(int i=0;i<n1;i++){
//         for(int j=0;j<n2;j++){
//             if(b[j]==a[i] && visArr[j] == 0){
//                 temp.push_back(a[i]);
//                 visArr[j] = 1;
//                 break;
//             }
//             if(b[j] > a[i]){
//                 break;
//             }
//         }
//     }
//     for(auto it : temp){
//         cout<<it<<" ";
//     }
// }

//optimal-method ----> T.C ----> o(n1 + n2) ----> S.C ----> o(1);
void intersectionArray(vector<int> &a,vector<int> &b){
    int n1 = a.size();
    int n2 = b.size();
    int i = 0;
    int j = 0;
    vector<int> temp;
    while(i<n1 && j<n2){
        if(a[i]<b[j]){
            i++;
        }
        if(b[j]<a[i]){
            j++;
        }
        if(a[i] == b[j]){
            temp.push_back(a[i]);
            i++;
            j++;
        }
    }

    for(auto it: temp){
        cout<<it<<" ";
    }
}

int main(){
    vector<int> a;
    int n1;
    cout<<"Enter the strength of the array a[]: ";
    cin>>n1;
    a.resize(n1);
    for(int i=0;i<n1;i++){
        cout<<"Enter the element a["<<i<<"] : ";
        cin>>a[i];
    }
    vector<int> b;
    int n2;
    cout<<"Enter the strength of the array b[] : ";
    cin>>n2;
    b.resize(n2);
    for(int i=0;i<n2;i++){
        cout<<"Enter the element b["<<i<<"] : ";
        cin>>b[i];
    }
    intersectionArray(a,b);

    return 0;    
}