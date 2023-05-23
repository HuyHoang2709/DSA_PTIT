#include <bits/stdc++.h>

using namespace std;

int P[35];
int n;
int OK;

void Init()
{
    OK = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) P[i] = i;
}

void Generate()
{
    int i = n - 1;
    while (P[i] > P[i + 1]) --i;
    if (i == 0) OK = 1;
    else
    {
        int j = n;
        while (P[i] > P[j]) --j;
        swap(P[i], P[j]);

        int l = i + 1, r = n;
        while (l < r)
        {
            swap(P[l], P[r]);
            ++l, --r;
        }
    }
}

void print()
{
    for (int i = 1; i <= n; ++i) cout << P[i] << ' ';
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