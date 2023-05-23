#include <bits/stdc++.h>

using namespace std;

int x;
int n = 6;
int ans[6];
int coins[6] = { 1, 2, 5, 10, 20 ,50 };

void Greedy(int value, int n)
{
    for (int i = n - 1; i >= 0; --i)
    {
        ans[i] = 0;
        while (coins[i] <= value)
        {
            value -= coins[i];
            ++ans[i];
        }
    }
}

int main()
{
    cin >> x;
    Greedy(x, n);
    cout << x << ": ";
    for (int i = 0; i < n; ++i)
    {
        if (ans[i] > 0) cout << ans[i] << '*' << coins[i] << ' ';
    }
    return 0;
}