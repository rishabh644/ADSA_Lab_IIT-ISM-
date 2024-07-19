#include<iostream>
#include<bits/stdc++.h>


using namespace std;

int getNextState(string p,int m,int q,int x)
{

   if( q<m && x==(p[q]-97) )
       return q + 1;

   int ns, i;

   for (ns = q; ns > 0; ns--)
    {
        if (p[ns-1] == x)
        {
            for (i = 0; i < ns-1; i++)
                if (p[i] != p[q-ns+1+i])
                    break;
            if (i == ns-1)
                return ns;
        }
    }

    return 0;


}


void com_Tf(string P,int m,vector<vector<int>>&tbl)
{

    for (int q = 0; q <= m;q++)
    {
        for (int x = 0; x < 26;x++)
        {
            tbl[q][x] = getNextState(P, m, q, x);
        }
    }
}





void finite_automation_match(string T,vector<vector<int>>&tbl,string P)
{
    int n = T.size();
    int q = 0;

    int m = P.size();
com_Tf(P,m, tbl);
    for (int i = 0; i < n;i++)
    {
        q = tbl[q][T[i] - 97];
        if(q==m)
          {

              cout << "Pattern occurs with shift " << (i - m + 1) << endl;
          }
    }
}




int main()
{

    string T = "bacbababaabcbab";
    string P1 = "ababa";
    string P2 = "abcbabc";
    vector<vector<int>> tbl1(P1.size() + 1, vector<int>(26, 0));
    vector<vector<int>> tbl2(P2.size() + 1, vector<int>(26, 0));
    finite_automation_match(T, tbl1,P1);
    finite_automation_match(T,tbl2,P2);
    return 0;




}