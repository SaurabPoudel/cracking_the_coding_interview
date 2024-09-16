#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 4;
    vector<int> height = {10, 20, 30, 10};
    int prev = 0;
    int prev2 = 0;

    for (int i = 1; i < n; i++)
    {
        int jumpTwo = INT_MAX;
        int jumpOne = prev + abs(height[i] - height[i - 1]);
        if (i > 1)
        {
            jumpTwo = prev2 + abs(height[i] - height[i - 2]);
        }
        int curi = min(jumpOne, jumpTwo);
        prev2 = prev;
        prev = curi;
    }
    cout << prev;
}