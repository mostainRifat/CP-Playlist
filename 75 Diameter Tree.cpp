#include <bits/stdc++.h>
using namespace std;
const int N = 10e5 + 5;
vector<int> g[N];
int depth[N];

void dfs(int vertex, int par = -1)
{
    for (int child : g[vertex])
    {
        if (child == par)
            continue;
        depth[child] = depth[vertex] + 1;
        dfs(child, vertex);
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i = 0 ; i< n-1; i++)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs(1);
    int mxdepth = -1 , mxnode = -1 ;
    for(int i = 0 ; i<= n;i++)
    {
        if(mxdepth < depth[i])
        {
            mxdepth = depth[i];
            mxnode =i ;
        }
        depth[i] = 0;
    }

    dfs(mxnode);
    mxdepth= -1;
    for(int i = 0 ; i<= n;i++)
    {
        if(mxdepth < depth[i])
        {
            mxdepth = depth[i];
            mxnode =i ;
        }
    }
    cout<<"MAX Depth : "<<mxdepth;
}