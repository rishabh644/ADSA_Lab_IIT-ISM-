#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,i;
    int f = 1;
    int s = 1;
    int t;
    cout << "Enter value of n\n";
    cin >> n;
    if(n<0)
        cout << -1 << endl;
    else if(n<=1)
        cout << 1 << endl;
    else
    {
        for(i = 2; i <= n;i++)
        {
            t = f;
            f = f + s;
            s = t;
        }
    }

    cout << "Total ways are " << f << endl;
}