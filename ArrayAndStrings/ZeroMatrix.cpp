#include <bits/stdc++.h>

using namespace std;

void nullifyRow(vector<vector<int>> &mat, int row)
{
    for (int j = 0; j < mat[0].size(); j++)
    {
        mat[row][j] = 0;
    }
}

void nullifyCols(vector<vector<int>> &mat, int col)
{
    for (int i = 0; i < mat.size(); i++)
    {
        mat[i][col] = 0;
    }
}

void setZeros(vector<vector<int>> &mat)
{
    vector<bool> row(mat.size());
    vector<bool> col(mat[0].size());

    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[0].size(); j++)
        {
            if (mat[i][j] == 0)
            {
                row[i] = true;
                col[j] = true;
            }
        }
    }
    for (int i = 0; i < row.size(); i++)
    {
        if (row[i])
            nullifyRow(mat, i);
    }
    for (int j = 0; j < col.size(); j++)
    {
        if (col[j])
            nullifyCols(mat, j);
    }
}

int main()
{
    vector<vector<int>> mat = {
        {0, 1, 2},
        {4, 5, 6},
        {7, 8, 9}};

    setZeros(mat);
    for (vector<int> row : mat)
    {
        for (int el : row)
        {
            cout << el << " ";
        }
        cout << endl;
    }
}