#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isEqual(string &word, string &copy)
{
    for (int i = 0; i < word.length(); i++)
    {
        if (copy[i] != '*' && copy[i] != word[i])
            return false;
    }
    return true;
}

int minimumTimeToInitialState(string word, int k)
{
    string copy = word;
    int cnt = 0;
    do
    {
        copy = copy.substr(k) + string(k, '*');
        cnt++;
    } while (!isEqual(word, copy));
    return cnt;
}

int main()
{
    return 0;
}