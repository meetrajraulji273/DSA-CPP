#include <bits/stdc++.h>
using namespace std;

// brute-force method --> T.C ---> O((sum-maxi+1)*n)
int getSum(vector<int> &weights)
{
    int sum = 0;
    for (int i = 0; i < weights.size(); i++)
    {
        sum += weights[i];
    }
    return sum;
}
int getMax(vector<int> &weights)
{
    int maxi = INT_MIN;
    for (int i = 0; i < weights.size(); i++)
    {
        maxi = max(maxi, weights[i]);
    }
    return maxi;
}
int requiredDays(vector<int> &weights, int capacity)
{
    int days = 1;
    int load = 0;
    for (int i = 0; i < weights.size(); i++)
    {
        if (load + weights[i] > capacity)
        {
            days = days + 1;
            load = weights[i];
        }
        else
        {
            load += weights[i];
        }
    }
    return days;
}
int shipWithinDays2(vector<int> &weights, int days)
{
    int maxi = getMax(weights);
    int sum = getSum(weights);
    for (int i = maxi; i <= sum; i++)
    {
        int total_days = requiredDays(weights, i);
        if (total_days <= days)
        {
            return i;
        }
    }
}

// optimal-approch ---> T.C ---> log 2 (sum-maxi+1) * O(n)
int shipWithinDays1(vector<int> &weights, int days)
{
    int maxi = getMax(weights);
    int sum = getSum(weights);
    int low = maxi;
    int high = sum;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int total_days = requiredDays(weights, mid);
        if (total_days <= days)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}

int main()
{
    int n;
    cout << "Enter the strength of the weights array : ";
    cin >> n;
    vector<int> weights(n);
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the element weights[" << i << "] : ";
        cin >> weights[i];
    }
    int days;
    cout << "Enter the days within all the weights should be shipped : ";
    cin >> days;
    cout << "The least capacity for which all the weights are shipped within given days is : " << shipWithinDays2(weights, days);
}