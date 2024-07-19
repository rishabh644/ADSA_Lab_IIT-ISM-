#include <iostream>
#include <vector>
#include <queue>
#include <climits>

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
    int adv, cst, s, i;
    pair<int, int> pr;
    pair<int, int> tr;

    cout << " Enter number of vertices " << endl;
    cin >> nv;
    cout << " Enter source vertex " << endl;
    cin >> s;
    vector<vector<pair<int, int>>> adj_list(nv);
    vector<pair<int, int>> ans;
    vector<pair<int, int>> temp;
    int nd;

    for (i = 0; i < nv; i++)
    {
        cout << "Enter no of vertices adjacent to " << i << " vertices " << endl;
        cin >> nd;
        cout << " Now Enter vertices adjacent to each vertex in pair {adj_ver,weight} " << endl;

        while (nd > 0)
        {
            cin >> adv;
            cin >> cst;
            pr = {adv, cst};
            adj_list[i].push_back(pr);
            nd -= 1;
        }
    }

    cout << "Initializing " << endl;
    vector<int> distance(nv, INT_MAX);
    distance[s] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> min_heap;
    min_heap.push({0, s});

    while (!min_heap.empty())
    {
        pr = min_heap.top();
        min_heap.pop();
        int u = pr.second;

        if (pr.first > distance[u])
        {
            continue; // Skip if this vertex has already been processed with a shorter distance
        }

        ans.push_back(pr);

        for (auto adjnd : adj_list[u])
        {
            int v = adjnd.first;
            int weight = adjnd.second;

            if (distance[v] > distance[u] + weight)
            {
                distance[v] = distance[u] + weight;
                min_heap.push({distance[v], v});
            }
        }
    }

    for (i = 0; i < ans.size(); i++)
    {
        cout << ans[i].second << " " << ans[i].first << endl;
    }

    return 0;
}
