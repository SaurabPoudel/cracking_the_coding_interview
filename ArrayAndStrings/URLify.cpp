#include <bits/stdc++.h>

using namespace std;

void URLify(string &s, int trueLength)
{
    int spaceCount = 0;
    for (int i = 0; i < trueLength; ++i)
    {
        if (s[i] == ' ')
        {
            ++spaceCount;
        }
    }

    int newIndex = trueLength - 1 + spaceCount * 2;
    for (int i = trueLength - 1; i >= 0; --i)
    {
        if (s[i] == ' ')
        {
            s[newIndex] = '0';
            s[newIndex - 1] = '2';
            s[newIndex - 2] = '%';
            newIndex -= 3;
        }
        else
        {
            s[newIndex] = s[i];
            --newIndex;
        }
    }
}
int main()
{
    string s = "Brady Pit Thriller    ";
    int trueLength = 18;
    URLify(s, trueLength);
    cout << s << endl;
    return 0;
}