#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 4;
    vector<int> height = {10, 20, 30, 10};
    vector<int> dp(n, -1);
    dp[0] = 0;

    for (int i = 1; i < n; i++)
    {
        int jumpTwo = INT_MAX;
        int jumpOne = dp[i - 1] + abs(height[i] - height[i - 1]);
        if (i > 1)
        {
            jumpTwo = dp[i - 2] + abs(height[i] - height[i - 2]);
        }
        dp[i] = min(jumpOne, jumpTwo);
    }
    cout << dp[n - 1];
}