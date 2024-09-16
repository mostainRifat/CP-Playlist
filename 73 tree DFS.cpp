#include <bits/stdc++.h>
using namespace std;

const int N = 10e5 + 5;
vector<int> g[N];
int d[N], h[N];

void dfs(int vertex, int par)
{
    // Action on Vertex before entering Vertex
    for (int child : g[vertex])
    {
        // Action on Child before entering Child node
        if (child == par)
            continue;
        d[child] = d[vertex] + 1;

        dfs(child, vertex);
        h[vertex] = max(h[vertex], h[child] + 1);
        // Action on Child after exiting Chind node
    }
    // Action on Vertex after exiting Vertex
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
    dfs(1, 0);
}