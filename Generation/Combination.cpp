#include <bits/stdc++.h>

using namespace std;

int C[35];
int n, k;
int OK;

void Init()
{
    OK = 0;
    cin >> n >> k;
    for (int i = 1; i <= k; ++i) C[i] = i;
}

void Generate()
{
    int i = k;
    while (C[i] == n - k + i) --i;
    if (i == 0) OK = 1;
    else
    {
        ++C[i];
        for (int j = i + 1; j <= k; ++j) C[j] = C[j - 1] + 1;
    }
}

void print()
{
    for (int i = 1; i <= k; ++i) cout << C[i] << ' ';
    cout << '\n';
}

int main()
{
    Init();
    while (!OK)
    {
        print();
        Generate();
    }
    return 0;
}