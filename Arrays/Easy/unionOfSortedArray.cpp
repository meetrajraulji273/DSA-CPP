#include<bits/stdc++.h>
using namespace std;

//brute-force method ---> T.C ---> o(mlogx + nlogx + m + n)  ----> S.C ---> o(m+n)
// void unionArray(vector<int> a,vector<int> b){
//     int m = a.size();
//     int n = b.size();
//     set<int> s;
//     for(int i=0;i<m;i++){
//         s.insert(a[i]);
//     }
//     for(int i=0;i<n;i++){
//         s.insert(b[i]);
//     }
//     vector<int> ans;
//     for(auto it: s){
//         ans.push_back(it);
//     }
//     for(auto it : ans){
//         cout<<it<<" ";
//     }

// }

//optimal approach ---> T.C --> o(m+n)
void unionArray(vector<int> &a, vector<int> &b) {
    int m = a.size();
    int n = b.size();
    int i = 0, j = 0;
    vector<int> temp;
    
    while (i < m && j < n) {
        if (a[i] <= b[j]) {
            if (temp.empty() || temp.back() != a[i]) {
                temp.push_back(a[i]);
            }
            i++;
        } else {
            if (temp.empty() || temp.back() != b[j]) {
                temp.push_back(b[j]);
            }
            j++;
        }
    }
    while (i < m) {
        if (temp.empty() || temp.back() != a[i]) {
            temp.push_back(a[i]);
        }
        i++;
    }
    while (j < n) {
        if (temp.empty() || temp.back() != b[j]) {
            temp.push_back(b[j]);
        }
        j++;
    }

    for (int i = 0; i < temp.size(); i++) {
        cout << temp[i]<<" ";
    }
}

int main() {
    vector<int> a;
    int m;
    cout << "Enter the size of the array a: ";
    cin >> m;
    a.resize(m);
    for (int i = 0; i < m; i++) {
        cout << "Enter the element a[" << i << "]: ";
        cin >> a[i];
    }

    vector<int> b;
    int n;
    cout << "Enter the size of the array b: ";
    cin >> n;
    b.resize(n);
    for (int i = 0; i < n; i++) {
        cout << "Enter the element b[" << i << "]: ";
        cin >> b[i];
    }

    unionArray(a, b);

    return 0;
}
