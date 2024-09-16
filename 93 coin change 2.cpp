// Find the Combination of amount

#include <bits/stdc++.h>
using namespace std;
const int N = 10e5 + 10;
int dp[310][10010];


int func1(int idx, int amount, vector<int> &coins)
{
    if (amount == 0)
        return 1;
    if(idx<0)
        return 0;
    if (dp[idx][amount] != -1)
        return dp[idx][amount];

    int way = 0;
    for (int coin_amount = 0; coin_amount <= amount; coin_amount += coins[idx])
    {
        way = func1(idx - 1, amount - coin_amount, coins);
    }
    return dp[idx][amount] = way;
}

int coinChange(vector<int> &coins, int amount)
{
    //int ans = func(amount, coins);
    return func1(coins.size()-1 , amount , coins);
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