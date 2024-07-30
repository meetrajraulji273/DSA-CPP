#include <bits/stdc++.h>
using namespace std;

void f()
{
    int count = 0;
    count++;
    cout << count << endl;
    f();
}

int main()
{
    f();
    return 0;
}