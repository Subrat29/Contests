#include <bits/stdc++.h>
using namespace std;

// sc: n
// tc: n

string compressedString(string word)
{
    string ans = "";
    int cnt = 1; // Initialize count as 1 since we count the first occurrence

    for (int i = 0; i < word.size(); i++)
    {
        // Check if the current character is the same as the next character
        if (cnt < 9 && i < word.size() - 1 && word[i] == word[i + 1])
        {
            cnt++;
        }
        else
        {
            // Append the count and character to the result
            ans += to_string(cnt) + word[i];
            cnt = 1; // Reset count for the next character
        }
    }
    return ans;
}

int main()
{
    return 0;
}