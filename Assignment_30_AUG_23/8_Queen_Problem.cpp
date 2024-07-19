#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

static int count = 0;
void print_mat(vector<vector<int>>nmat)
{
    int i, j;
    for (i = 0; i < 8;i++)
   {
       for (j = 0; j < 8;j++)
       {
           cout << nmat[i][j] << " ";
       }
       cout << endl;
   }

   cout << "##########################################" << endl;
   //    exit(1);
   count += 1;
}

bool issafe(vector<vector<int>>nmat,int m,int n)
{

    int i=0, j=n;
    // column checking
    while (i < m)
    {
         if(nmat[i][j]==1)
             return false;
         i++;
    }
    // left upper diagonal
    int k = 1;
    i = m;
    j = n;
    while((i-k)>=0 && (j-k)>=0)
    {
       if(nmat[i-k][j-k]==1)
             return false;
       k += 1;
    }
    // right upper
    k = 1;
    i = m;
    j = n;
    while((i-k)>=0 && (j+k)<8)
    {
       if(nmat[i-k][j+k]==1)
             return false;
       k += 1;
    }
    // left lower
    // int k = 1;
    // i = m;
    // j = n;
    // while((i+k)<8 && (j-k)>=0)
    // {
    //    if(nmat[i+k][j-k]==1)
    //          return false;
    //    k += 1;
    // }
    // // right lower
    // int k = 1;
    // i = m;
    // j = n;
    // while((i+k)<8 && (j+k)<8)
    // {
    //    if(nmat[i+k][j+k]==1)
    //          return false;
    //    k += 1;
    // }

    return true;
}

void eight_queen(vector<vector<int>>nmat,int i,int j)
{

     while(j<8)
     {

         nmat[i][j] = 1;

        if(issafe(nmat,i,j))
        {
            if(i==7)
            {
                print_mat(nmat);
                nmat[i][j] = 0;
                return;
            }
            eight_queen(nmat, i + 1, 0);
        }
        nmat[i][j] = 0;
        j++;
     }
     return;
}




int main()
{

    vector<vector<int>> nmat(8, vector<int>(8, 0));


    eight_queen(nmat,0,0);
    cout <<"count "<<count<< endl;
    return 0;
}