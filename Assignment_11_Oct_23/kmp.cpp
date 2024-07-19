#include<iostream>
#include<bits/stdc++.h>

using namespace std;


void lpsfx(string P,vector<int>&lps)
{
    int m = P.size();
    lps[0] = 0;

    int k = 0;

    for (int q = 1; q < m;q++)
    {

        while(k>0 && P[k]!=P[q])
         {
             k = lps[k];
         }
          if(P[k]==P[q])
             k = k + 1;
          lps[q] = k;
    }

}


void kmp_match(string T,string P)
{

    int n = T.size();
    int m = P.size();
    vector<int> lps(P.size(), 0);
    lpsfx(P, lps);
    int q = 0;
    bool ck = false;
    // cout<<T<<endl;
    // cout << P << endl;
    // // for (int j = 0; j < lps.size();j++)
    //  {
    //       cout << lps[j] << endl;
    // cout << "Rishabh " << endl;

    //  }

          for (int i = 0; i < n; i++)
          {
             while (q > 0 && P[q] != T[i])
             {
                 q = lps[q];
             }
             if (P[q] == T[i])
                 q = q + 1;
             if (q == m)
             {
                 cout << " String ' "<<P<<" ' occur with shift " << (i - m +1)<<" in ' "<<T<<" ' "<<endl;
                 q = lps[q];
                 ck = true;
             }
          }
          if(ck==false)
          {
             cout << "String ' " << P << " ' does not occur in ' " << T << " ' "<<endl;
          }
          return;
}

int main()
{

    string T = "bacbababaabcbab";
    string P1 = "ababa";
    string P2 = "abcbabc";

    kmp_match(T, P1);
    kmp_match(T, P2);
    return 0;
}