#include <bits/stdc++.h>
using namespace std;

// oneEditReplace -> check if a character is replaced
bool oneEditReplace(string first, string second)
{
    bool foundDifference = false;
    for (int i = 0; i < first.length(); i++)
    {
        if (first[i] != second[i])
        {
            if (foundDifference)
            {
                return false;
            }
            foundDifference = true;
        }
    }
    return foundDifference;
}

// oneEditInsert -> check if a character is edited
bool oneEditInsert(string first, string second)
{
    int index1 = 0, index2 = 0;
    while (index2 < second.length() && index1 < first.length())
    {
        if (first[index1] != second[index2])
        {
            if (index1 != index2)
            {
                return false;
            }
            index2++;
        }
        else
        {
            index1++;
            index2++;
        }
    }
    return true;
}

// oneEditAway -> calls the above function according to the length of the final string
bool oneEditAway(string first, string second)
{
    if (first.length() == second.length())
    {
        return oneEditReplace(first, second);
    }
    else if (first.length() + 1 == second.length())
    {
        return oneEditInsert(first, second);
    }
    else if (first.length() - 1 == second.length())
    {
        return oneEditInsert(second, first);
    }
    return false;
}

// since oneEditReplace and oneEditInsert are very similar , we can merge them into one method

bool oneEditAway2(string first, string second)
{
    if ((abs(static_cast<long>(first.length())) - abs(static_cast<long>(second.length()))) > 1)
    {
        return false;
    }
    string s1 = first.length() < second.length() ? first : second;
    string s2 = first.length() < second.length() ? second : first;

    bool foundDifference = false;
    int index1 = 0, index2 = 0;

    while (index2 < s2.length() && index1 < s1.length())
    {
        if (s1[index1] != s2[index2])
        {
            // first difference found
            if (foundDifference)
                return false;
            foundDifference = true;
            if (s1.length() == s2.length())
            {
                index1++;
            }
        }
        else
        {
            index1++;
        }
        index2++;
    }
    return true;
}

int main()
{
    string first = "pale";
    string second = "padle";
    cout << oneEditAway2(first, second);
}