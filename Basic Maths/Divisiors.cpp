#include <bits/stdc++.h>
using namespace std;

// Time Complexity : o(n)
void print_disisors(int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            cout << i << " ";
        }
    }
}

// Time Complexity : o(sqrt(n) + no. factors log no. factors + no. of factors)
void print_divisors2(int n)
{
    vector<int> v;
    // o(sqrt(n))
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            v.push_back(i);
            if (n / i != i)
            {
                v.push_back(n / i);
            }
            // o(no. factors log no. factors)

            // o(no. factors)
        }
    }
    sort(v.begin(), v.begin() + v.size());
    for (auto it : v)
        cout << it << " ";
}

int main()
{
    cout << "--------";
    cout << endl
         << endl;

    int n;
    cout << "Enter the Number : ";
    cin >> n;

    print_divisors2(n);

    cout << endl
         << endl;
    cout << "--------";
}