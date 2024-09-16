#include <bits/stdc++.h>
using namespace std;
const int N = 10e3 + 3;
int graph1[N][N];

vector<pair<int, int>> graph2[N];

int main()
{
    int n, m, i, j;

    for (int i = 0; i < m; i++)
    {
        int v1, v2, wt;
        cin >> v1 >> v2;
        // Matrix Representation
        graph1[v1][v2] = wt;
        graph1[v2][v1] = wt;

        // List Representation
        graph2[v1].push_back({v2, wt});
        graph2[v2].push_back({v1, wt});
    }

    if (graph1[i][j] != 0) // Connected
        graph1[i][j] = 1;  // weight;
    for (pair<int, int> child : graph2[i])
    {
        if (child.first == j)
            child.second; // Value
    }
}