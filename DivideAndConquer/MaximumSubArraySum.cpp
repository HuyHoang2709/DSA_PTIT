#include <bits/stdc++.h>

using namespace std;

/*
Input:
8
-2 -3 4 -1 -2 1 5 -3

Output:
7
*/

int n;
int a[100];

void Init()
{
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
}

int maxCrossingSum(int l, int m, int h) {
    int sum = 0;
    int leftSum = INT_MIN;
    int rightSum = INT_MIN;
    for (int i = m; i >= l; i--) {
        sum = sum + a[i];
        if (sum > leftSum) leftSum = sum;
    }
    sum = 0;
    for (int i = m + 1; i <= h; i++) {
        sum = sum + a[i];
        if (sum > rightSum) rightSum = sum;
    }
    return leftSum + rightSum;
}
int maxSubArraySum(int l, int h) {
    if (l == h)	return a[l];
    int m = (l + h) / 2;
    return max(maxSubArraySum(l, m),
           max(maxSubArraySum(m + 1, h),
               maxCrossingSum(l, m, h)));
}

int main()
{
    Init();
    cout << maxSubArraySum(0, n - 1);
    return 0;
}