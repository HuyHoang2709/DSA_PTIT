#include <bits/stdc++.h>

using namespace std;

// Input:
// x  : 5
// n  : 11
// a[]: 28 75 58 43 89 6 92 29 9 21 5

int n, x;
int a[100];

void Init()
{
    cin >> n >> x;
    for(int i = 0; i < n; ++i) cin >> a[i];
}

void LinearSearch()
{
    int pos = -1;
    for(int i = 0; i < n; ++i)
    {
        if(a[i] == x) 
        {
            pos = i;
            break;
        }
    }
    cout << pos;
}

int main()
{
    Init();
    LinearSearch();
    return 0;
}