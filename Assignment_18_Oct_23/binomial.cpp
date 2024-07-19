#include<iostream>
#include<bits/stdc++.h>

using namespace std;
// 1 2 3 4 -1 5 6 -1 -1 7
struct Node{

    int data,degree;
    Node *child;
    Node *sibling;
    Node *parent;

};


Node* new_node(int data)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->degree=0;
    node->child =NULL;
    node->sibling=NULL;
    node->parent=NULL;
    return (node);
}

void myswap(Node* b1,Node* b2)
{
      Node* temp;

      temp=b1;
      b1=b2;
      b2=temp;

}

Node* mergeBinomialTrees(Node *b1,Node *b2)
{
       if(b1->data > b2->data)
       {
            myswap(b1,b2);
       }

       b2->parent=b1;
       b2->sibling=b1->child;
       b1->child=b2;
       b1->degree++;

       return b1;

}


list<Node*> unionBinomialHeap(list<Node*> l1,list<Node*> l2)
{

   list<Node*> _new;
   list<Node*>::iterator it=l1.begin();
   list<Node*>::iterator ot=l2.begin();

   while( it!=l1.end() && ot!=l2.end() ){


       if(((*it)->degree)<=((*ot)->degree))
       {

          _new.push_back(*it);
          it++;

       }
       else
       {
           _new.push_back(*ot);
           ot++;

       }




                                       }
while(it!=l1.end())
{

 _new.push_back(*it);
 it++;

}

while(ot!=l2.end())
{
   _new.push_back(*ot);
   ot++;

}

     return _new;

}

list<Node*> adjust(list<Node*> _heap)
{

   if(_heap.size()<=1)
      return _heap;

   list<Node*> new_heap;
   list<Node*>::iterator it1,it2,it3;
   it1=it2=it3=_heap.begin();

   if(_heap.size()==2)
   {
      it2=it1;
      it2++;
      it3=_heap.end();
   }
   else
   {
     it2++;
     it3=it2;
     it3++;

   }

   while(it1!=_heap.end())
   {

     if(it2==_heap.end())
     {
     it1++;
     }


     else if( ((*it1)->degree)< ((*it2)->degree) )
     {
        it1++;
        it2++;
        if(it3!=_heap.end())
        {
          it3++;
        }
     }

     else if( it3!=_heap.end() && (*it1)->degree==(*it2)->degree
     && (*it1)->degree==(*it3)->degree )
     {
         it1++;
         it2++;
         it3++;

     }

     else if((*it1)->degree == (*it2)->degree)
     {
         Node *temp;
        *it1=mergeBinomialTrees  (*it1,*it2);
         it2=_heap.erase(it2);

         if(it3!=_heap.end())
          it3++;

     }


   }

   return _heap;

}




// int height(Node *root)
// {
//      if(root==NULL)
//         return 0;

//      else
//         return 1 + max(height(root->left), height(root->right));
// }
// void dfs(Node *root)
// {
//   if(root==NULL)
//         return;
//   if(root->left==NULL && root->right==NULL)
//   {
//         cout << root->data << " ";
//         return;
//   }
//   dfs(root->right);
//   dfs(root->left);
// }

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
