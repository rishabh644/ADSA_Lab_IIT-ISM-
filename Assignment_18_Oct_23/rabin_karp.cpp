#include<iostream>
#include<bits/stdc++.h>

using namespace std;


bool check(string P,string T){

    for (int i = 0; i < P.size();i++)
    {
          if(P[i]!=T[i])
              return false;
    }
    return true;
}

void rabin_karp(string T,string P,int d,int q)
{
    int n = T.size();
    int m = P.size();

    int h = ((int)pow(d, m - 1)) % q;

    int p = 0;
    int t = 0;

    for (int i = 0; i < m;i++)
    {

        p = (d * p + int(P[i])) % q;
        t = (d * t + int(T[i])) % q;
    }

    for (int s = 0;s<=(n-m);s++)
    {

           if(p==t)
           {

              if (check(P, T.substr(s, m)))
              {
                  cout << "Pattern " << P << " found with shift " << s << endl;
                }
           }

           if( s<(n-m))
           {
                t = ( d * (t - (int(T[s]) * h)) + int(T[s + m]) ) % q;
           }

           //cout << "p" << p << "  "
             //   << "t" << t << endl;
    }
}


int main()
{

    string T = "3141592653589793";
    string P1 = "26";
    string P2 = "261";
    int d = 10;
    int q = 104729;

    rabin_karp(T,P1,d,q);
    rabin_karp(T,P2,d,q);

    return 0;
}