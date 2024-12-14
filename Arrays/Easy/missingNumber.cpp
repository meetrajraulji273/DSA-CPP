#include<bits/stdc++.h>
using namespace std;

//brute-force-method ---> T.C ----> o(n*n) ----> S.C ----> o(1)
// int findMissingNum(int arr[],int n){
//     for(int i=1;i<=n;i++){
//         int flag = 0;
//         for(int j=0;j<n-1;j++){
//             if(arr[j] == i){
//                 flag = 1;
//                 break;
//             }
//         }
//         if(flag == 0) return i;
//     }
// }


//better-approach ---> T.C ----> o(n+n) ----> sc ----> o(n);
// int findMissingNum(int arr[],int n){
//     int hash[n+1] = {0};
//     for(int i=0;i<n-2;i++){
//         hash[arr[i]] = 1;
//     }
//     for(int i=1;i<=n;i++){
//         if(hash[i] == 0) return i;
//     }
// }

//optimal-approach ----> T.C ----> o(n) ----> sc ----> o(1)
// int findMissingNum(int arr[],int n){
//     int sum = n*(n+1)/2;
//     for(int i=0;i<=n-2;i++){
//         sum = sum - arr[i];
//     }
//     return sum;
// }

//most-optimal-approach ----> XOR approach ----> T.C -----> o(n) -----> S.C ----> o(always stores a number which smaller in size inside the xor variable)
int findMissingNum(int arr[],int n){
    int xor1 = 0;
    int xor2 = 0;
    for(int i=0;i<n-1;i++){
        xor1 = xor1 ^ i+1;
        xor2 = xor2 ^ arr[i];
    }
    xor1 = xor1 ^ n;
    return xor1 ^ xor2;
}

int main(){
    int n;
    cout<<"Enter the strength of the array : ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements between 1 to "<<n<<" and missing 1 number : ";
    for(int i=0;i<n-1;i++){
        cout<<"Enter the element arr["<<i<<"] : ";
        cin>>arr[i];
    }
    int missNum = findMissingNum(arr,n);
    cout<<"The missing number is : "<<missNum; 
    return 0;
}