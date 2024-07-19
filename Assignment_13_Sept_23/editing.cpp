#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int minm_operation(string str1,string str2,int m,int n,vector<vector<int>>&vec)
{

      if(m==0 || n==0)
      {
          return max(m, n) + 1;
      }
      if(vec[m][n]!=-1)
          return vec[m][n];
      if(str1[m]==str2[n])
      {
          vec[m][n]=minm_operation(str1, str2, m - 1, n - 1,vec);
          return vec[m][n];
      }
      else
      {
          vec[m][n]=1+min(minm_operation(str1,str2,m,n-1,vec),min(minm_operation(str1, str2, m - 1, n,vec),minm_operation(str1, str2, m - 1, n - 1,vec)));
          return vec[m][n];
      }

}


int main()
{
    string str1;
    string str2;
    int ans;

    cout << "Enter string 1" << endl;
    cin >> str1;
    cout << " Enter string 2 " << endl;
    cin >> str2;
    vector<vector<int>> vec(str1.size(), vector<int>(str2.size(), -1));
    ans = minm_operation(str1, str2,str1.size()-1,str2.size()-1,vec);

    cout << "Minimum operation to convert string1 to string2 is " << ans << endl;

    return 0;
}