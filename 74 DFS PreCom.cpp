// Print Subtree Sum
// Number of even Numbers in subtree

#include <bits/stdc++.h>
using namespace std;

const int N = 10e5 + 5;
vector<int> g[N];
int subtree_sum[N];
int even[N];

void dfs(int vertex, int par)
{
    subtree_sum[vertex] += vertex;
    if(vertex%2 == 0 ) even[vertex]++;

    for (int child : g[vertex])
    {
        if(child == par) continue;
        dfs(child, vertex);
        subtree_sum[vertex] += subtree_sum[child];
        even[vertex] += even[child];
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
    dfs(1,0);
    int q;
    cin >> q;
    while (q--)
    {
        int v;
        cin>>v;
        cout<<subtree_sum[v];
    }
}