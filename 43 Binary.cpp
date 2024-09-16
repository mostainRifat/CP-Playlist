// PREDICATE FUNCTION

#include <bits/stdc++.h>
using namespace std;
const int N = 10e6 + 10;
int n;
long long m;
long long trees[N];

bool isenoughwood(int h)
{
    long long wood=0;
    for(int i=0 ; i<n;i++)
    {
        if(trees[i] >= h)
            wood += (trees[i] - h);
    }
    return wood>= m;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> trees[i];
    }
    long long lo = 0, hi = 1e9, mid;

    while (hi - lo > 0)
    {
        mid = (hi + lo) / 2;
        if (isenoughwood(mid))
            lo = mid;
        else
            hi = mid - 1;
    }
    if (isenoughwood(hi))
        cout << hi << endl;
    else
        cout << lo << endl;
}
