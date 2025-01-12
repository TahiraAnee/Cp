#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl "\n"

struct node{
    bool endmark=false;
    node *child[52]={NULL};
};
node *rootNode;
ll getIndex(char ch)
{
    ll indx=ch-'A';
    if(ch>='a')indx-=6;

    return indx;

}
void insert(string s)
{
    node *curNode=rootNode;
    for(auto &u:s)
    {
        ll indx=getIndex(u);
        if(curNode ->child[indx]==NULL)
        {
            curNode->child[indx]=new node;
        }
        curNode=curNode->child[indx];

    }

    curNode->endmark=true;
}
bool search(string s)
{
    node *curNode =rootNode;
    for(auto &u:s)
    {
        ll indx=getIndex(u);
        if(curNode->child[indx]==NULL) return false;
        curNode=curNode->child[indx];
    }

    return curNode->endmark;
}
void Delete(node *curNode)
{
    for(ll i=0;i<52;i++)
    {
        if(curNode->child[i]!=NULL)
        {
            Delete(curNode->child[i]);
        }
    }

    delete(curNode);
}
int32_t main()
{
    rootNode = new node;
}
