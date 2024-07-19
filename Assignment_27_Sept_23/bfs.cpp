#include<iostream>
#include<bits/stdc++.h>

using namespace std;











int main()
{

    int n,e;
    int v1, v2;
    cin >> n>>e;

    vector<vector<int>>adj_list(n + 1);
    vector<pair<int, int>> pred_v(n + 1);
    vector<bool> visited(n + 1, false);
    queue<int> qu;
    int i;
    int v,adj_v;
    int st,end_v;
    for (i = 0; i < e;i++)
   {
       cin >> v1;
       cin >> v2;

       adj_list[v1].push_back(v2);

   }
   cout << "enter start and end vertex" << endl;
   cin >> st >> end_v;
   qu.push(st);
   pred_v[st] = {0, -1};
   visited[st] = true;
   while(!qu.empty())
   {
       v = qu.front();
       for(auto adj_v:adj_list[v])
       {
           if(!visited[adj_v])
           {
               visited[adj_v] = true;
               pred_v[adj_v] = {pred_v[v].first + 1, v};
               qu.push(adj_v);
           }

       }

       qu.pop();
   }
   cout << pred_v[end_v].first << " " << endl;


}