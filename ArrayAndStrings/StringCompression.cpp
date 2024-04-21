/*
compress function compresses the string
aaaddddeeef-> a3d4e3f1
*/

#include <bits/stdc++.h>

using namespace std;

string compress(string str)
{
    int len = str.length();
    string out{""};
    if (len < 2)
        return str;
    int count = 1;
    for (int i = 1; i < str.length(); i++)
    {
        if (str[i - 1] == str[i])
        {
            ++count;
        }
        else
        {
            out += str[i - 1];
            out += to_string(count);
            count = 1;
        }
        if (out.length() >= len)
            return str;
    }

    out += str[len - 1];
    out += to_string(count);
    if (out.length() >= len)
        return str;

    return out;
}

int main()
{
    string str = "ssaauurrrraaaabbbbbb";
    cout << compress(str);

    return 0;
}
