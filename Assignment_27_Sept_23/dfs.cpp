#include<iostream>
#include<bits/stdc++.h>

using namespace std;


void dfs(vector<bool>&visited,vector<vector<int>>adj_list,int i)
{

    visited[i] = true;
    cout << i << " " << endl;
    for(auto adjv:adj_list[i])
    {

       if(!visited[adjv])
       {
           dfs(visited, adj_list, adjv);
       }

    }



}

int main()
{

    int n,e;
    int v1, v2;
    cin >> n>>e;

    vector<vector<int>>adj_list(n + 1);
    vector<bool> visited(n + 1, false);
    int i;
    int st;
    for (i = 0; i < e;i++)
   {
       cin >> v1;
       cin >> v2;

       adj_list[v1].push_back(v2);

   }
   cin >> st;
   dfs(visited, adj_list, st);
   for (i = 1; i <= n;i++)
   {

       if(!visited[i])
       {
           dfs(visited, adj_list, i);
       }


   }


}