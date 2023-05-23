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

void Merge(int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1, n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; ++i) L[i] = a[l + i];
    for (j = 0; j < n2; ++j) R[j] = a[m + 1 + j];

    i = 0; j = 0; k = l;
    
    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j])
        {
            a[k] = L[i];
            ++i;
        }
        else
        {
            a[k] = R[j];
            ++j;
        }
        ++k;
    }
    // Đề phòng trường họp chưa ghép hết các phần tử còn lại vào mảng
    while(i < n1)
    {
        a[k] = L[i];
        ++i; ++k;
    }
    while(j < n2)
    {
        a[k] = R[j];
        ++j; ++k;
    }
}

void MergeSort(int l, int r)
{
    if (l < r)
    {
        int m = (l + r - 1) / 2;
        MergeSort(l, m);
        MergeSort(m + 1, r);
        Merge(l, m, r);
    }
}

void print()
{
    for (int i = 0; i < n; ++i) cout << a[i] << ' ';
}

int main()
{
    Init();
    MergeSort(0, n - 1);
    print();
    return 0;
}