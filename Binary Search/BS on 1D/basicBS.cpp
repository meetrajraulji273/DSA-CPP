#include <bits/stdc++.h>
using namespace std;

//iterative-approach --> T.C ---> O(log 2 N) ---> S.C ---> O(1)
int binary_search1(vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;  // Avoiding integer overflow
        if (arr[mid] == target) return mid;
        else if (target > arr[mid]) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

//recursive-approach ---> T.C ---> O(log 2 N) ---> S.C ----> O(1);
int recursive_bs(vector<int> &arr,int low, int high, int target){
    int mid = low + (high - low)/2;
    if(low > high) return -1;
    if(target == arr[mid]) return mid;
    else if(target > arr[mid]) recursive_bs(arr,mid+1,high,target);
    else recursive_bs(arr,low,mid-1,target);
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);  // Using std::vector instead of VLA
    for (int i = 0; i < n; i++) {
        cout << "Enter the element arr[" << i << "] : ";
        cin >> arr[i];
    }

    int target;
    cout << "Enter the target number: ";
    cin >> target;
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int result = recursive_bs(arr,0,arr.size()-1,target);
    if (result != -1) {
        cout << "The number is present at index: " << result << endl;
    } else {
        cout << "The number is not present in the array." << endl;
    }

    return 0;
}
