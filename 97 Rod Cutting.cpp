#include <bits/stdc++.h>
using namespace std;

int dp[1005];
int func(int len, vector<int> &prices)
{
    if (len == 0)
        return 0;
    if (dp[len] != -1)
        return dp[len];
    int ans = 0;
    for (int len_to_cut = 1; len_to_cut <= prices.size(); len_to_cut++)
    {

        if (len - len_to_cut >= 0)
        {
            ans = max(ans, func(len - len_to_cut, prices) + prices[len_to_cut - 1]);
        }
    }
    return dp[len] = ans;
}

int cutRod(int price[], int n)
{
    memset(dp , -1 , sizeof(dp));
    vector<int> prices(price, price + n);
    return func(n, prices);
}

int main()
{
}