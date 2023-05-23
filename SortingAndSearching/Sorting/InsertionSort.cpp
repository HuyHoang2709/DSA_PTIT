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

void InsertionSort()
{
    for(int i = 1; i < n; ++i)
    {
        int key = a[i];
        int j = i-1;
        while(j >= 0 && a[j] > key)
        {
            a[j+1] = a[j];
            --j;
        }
        a[j+1] = key;
    }
}

void print()
{
    for(int i = 0; i < n; ++i) cout << a[i] << ' ';
}

int main()
{
    Init();
    InsertionSort();
    print();
    return 0;
}