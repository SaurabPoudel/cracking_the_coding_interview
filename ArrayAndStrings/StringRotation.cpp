#include <bits/stdc++.h>
using namespace std;

bool isRotation(string s1, string s2)
{
    int len = s1.length();
    if (len != s2.length() && len == 0)
    {
        return false;
    }
    string s1s1 = s1 + s1;
    if (s1s1.find(s2) != string::npos)
    {
        return true;
    }
    else
    {
        return false;
    }
    return false;
}
int main()
{
    string s1 = "waterbottle";
    string s2 = "erbottlewat";

    if (isRotation(s1, s2))
    {
        cout << "One string is rotation of other";
    }
    else
    {
        cout << "One string is not rotation of other";
    }
}