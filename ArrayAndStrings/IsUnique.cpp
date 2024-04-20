#include <bits/stdc++.h>

using namespace std;

bool isUnique(const string &str)
{
    if (str.length() > 128)
        return false;
    vector<bool> char_set(128);
    for (int i = 0; i < str.length(); i++)
    {
        int val = str[i];
        if (char_set[val])
        {
            return false;
        }
        char_set[val] = true;
    }
    return true;
}

bool isUnique_No_DS(string &str)
{
    sort(str.begin(), str.end());
    bool noRepeat = true;
    for (int i = 0; i < str.length() - 1; i++)
    {
        if (str[i] == str[i + 1])
        {
            noRepeat = false;
            break;
        }
    }
    return noRepeat;
}

int main()
{
    string str;
    cin >> str;

    if (isUnique_No_DS(str))
        cout << "Is Unique";
    else
        cout << "Is Not Unique";
    // cout << static_cast<int>(str.at(2));
}