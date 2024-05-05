#include <bits/stdc++.h>
using namespace std;

bool isValid(string word)
{
    if (word.length() < 3)
        return false;

    int vowel = 0, consonent = 0;
    for (auto &&i : word)
    {
        int c = i;
        if (c >= 48 && c <= 57)
        {
            continue;
        }
        if (c >= 97 && c <= 122)
        {
            if (i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u')
                vowel++;
            else
                consonent++;
            continue;
        }
        if (c >= 65 && c <= 90)
        {
            if (i == 'A' || i == 'E' || i == 'I' || i == 'O' || i == 'U')
                vowel++;
            else
                consonent++;
            continue;
        }
        return false;
    }
    if (vowel && consonent)
        return true;
    else
        return false;
}

int main()
{
    int ch = 'A';
    cout << ch << endl;
    return 0;
}