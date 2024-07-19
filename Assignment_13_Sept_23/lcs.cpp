#include<iostream>
#include<bits/stdc++.h>


using namespace std;

int modified_binary_search(vector<int>temp,int end,int key)
{

    int low = 0;
    int high = end;
    int mid;
    int pos = end + 1;
    while(low<=high)
    {

        mid = (low + high) / 2;
       if(temp[mid]==key)
       {
           pos = mid;
           return pos;
       }
       else if(temp[mid]>key)
       {
           pos = mid;
           high = mid - 1;
       }
       else
       {
           low = mid + 1;
       }

    }

    return pos;
}



int longest_strictly_subsequence(vector<int>vec,int n)
{
    vector<int> temp(n);
    int j=0,i;
    int pos;
    temp[j] = vec[j];
    for (i = 1; i < n;i++)
    {
        pos = modified_binary_search(temp, j, vec[i]);
        if(pos==(j+1))
        {
           j += 1;
           temp[j] = vec[i];
        }
        else
        {
           temp[pos] = vec[i];
        }
    }

    return j + 1;
}

int main()
{

    vector<int> vec={3,10,2,1,20};
    int ans;

    ans = longest_strictly_subsequence(vec,5);

    cout << "Longest striclty increasing subsequence is " << ans << endl;

    return 0;
}
