#include <bits/stdc++.h>

using namespace std;

// Input:
// n  : 11
// a[]: 28 75 58 43 89 6 92 29 9 21 5

int n;
int a[100];

void Init()
{
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> a[i];
}

void BubbleSort()
{
    for(int i = 0; i < n-1; ++i)
    {
        for(int j = 0; j < n-i-1; ++j)
        {
            if(a[j] > a[j+1]) swap(a[j], a[j+1]);
        }
    }
}

void print()
{
    for(int i = 0; i < n; ++i) cout << a[i] << ' ';
}

int main()
{
    Init();
    BubbleSort();
    print();
    return 0;
}