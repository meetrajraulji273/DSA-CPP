#include <bits/stdc++.h>
using namespace std;

int findHcf(int n1, int n2)
{
    int hcf = 1;
    for (int i = 1; i <= min(n1, n2); i++)
    {
        if (n1 % i == 0 && n2 % i == 0)
        {
            hcf = i;
        }
    }
    return hcf;
}
     
int findHcf2(int n1,int n2){
    int hcf = 1; 
    for(int i = min(n1,n2);i>=1;i--){
        if(n1%i == 0 && n2%i == 0){
            hcf = i;
            break;
        }
    }
    return hcf;
}

int main()
{
    cout << "--------";
    cout << endl
         << endl;

    int n1, n2;
    cout << "Enter n1 : ";
    cin >> n1;
    cout << "Enter n2 : ";
    cin >> n2;

    cout << "The HCF is : " << findHcf2(n1, n2);

    cout << endl
         << endl;
    cout << "--------";
}