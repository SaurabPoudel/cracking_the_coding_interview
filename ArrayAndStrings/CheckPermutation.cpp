#include <bits/stdc++.h>

using namespace std;

// this method is done when the efficiency is not very important
bool checkPermutation1(string s, string t)
{
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    if (s == t)
        return true;
    else
        return false;
}

// efficiency matters !
bool checkPermutation2(string s, string t)
{
    if (s.length() != t.length())
        return false;

    vector<int> letters(128);
    for (char c : s)
    {
        letters[c]++;
    }
    for (int i = 0; i < t.length(); i++)
    {
        int c = static_cast<int>(t[i]);
        letters[c]--;
        if (letters[c] < 0)
            return false;
    }
    return true;
}

int main()
{
    if (checkPermutation2("saurab", "baruas"))
    {
        cout << "One string is permutation of another";
    }
    else
    {
        cout << "Not a permutation";
    }
    return 0;
}