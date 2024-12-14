#include <bits/stdc++.h>
using namespace std;

void isPrime(int n)
{
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            count++;
        }
    }
    if (count == 2)
        cout << "true";
    else
        cout << "false";
}

void isPrime2(int n){
    int count = 0;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            count++;
            if(n/i != 0){
                count++;
            }
        }
    }
    if(count == 2) cout<<"true";
    else cout<<"false";
}

int main()
{
    cout << "--------";
    cout << endl
         << endl;

    int num;
    cout << "Enter the Number : ";
    cin >> num;

    isPrime2(num);

    cout << endl
         << endl;
    cout << "--------";
}