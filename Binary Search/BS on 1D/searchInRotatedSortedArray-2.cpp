#include <bits/stdc++.h>
using namespace std;

// The array may have dupliactes
// optimal-approach ---> T.C --> average case ----> O(log 2 N)
// ---> T.C ---> worst case ----> O(n/2) ----> S.C ----> O(1)
bool searchInRotatedSortedArray(vector<int> &arr, int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
            return true;
        if (arr[low] == arr[mid] && arr[mid] == arr[high])
        {
            low++;
            high--;
            continue;
        }
        if (arr[low] <= arr[mid])
        {
            if (arr[low] <= target && target <= arr[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        else
        {
            if (arr[mid] <= target && target <= arr[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return false;
}

int main()
{
    int n;
    cout << "Enter the strength of the array : ";
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the element arr[" << i << "] : ";
        cin >> arr[i];
    }
    int target;
    cout << "Enter the target number : ";
    cin >> target;
    if (searchInRotatedSortedArray(arr, n, target))
    {
        cout << "The targeted number is present inside of the array.";
    }
    else
    {
        cout<<"The targeted number is not present inside of the array.";
    }
}