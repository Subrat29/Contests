#include <bits/stdc++.h>
using namespace std;

using ll = signed long long int;

void solve()
{
    int n;
    cin >> n;

    int teamA_attack[n];
    for (int i = 0; i < n; i++)
        cin >> teamA_attack[i];
    int teamA_defense[n];
    for (int i = 0; i < n; i++)
        cin >> teamA_defense[i];

    int teamB_attack[n];
    for (int i = 0; i < n; i++)
        cin >> teamB_attack[i];
    int teamB_defense[n];
    for (int i = 0; i < n; i++)
        cin >> teamB_defense[i];

    int totalAttack1 = 0, totalDefense1 = 0;
    int totalAttack2 = 0, totalDefense2 = 0;
    for (int i = 0; i < n; i++)
    {
        totalAttack1 += teamA_attack[i];
        totalDefense1 += teamA_defense[i];
        totalAttack2 += teamB_attack[i];
        totalDefense2 += teamB_defense[i];
    }

    cout << totalAttack1 << endl;
    cout << totalDefense1 << endl;
    cout << totalAttack2 << endl;
    cout << totalDefense2 << endl;

    if (totalAttack1 > totalAttack2 && totalDefense1 > totalDefense2)
        cout << "A" << endl;
    else if (totalAttack2 > totalAttack1 && totalDefense2 > totalDefense1)
        cout << "P" << endl;
    else
        cout << "DRAW" << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}