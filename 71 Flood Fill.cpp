#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

void dfs(int i, int j, int initial, int neo, vector<vector<int>> &image)
{
    int n = image.size();
    int m = image[0].size();

    if (i < 0 || j < 0)
        return;
    if (i >= n || j >= m)
        return;
    if(image[i][j] != initial) 
        return;

    image [i][j] = neo;

    dfs(i - 1, j, initial, neo , image);
    dfs(i + 1, j, initial, neo , image);
    dfs(i, j + 1, initial, neo , image);
    dfs(i, j - 1, initial, neo , image);
}

vector<vector<int>>floodFill(vector<vector<int>> & image , int sr , int sc , int initial , int neo)
{
    int initial = image[sr][sc];
    if(initial != neo)
        dfs(sr,sc, initial , neo , image);
    return image;
}

int main()
{
}