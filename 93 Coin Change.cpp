// Find the Lowest amount of coin
#include <bits/stdc++.h>
using namespace std;
const int N = 10e5 + 10;
int dp[10010];

int func(int amount, vector<int> &coins)
{
    if (amount == 0)
        return 0;
    if (dp[amount] != -1)
        return dp[amount];
    int ans = INT_MAX;
    for (int coin : coins)
    {
        if (amount - coin >= 0)
            ans = min(ans + 0LL, func(amount - coin, coins) + 1LL);
    }
    return dp[amount] = ans;
}

int coinChange(vector<int> &coins, int amount)
{
    int ans = func(amount, coins);
    return ans == INT_MAX ? -1 : ans;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int n, target;
    cin >> n;
    vector<int> coins(n);

    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }
    cin >> target;
    cout << coinChange(coins, target);
}