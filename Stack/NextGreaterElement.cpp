#include <bits/stdc++.h>

using namespace std;

/*
Input:
3
4
4 5 2 25
3
2 2 2
4
4 4 5 5

Output:
5 25 25 -1
-1 -1 -1
5 5 -1 -1
*/

void handle(int a[], int n)
{
    int R[n];
    stack<int> st;
    for (int i = n - 1; i >= 0; --i)
    {
        while (!st.empty() && st.top() <= a[i]) st.pop();
        if (st.empty()) R[i] = -1;
        else R[i] = st.top();
        st.push(a[i]);
    }
    for (int i = 0; i < n; ++i) cout << R[i] << ' ';
    cout << '\n';
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; ++i) cin >> a[i];

        handle(a, n);
    }
    return 0;
}