#include<iostream>
#include<bits/stdc++.h>

using namespace std;
class Compare
{
public:
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.first > b.first;
    }
};

int main()
{

    int nv;
    int adv,cst,s,i;
    pair<int, int> pr;
    pair<int, int> tr;
    pair<int, int> mr;
    cout << " Enter number of vertices " << endl;
    cin >> nv;
    cout << " Enter source vertex " << endl;
    cin >> s;
    vector<vector<pair<int,int>>> adj_list(nv);
    vector<pair<int, int>> initialize;
    vector<pair<int, int>> ans;
    vector<pair<int, int>> temp;
    vector<int> distance(nv,INT_MAX);
    int nd;
    for (i = 0; i < nv;i++)
    {
       cout << "Enter no of vertices adjacent to " << i << " vertices " << endl;
       cin >> nd;
       cout << " Now Enter vertices adjacent to each vertex in pair {adj_ver,weight} " << endl;

       while(nd>0){
       cin >> adv;
       cin >> cst;
       pr = {adv, cst};
       adj_list[i].push_back(pr);
       nd -= 1;
                  }
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> min_heap;
    min_heap.push({s, 0});
    cout << "Inside the heap " << endl;
    while(!min_heap.empty())
    {

        pr = min_heap.top();
        min_heap.pop();
        int u = pr.second;
        int v,wt;
        if(pr.first>distance[u])
         {   continue;
         }
        ans.push_back(pr);

        for(auto adjver:adj_list[u])
        {
       v = adjver.first;
       wt = adjver.second;
       if (distance[v] > (distance[u] + wt))
       {
           distance[v] = distance[u] + wt;
       }
              min_heap.push({distance[v],v});
        }
        cout << "Inside the loop" << endl;
    }

    for (i = 0; i < ans.size();i++)
    {
       cout << ans[i].second << " " << ans[i].first << endl;
    }

    return 0;
}