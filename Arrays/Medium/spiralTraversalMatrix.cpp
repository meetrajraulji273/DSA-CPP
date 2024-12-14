#include <bits/stdc++.h>
using namespace std;

// optimal-approach ---> T.C ---> O(n*m) ---> S.C ---> O(1)
void spiralTraversal(vector<vector<int>> &arr, int n, int m)
{
    cout<<"Spiral Matrix : ";
    int top = 0;
    int bottom = n - 1;
    int left = 0;
    int right = n - 1;
    while (top <= bottom && left <= right)
    {
        for (int j = top; j <= right; j++)
        {
            cout << arr[top][j] << " ";
        }
        top++;
        for (int i = top; i <= bottom; i++)
        {
            cout << arr[i][right] << " ";
        }
        right--;
        if (top <= bottom)
        {
            for (int j = right; j >= left; j--)
            {
                cout << arr[bottom][j] << " ";
            }
            bottom--;
        }
        if (left<=right)
        {
            for (int i = bottom; i >= top; i--)
            {
                cout << arr[i][left] << " ";
            }
            left++;
        }
    }
}

int main()
{
    int n, m;
    cout << "Enter the no. of rows and columns of the matrix : ";
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << "Enter the element arr[" << i << "][" << j << "] : ";
            cin >> arr[i][j];
        }
    }
    cout << "Matrix before : " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    spiralTraversal(arr, n, m);
    return 0;
}