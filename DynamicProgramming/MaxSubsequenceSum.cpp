#include <bits/stdc++.h>

using namespace std;

/*
Input:
9
−2 1 −3 4 −1 2 1 −5 4

Output:
6

Explain output:
6 = 4 + (-1) + 2 + 1
*/

int dp(int a[], int n)
{
    int currentSum = 0;
    int maxSum = 0;
    for(int i = 0; i < n; ++i)
    {
        currentSum = max(0, currentSum + a[i]);
        maxSum = max(maxSum, currentSum);
    }
    return maxSum;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; ++i) cin >> a[i];
    cout << dp(a, n);
    return 0;
}