#include<iostream>
#include<bits/stdc++.h>

using namespace std;



void initialize_single_source(vector<pair<int,int>>& ans,int s)
{
    // d.first=distance
    // d.second=predecessor
   // taking 15000 as infinity
    for (int i = 0; i<ans.size();i++)
    {

        ans[i] = {15000, -1};
    }
    ans[s].first = 0;
}


void print_cost(vector<pair<int, int>>ans)
{
    for (auto v:ans)
    {
        cout << v.first << " " << v.second<<endl;
    }
}
void relax_edge(vector<pair<int, int>>curr,vector<pair<int, int>>&ans,vector<int>edge)
{

    if(ans[edge[1]].first>(curr[edge[0]].first+edge[2]) )
    {
        ans[edge[1]].first = curr[edge[0]].first + edge[2];
        ans[edge[1]].second = edge[0];
    }


}


bool bellmon_ford(vector<pair<int, int>>&ans,vector<vector<int>>& weight_edge_list,int nv)
{
    int count = 1;
    vector<pair<int,int>>curr;
    while(count<=(nv-1))
    {
        curr= ans;
        for (auto edge:weight_edge_list)
        {
            relax_edge(curr,ans, edge);
        }
        cout << "After "<<count<<" iteration " << endl;
        print_cost(ans);
        count += 1;
    }

         // cheking for negative cycle
        for (auto edge:weight_edge_list)
        {
            if(ans[edge[1]].first>(ans[edge[0]].first+edge[2]))
            return false;
        }
        return true;
}
int main()
{

    int nv,s,ne,i,in,count;
    cout << "Enter no. of vertices " << endl;
    cin >> nv;
    cout << " Enter the source vetex " << endl;
    cin >> s;
    cout << "Enter no. of edges" << endl;
    cin >> ne;
    vector<vector<int>> weight_edge_list;
    vector<pair<int, int>> ans(nv);
    vector<int> temp;
    initialize_single_source(ans, s);
    cout << "Enter edge list matrix " << endl;
    cout << " Enter each eadge as three tuple that is source,destination,weight " << endl;
    i = 0;
    while(i<ne)
    {

        cin >> in;
        temp.push_back(in);
        cin >> in;
        temp.push_back(in);
        cin >> in;
        temp.push_back(in);
        weight_edge_list.push_back(temp);
        temp.clear();
        i += 1;
    }

    if(!bellmon_ford(ans,weight_edge_list,nv))
    {
        cout << "Negative Cycle Exist in the Graph " << endl;
    }
    else
    {
        cout << "Single source shortest distance with predecessor is " << endl;
        print_cost(ans);
    }


    return 0;
}