#include <bits/stdc++.h>
using namespace std;

void rotate90Degree(vector<vector<int>> &num)
{
    int N = num.size();
    if (num.size() != num[0].size())
        return;
    for (size_t i = 0; i < N / 2; i++)
    {
        int offset1 = N - i - 1;
        for (size_t j = 0; j < offset1; j++)
        {
            int offset2 = N - j - 1;
            int temp = num[i][j];
            num[i][j] = num[j][offset1];
            num[j][offset1] = num[offset1][offset2];
            num[offset1][offset2] = num[offset2][i];
            num[offset2][i] = temp;
        }
    }
}
int main()
{
    vector<vector<int>> num = {
        {1, 2, 3},
        {3, 4, 5},
        {4, 5, 6}};
    rotate90Degree(num);
    rotate90Degree(num);
    rotate90Degree(num);
    for (vector<int> row : num)
    {
        for (int el : row)
        {
            cout << el << " ";
        }
        cout << endl;
    }
}
