#include <bits/stdc++.h>
using namespace std;

// brute-fore method ---> T.C ---> O((Maxi-Mini+1)*piles.size()(length of the piles array))
vector<int> getMinAndMax(vector<int> &piles)
{
    int maxi = INT_MIN;
    int mini = INT_MAX;
    for (int i = 0; i < piles.size(); i++)
    {
        mini = min(mini, piles[i]);
        maxi = max(maxi, piles[i]);
    }
    return {mini, maxi};
}

// bool possible(vector<int> &piles,int m,int k){
//     int cnt = 0;
//     int bouquets = 0;
//     for(int i=0;i<piles.size();i++){
//         if(piles[i]<=)
//     }
// }

int minDaysMakingMBouquets1(vector<int> &piles, int m, int k)
{
    vector<int> miniAndMaxi = getMinAndMax(piles);
    int mini = miniAndMaxi[0];
    int maxi = miniAndMaxi[1];
    for (int i = mini; i <= maxi; i++)
    {
        int cnt = 0;
        int bouquets = 0;
        for (int j = 0; j < piles.size(); j++)
        {
            if (piles[j] <= i)
            {
                cnt++;
            }
            else
            {
                bouquets += cnt / k;
                cnt = 0;
            }
        }
        bouquets += cnt / k;
        if (bouquets >= m)
        {
            return i;
        }
    }
}

// optimal-approach ---> T.C ---> log 2 (maxi-mini+1) * O(n)
int minDaysMakingMBouquets2(vector<int> &piles, int m, int k)
{
    vector<int> miniAndMaxi = getMinAndMax(piles);
    int mini = miniAndMaxi[0];
    int maxi = miniAndMaxi[1];
    int low = mini;
    int high = maxi;
    int ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int cnt = 0;
        int bouquets = 0;
        for (int j = 0; j < piles.size(); j++)
        {
            if (piles[j] <= mid)
            {
                cnt++;
            }
            else
            {
                bouquets += cnt / k;
                cnt = 0;
            }
        }
        bouquets += cnt / k;
        if (bouquets >= m)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int main()
{
    int n;
    cout << "Enter the strength of the piles of flower's array : ";
    cin >> n;
    vector<int> piles(n);
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the array element piles[" << i << "] : ";
        cin >> piles[i];
    }
    int k;
    cout << "Enter the strength of the bouquet that you want make : ";
    cin >> k;
    int m;
    cout << "Enter the number bouquets that you want to make : ";
    cin >> m;

    cout << "The min days for which k no. of bouquets of m strength can be made is : " << minDaysMakingMBouquets2(piles, m, k);
    return 0;
}