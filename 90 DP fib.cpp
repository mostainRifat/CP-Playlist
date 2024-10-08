#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

// TOP DOWN APPROACH
int dp[N];

int fib(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    if (dp[n] != -1)
        return dp[n]; // memeoisation
    //cout << dp[n];
    return dp[n] = fib(n - 1) + fib(n - 2);
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    cout << "Fibonacci : " << fib(n) << endl;

    // BOTTOM UP APPROACH
    int dp2[N];
    dp2[0] = 0;
    dp2[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp2[i] = dp2[i - 1] + dp2[i - 2];
    }
}