#include<iostream>
#include<bits/stdc++.h>

using namespace std;
// 1 2 3 4 -1 5 6 -1 -1 7
struct Node{
    int data;
    Node *left;
    Node *right;
};


Node* new_node(int data)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}

void pre_order(Node *root)
{
    if(root==NULL)
        return;

    cout << root->data<< "  ";
    pre_order(root->left);
    pre_order(root->right);
}

int height(Node *root)
{
     if(root==NULL)
        return 0;

     else
        return 1 + max(height(root->left), height(root->right));
}
void dfs(Node *root)
{
  if(root==NULL)
        return;
  if(root->left==NULL && root->right==NULL)
  {
        cout << root->data << " ";
        return;
  }
  dfs(root->right);
  dfs(root->left);
}

int main()
{

    int n,i;

    cin >> n;

    vector<int> arr(n, 0);

    for (i = 0; i < n;i++)
    {
        cin >> arr[i];
    }

    queue<Node *> qu;
     Node *root;
    Node *temp;
    Node *nwnd;
    root = new_node(arr[0]);
    qu.push(root);
    i = 0;
    cout << "Root data" << endl;
    cout << root->data << endl;
    while(!qu.empty())
    {
        i++;
        temp = qu.front();
        qu.pop();
         //cout << temp->data;
        if(i==n)
            break;
        if(arr[i]!=-1)
        {
            nwnd = new_node(arr[i]);
            temp->left = nwnd;
            qu.push(nwnd);
        }
        i++;
        if(i==n)
            break;
        if(arr[i]!=-1)
        {
            nwnd = new_node(arr[i]);
            temp->right = nwnd;
            qu.push(nwnd);
        }

    }
     cout << "Preorder_Traversal" << endl;
    pre_order(root);
    cout << "\nHeight is " << height(root)<<endl;
    cout << "Print leaves right to left " << endl;
    dfs(root);
    return 0;
}
