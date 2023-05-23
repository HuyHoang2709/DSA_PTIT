#include <bits/stdc++.h>

using namespace std;

// This code uses last element as pivot

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

int Partition(int low, int high)
{
    int pivot = a[high];
    int i = low - 1;
    for (int j = low; j < high; ++j)
    {
        if (a[j] <= pivot)
        {
            ++i;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[high]);
    return i + 1;
}

void QuickSort(int low, int high)
{
    if (low < high)
    {
        int p = Partition(low, high);
        QuickSort(low, p - 1);
        QuickSort(p + 1, high);
    }
}

void print()
{
    for(int i = 0; i < n; ++i) cout << a[i] << ' ';
    cout << '\n';
}

int main()
{
    Init();
    QuickSort(0, n-1);
    print();
    return 0;
}