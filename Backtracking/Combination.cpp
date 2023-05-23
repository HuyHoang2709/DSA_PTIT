#include <bits/stdc++.h>

using namespace std;

int n, k;
int C[30];

void print()
{
    for (int i = 0; i <= k; ++i) cout << C[i] << ' ';
    cout << '\n';
}

void Try(int i)
{
    for (int j = C[i - 1] + 1; j <= n - k + i; ++j)
    {
        C[i] = j;
        if (i == k) print();
        else Try(i + 1);
    }
}

int main()
{
    cin >> n >> k;
    Try(1);
    return 0;
}