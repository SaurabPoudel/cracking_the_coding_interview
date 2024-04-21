#include <bits/stdc++.h>

using namespace std;

bool checkMaxOneOdd(vector<int> table)
{
    bool foundOdd = false;
    for (int count : table)
    {
        if (count % 2 == 1)
        {
            if (foundOdd)
                return false;
            foundOdd = true;
        }
    }
    return true;
}

vector<int> buildCharFrequency(string phrase)
{
    vector<int> table('z' - 'a' + 1);
    for (char c : phrase)
    {
        table[c - 'a']++;
    }
    return table;
}

bool isPermutationOfPallindrome(string phrase)
{
    vector<int> table = buildCharFrequency(phrase);
    return checkMaxOneOdd(table);
}

bool isPermutationOfPallindrome2(string phrase)
{
    int countOdd = 0;
    vector<int> table('z' - 'a' + 1);
    for (char c : phrase)
    {
        table[c - 'a']++;
        if (table[c - 'a'] % 2 == 1)
        {
            countOdd++;
        }
        else
        {
            countOdd--;
        }
    }
    return countOdd <= 1;
}

int main()
{
    cout << isPermutationOfPallindrome2("moyemoey");
}
