#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// int minimumTimeToInitialState(string word, int k)
// {
//     bool flag = true;
//     for (int i = 0; i < word.length() - 1; i++)
//     {
//         if (word[i] != word[i + 1])
//         {
//             flag = false;
//             break;
//         }
//     }

//     if (flag)
//         return 1;

//     return word.length() / k;
// }

int minimumTimeToInitialState(string word, int k)
{

    for (int i = k; i < word.length(); i += k)
    {
        bool flag = 1;

        for (int j = i, tmp = 0; j < word.length(); j++, tmp++)
        {
            if (word[j] != word[tmp])
            {
                flag = 0;
            }
        }

        if (flag)
            return i / k;
    }

    return (word.length() + k - 1) / k;
}

int main()
{
    return 0;
}