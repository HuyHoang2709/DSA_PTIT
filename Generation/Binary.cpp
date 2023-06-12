#include <bits/stdc++.h>

using namespace std;

int B[35];
int n;
int OK;

void Init()
{
    OK = 0;
    cin >> n;
    for (int i = 0; i <= n; ++i) B[i] = 0;
}

void Generate()
{
    int i = n;
    while (B[i] == 1 && i > 0)
    {
        B[i] = 0;
        --i;
    }
    if (i == 0) OK = 1;
    else B[i] = 1;
}

void print()
{
    for (int i = 1; i <= n; ++i) cout << B[i] << ' ';
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