#include <bits/stdc++.h>
using namespace std;

void f(int n, int sum)
{
    if (n < 1)
    {
        cout << sum;
        return;
    }
    f(n-1,sum+n);
}

int sum(int n){
    if(n==0) return 0;
    return n+sum(n-1);
}

int main()
{
    int n;
    cout << "Enter the number : ";
    cin >> n;
    cout<<sum(n);
    // f(n, 0);
}