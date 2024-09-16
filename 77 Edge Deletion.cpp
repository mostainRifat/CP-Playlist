// delete an edge and find the maximum sum of two parts

#include <bits/stdc++.h>
using namespace std;

const int M = 10e9+7;
const int N = 10e5 + 5;
vector<int> g[N];
int subtree_sum[N] , val[N];


void dfs(int vertex, int par=-1)
{
    //par[vertex] = p;
    subtree_sum[vertex] += val[vertex];
    for (auto child : g[vertex])
    {
        if (child == par)
            continue;
        
        dfs(child, vertex);
        subtree_sum[vertex] += subtree_sum[child]; 
    }
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
    long long ans = 0;
    
    for(int i =2 ; i<= n;i++)
    {
        int part1 = subtree_sum[i];
        int part2 = subtree_sum[1] - part1 ;
        ans = max(ans, (part1*1LL*part2) % M);
    }
    cout<<ans;
}
