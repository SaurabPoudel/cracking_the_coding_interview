#include <bits/stdc++.h>

using namespace std;

// Dynamic programming, same as fibonacci

int ways(int n, vector<int> dp)
{

    if (n <= 1)
        return n;

    if (dp[n] != -1)
        return dp[n];

    return dp[n] = ways(n - 1, dp) + ways(n - 2, dp);
}

// tabulation same as fibonacci
// see TabulationFibonacci
int main()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);
    cout << ways(n, dp);
    return 0;
}