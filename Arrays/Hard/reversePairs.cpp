#include <bits/stdc++.h>
using namespace std;

//brute-force method ----> T.C --> O(n * n) ----> S.C ---> O(1)
int reversePairs1(int arr[],int n){
    int count = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i] > 2 * arr[j]){
                count++;
            }
        }
    }
    return count;
}

//optimal-approach --> T.C ---> o(n log n + n) ---> S.C (no extra space)---> O(n)
void mergeJoin(int arr[], int low, int mid, int high)
{
    vector<int> temp;    
    int left = low;  
    int right = mid + 1;

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }

    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}
int countPairs(int arr[], int low, int mid, int high)
{
    int right = mid + 1;
    int cnt = 0;
    for (int i = low; i <= mid; i++)
    {
        while (right <= high && arr[i] > 2 * arr[right])
            right++;
        cnt += (right - (mid + 1));
    }
    return cnt;
}
int mergeSort(int arr[], int low, int high)
{
    int cnt = 0;
    if (low == high)
        return cnt;
    int mid = (low + high) / 2;
    cnt += mergeSort(arr, low, mid);
    cnt += mergeSort(arr, mid + 1, high);
    cnt += countPairs(arr, low, mid, high);
    mergeJoin(arr, low, mid, high);
    return cnt;
}
int reversePairs2(int arr[], int n)
{
    return mergeSort(arr, 0, n - 1);
}

int main()
{
    int n;
    cout << "Enter the strength of the array : ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the element arr[" << i << "] : ";
        cin >> arr[i];
    }
    cout << "Number of reverse pairs are : " << reversePairs1(arr, n);
    return 0;
}