#include <bits/stdc++.h>
using namespace std;

int minimum_energy_required(int index, vector<int> &height, vector<int> &dp)
{
    if (index == 0)
        return 0;
    if (dp[index] != -1)
        return dp[index];
    int jumpTwo = INT_MAX;
    int jumpOne = minimum_energy_required(index - 1, height, dp) + abs(height[index] - height[index - 1]);
    if (index > 1)
    {
        jumpTwo = minimum_energy_required(index - 2, height, dp) + abs(height[index] - height[index - 2]);
    }
    return dp[index] = min(jumpOne, jumpTwo);
}

int main()
{
    int n = 4;
    vector<int> height = {10, 20, 30, 10};
    vector<int> dp(n, -1);
    cout << minimum_energy_required(n - 1, height, dp);
}