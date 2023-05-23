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

void SelectionSort()
{
    for(int i = 0; i < n-1; ++i)
    {
        int min = i;
        for(int j = i+1; j < n; ++j)
        {
            if(a[min] > a[j]) min = j;
        }
        swap(a[i], a[min]);
    }
}

void print()
{
    for(int i = 0; i < n; ++i) cout << a[i] << ' ';
}

int main()
{
    Init();
    SelectionSort();
    print();
    return 0;
}