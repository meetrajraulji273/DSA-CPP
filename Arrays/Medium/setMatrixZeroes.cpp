#include<bits/stdc++.h>
using namespace std;

//brute-force-method 
// void col(int j,vector<vector<int>> &arr,int n){
//     for(int i=0;i<n;i++){
//         if(arr[i][j]!=0){
//             arr[i][j] = -1;
//         }
//     }
// }
// void row(int i,vector<vector<int>> &arr,int m){
//     for(int j=0;j<m;j++){
//         if(arr[i][j]!=0){
//             arr[i][j] = -1;
//         }
//     }
// }
// void setMatrixZeroes(vector<vector<int>> &arr,int n,int m){
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             if(arr[i][j] == 0){
//                 col(j,arr,n);
//                 row(i,arr,m);
//             }
//         }
//     }
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             if(arr[i][j]==-1){
//                 arr[i][j] = 0;
//             }
//         }
//     }
//     cout<<"Matrix after : "<<endl;
//     for(int  i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             cout<<arr[i][j]<<" ";
//         }
//         cout<<endl;
//     }
// }

//better-approach
// void setMatrixZeroes(vector<vector<int>> &arr,int n,int m){
//     int col[m] = {0};
//     int row[n] = {0};
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             if(arr[i][j] == 0){
//                 row[i] = 1;
//                 col[j] = 1;
//             }
//         }
//     }
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             if(arr[i][j] != 0){
//                 if(row[i] == 1 || col[j] == 1){
//                     arr[i][j] = 0;
//                 }
//             }
//         }
//     }
//     cout<<"Matrix after : "<<endl;
//     for(int  i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             cout<<arr[i][j]<<" ";
//         }
//         cout<<endl;
//     }
// }

//optimal-approach
void setMatrixZeroes(vector<vector<int>> &arr,int n,int m){
    int col0 = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==0){
                arr[0][j] = 0;
                if(j!=0){
                    arr[i][0] = 0;
                }else{
                    col0 = 0;
                }
            }
        }
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(arr[i][0] == 0 || arr[0][j] == 0){
                arr[i][j] = 0;
            }
        }
    }
    if(arr[0][0] == 0){
        for(int j=0;j<m;j++){
            arr[0][j] = 0;
        }
    }
    if(col0 == 0){
        for(int i=0;i<n;i++){
            arr[i][0] = 0;
        }
    }

    cout<<"Matrix after : "<<endl;
    for(int  i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int n,m;
    cout<<"Enter the no. of rows and columns of arrays : ";
    cin>>n>>m;
    vector<vector<int>> arr(n, vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<"Enter the element arr["<<i<<"]["<<j<<"] : ";
            cin>>arr[i][j];
        }
    }
    cout<<"Matrix before : "<<endl;
    for(int  i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    setMatrixZeroes(arr,n,m);
    return 0;
}