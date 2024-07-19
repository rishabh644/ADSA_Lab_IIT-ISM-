#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void print_cost(vector<vector<int>>& ans,int n)
{
    int i, j;
    for (i = 0; i < n;i++)
    {
        for (j = 0; j < n;j++)
        {   if(ans[i][j]!=INT_MAX)
            cout << setw(10)<<ans[i][j] << " ";
            else
            cout<<setw(10) << "Inf"<< " ";
        }
        cout << endl;
    }
    return;
}

int main()
{
    int n,i,j,k;
    // cout << "Enter no. of vertex " << endl;
    // cin >> n;
    vector<vector<int>> adj_mat(n, vector<int>(n,INT_MAX));
    vector<vector<int>> curr;
    vector<vector<int>> ans;
    adj_mat[0][0] = 0;
    adj_mat[1][1] = 0;
    adj_mat[2][2] = 0;
    adj_mat[3][3] = 0;
    adj_mat[4][4] = 0;
    adj_mat[5][5] = 0;
    adj_mat[6][6] = 0;
    adj_mat[7][7] = 0;
    adj_mat[0][1] = 10;
    adj_mat[0][7] = 8;
    adj_mat[1][5] = 2;
    adj_mat[2][1] = 1;
    adj_mat[2][3] = 1;
    adj_mat[3][4] = 3;
    adj_mat[4][5] = -1;
    adj_mat[5][2] = -2;
    adj_mat[6][1] = -4;
    adj_mat[6][5] = -1;
    adj_mat[7][6] = 1;
    //     cout << "Enter adjacency matrix " << endl;
    //    for (i = 0; i < n;i++)
    //    {
    //        for (j = 0; j < n;j++)
    //        {
    //            cin >> adj_mat[i][j];
    //        }
    //    }
    ans = adj_mat;
    cout << "After Initialization " << endl;
        print_cost(ans, n);
    for (k = 0; k <= n - 1; k++)
    {
        curr = ans;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {   if(curr[i][k]!=INT_MAX && curr[k][j]!=INT_MAX)
                {ans[i][j] = min(curr[i][j], curr[i][k] + curr[k][j]);}
                else
                {
                ans[i][j] = curr[i][j];
                }
            }
        }
        cout << "After " << k + 1 << " Pass" << endl;
        print_cost(ans, n);

    }

    return 0;
}