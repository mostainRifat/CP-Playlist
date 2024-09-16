#include<bits/stdc++.h>
using namespace std;

const int N=1e5 + 5;
vector<int>g[N];
bool vis[N];


bool dfs(int vertex , int par)
{
    vis[vertex] = 1;
    bool isLoopExist = false;
    for(int child : g[vertex])
    {
        cout<< "Par : "<<vertex<<" , Child: "<<child<< endl;
        if(vis[child] && child == par) continue;
        if(vis[child]) return true;
        isLoopExist |= dfs(child , vertex);
    }
    return isLoopExist;
}

int main()
{
    int n, m;
    cin>>n>>m;
    for(int i =0 ;i< m; i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }

    //int ct =0 ;
    bool isLoopExist = false;
    for(int i =1 ; i<= n;i++)
    {
        if(vis[i]) continue;
        if(dfs(i,0)){
            isLoopExist = true;
            break;
        }
        //ct++;
    }
    
}