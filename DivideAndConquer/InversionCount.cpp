#include <bits/stdc++.h>

using namespace std;

long long Merge(long long a[], int l, int m, int r)
{
    int i, j, k, n1 = m - l + 1, n2 = r - m;
    long long L[n1], R[n2];
    for (i = 0; i < n1; ++i) L[i] = a[l + i];
    for (i = 0; i < n2; ++i) R[i] = a[m + i + 1];

    long long kq = 0;
    i = j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j]) a[k++] = L[i++];
        else
        {
            kq = kq + n1 - i;
            a[k++] = R[j++];
        }
    }
    while (i < n1) a[k++] = L[i++];
    while (j < n2) a[k++] = R[j++];
    return kq;
}

long long InversionCount(long long a[], int l, int r)
{
    long long kq = 0;
    if (l < r)
    {
        int m = (l + r) / 2;
        kq = kq + InversionCount(a, l, m);
        kq = kq + InversionCount(a, m + 1, r);
        kq = kq + Merge(a, l, m, r);
    }
    return kq;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        long long a[n];
        for (int i = 0; i < n; ++i) cin >> a[i];
        cout << InversionCount(a, 0, n - 1) << '\n';
    }
    return 0;
}