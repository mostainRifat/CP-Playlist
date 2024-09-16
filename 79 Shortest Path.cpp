#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int INF = 1e9+10;

vector<int> g[N];
int level[8][8];
int vis[8][8];

int getX(string s)
{
    return s[0] - 'a';
}

int getY(string s)
{
    return s[1] - '1';
}

bool isValid(int x, int y)
{
    return x>= 0 && y>= 0 && x<8 && y<8;
}

vector<pair<int, int>> movements = {
    {-1, 2},
    {1, 2},
    {-1, -2},
    {1, -2},
    {2, -1},
    {2, 1},
    {-2, -1},
    {-2, 1},
};

int bfs(string src, string dest)
{
    int srcx = getX(src);
    int srcy = getY(src);
    int destx = getX(dest);
    int desty = getY(dest);
    queue<pair<int, int>> q;

    q.push({srcx, srcy});
    vis[srcx][srcy] = 1;
    level[srcx][srcy] = 0 ;

    while (!q.empty())
    {
        pair<int, int> v = q.front();
        int x = v.first, y = v.second;
        q.pop();
        for(auto movement : movements)
        {
            int childx= movement.first + x;
            int childy = movement.second + y;
            if(!isValid(childx,childy)) continue;

            if(!vis[childx][childy])
            {
                q.push({childx,childy});
                level[childx][childy] = level[x][y] + 1;

            }
        }
        if(level[destx][desty] != INF)
            break;
    }
    return level[destx][desty];
}

void reset()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            level[i][j] = INF;
            vis[i][j] = INF;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        reset;
        string s1, s2;
        cin >> s1 >> s2;
    }
}