#include<iostream>
#include<bits/stdcpp.h>


using namespace std;

void print_dft(vector<vector<int>>& ans)
{

   int i,j;

   for (i = 0; i < ans.size();i++)
   {

       cout << ans[i][0] << " + i" << ans[i][1] << endl;
   }

}

void recursive_dft(vector<int>poly)
{

   int n = poly.size();

   if n==1
}


int main()
{

int bound;
cout << "Enter bound of polynomial" << endl;
cin >> bound;

vector<int> poly(bound, 0);
vector<vector<int>> ans(bound, vector<int>(2, 0));
}