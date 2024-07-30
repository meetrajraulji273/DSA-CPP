#include <bits/stdc++.h>
using namespace std;

int fact(int n)
{
    if (n == 1)
        return 1;
    return n * fact(n - 1);
}
void factorialNumbers(long long n)
{
    if (n < 1)
    {
        return;
    }
    cout << fact(n - 1);
    factorialNumbers(n - 1);
}

int main()
{
    int n;
    cout << "Enter the Number : ";
    cin >> n;
    factorialNumbers(n);
}