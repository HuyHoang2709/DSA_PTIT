#include <bits/stdc++.h>

using namespace std;

/*
Input:
abcbadd

Output:
5
*/

int dp(string s)
{
    int n = s.size();
    bool f[n + 1][n + 1];
    int ans = -1e9;
    memset(f, false, sizeof(f));

    for (int i = n - 1; i >= 0; --i)
    {
        for (int j = i; j <= n - 1; ++j)
        {
            if (i == j) f[i][j] = true;
            else if (s[i] == s[j])
            {
                if (i == j - 1) f[i][j] = true;
                else f[i][j] = f[i + 1][j - 1];
            }
            if (f[i][j]) ans = max(ans, j - i + 1);
        }
    }
    return ans;
}

int main()
{
    string s;
    cin >> s;
    cout << dp(s);
    return 0;
}