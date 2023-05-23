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
    for (int i = 0; i < n; ++i) cin >> a[i];
}

void BinarySearch()
{
    sort(a, a + n);
    int pos = -1;
    int l = 0;
    int r = n - 1;
    
    while(l <= r)
    {
        int mid = (l + r) / 2;
        if(a[mid] == x) 
        {
            pos = mid;
            break;
        } 
        else if(a[mid] > x) --r;
        else ++l;
    }
    cout << pos;
}

int main()
{
    Init();
    BinarySearch();
    return 0;
}