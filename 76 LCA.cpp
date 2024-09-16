#include <bits/stdc++.h>
using namespace std;

const int N = 10e5 + 5;
vector<int> g[N];
int par[N];

void dfs(int vertex, int p=-1)
{
    par[vertex] = p;
    for (auto child : g[vertex])
    {
        if (child == p)
            continue;
        
        dfs(child, vertex);
    }
}

vector<int> path(int v)
{
    vector<int>ans;
    while(v!= -1)
    {
        ans.push_back(v);
        v=par[v];
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1);

    int x,y;
    cin>>x>>y;
    vector<int>pathx = path(x);
    vector<int>pathy = path(y);
    
    int min_ln = min(pathx.size(),pathy.size());

    int lca =-1;

    for(int i =0 ;i<min_ln ; i++)
    {
        if ( pathx[i] == pathy[i])
            lca = pathx[i];
        else
            break;
    }
    cout<<lca<<endl;
}