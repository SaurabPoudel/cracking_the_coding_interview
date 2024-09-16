#include <bits/stdc++.h>

// Memoizaion solution

using namespace std;
int solveUtil(int n, vector<int> &height, vector<int> &dp, int k)
{
    if (n == 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];
    int mmSteps = INT_MAX;

    for (int j = 1; j <= k; j++)
    {
        if (n - j >= 0)
        {
            int jump = solveUtil(n - j, height, dp, k) + abs(height[n] - height[n - j]);
            mmSteps = min(jump, mmSteps);
        }
    }
    return dp[n] = mmSteps;
}

int solve(int n, vector<int> &height, int k)
{
    vector<int> dp(n, -1);
    return solveUtil(n - 1, height, dp, k);
}

int main()
{
    vector<int> height{30, 10, 60, 10, 60, 50};
    int n = height.size();
    int k = 2;
    vector<int> dp(n, -1);
    cout << solve(n, height, k) << endl;
    return 0;
}